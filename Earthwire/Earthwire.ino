#include <Gamebuino-Meta.h>
#include "Ship.h"
#include "Explosion.h"

/*
* =====================
* V A R I A B L E S - S E T U P
* =====================
*/

Player *p1 = new Player(8, 9, 'a');

//the purpose of this arrays is to limit the stuff that gets drawn on screen
// current values are for testing
const int maxProj = 10;
const int maxEnem = 2;
const int maxEnemProj = 5;
const int maxExplosions = maxEnem + 1;

int curEnem = 0;     // current number of enemies on screen
int curEnemProj = 0; // current number of enemie projectiles

Projectile *ProjArr[maxProj] = {nullptr};         // Array of Player Projectiles
Projectile *EnemProjArr[maxEnemProj] = {nullptr}; // Array of Enemy Projectiles
Enemy *EnemyArr[maxEnem] = {nullptr};             // Array of Enemies
Explosion *ExplosionsArr[maxExplosions] = {nullptr};

// Array Indexes for going through the arrays
int projIndex = 0;
int deleted = 0; //used to only clean up everything once, probably really bad practice


enum GameState {inGame, gameOver};
int gameState = inGame; //used to differentiate between game and game end (potentially high score screen); maybe use enum in future?


bool NoExplosionsLeft (Explosion** ExplosionsArr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (ExplosionsArr[i] != nullptr)
            return false;
    }

    return true;
}

/*
* =====================
* G A M E B U I N O - S E T U P
* =====================
*/

void setup()
{
    gb.begin();
}

/*
* =====================
* G A M E - L O O P
* =====================
*/

void loop()
{
    while (!gb.update());
    if (gameState == inGame)
    {

        /* ------------------------
     * CALCULATION AND SPAWNING
     */

        // Movement Input
        if (gb.buttons.repeat(BUTTON_UP, 1))
            p1->Move('n');

        if (gb.buttons.repeat(BUTTON_DOWN, 1))
            p1->Move('s');

        if (gb.buttons.repeat(BUTTON_LEFT, 1))
            p1->Move('w');

        if (gb.buttons.repeat(BUTTON_RIGHT, 1))
            p1->Move('e');

        // Player's Ability to shoot (!Testing!)
        if (gb.buttons.pressed(BUTTON_A))
        {
            if (ProjArr[projIndex] != nullptr)
            {
                delete ProjArr[projIndex];
                ProjArr[projIndex] = nullptr;
            }
            ProjArr[projIndex] = p1->Shoot();
            projIndex++;
            if (projIndex >= maxProj)
            {
                projIndex = 0;
            }
        }

        // Spawn new Enemy based on the max count of Enemies onscreen
        for (int j = 0; j < maxEnem; j++)
        {
            if (curEnem < maxEnem && EnemyArr[j] == nullptr)
            {
                EnemyArr[j] = new Enemy(100); // creating Enemy with shootingRate of 50 (testing!)
                curEnem++;
            }
        }

        // Evaluate which Enemies will shoot next based on the max count of Projectiles onscreen
        for (int j = 0; j < maxEnem; j++)
        { // goes through Enemies
            if (EnemyArr[j] != nullptr && curEnemProj < maxEnemProj && EnemyArr[j]->life > 0)
            { // Enemy Object found, Enemy is allowed to shoot
                for (int i = 0; i < maxEnemProj; i++)
                { // goes through Projectiles
                    if (EnemProjArr[i] == nullptr)
                    { // it can be shooten
                        EnemProjArr[i] = EnemyArr[j]->Shoot();
                        // Shoot returns Projetile Pointer or nullptr based on its shooting rate
                    }
                }
            }
        }

        // Check for Collisions & Lifepoints of PLAYER
        p1->CheckProjColl(EnemProjArr, maxEnemProj);

        if (p1->life <= 0)
        {
            if (!p1->isDestroyed)
            {
                p1->Explode(ExplosionsArr, maxExplosions);
            } else if (NoExplosionsLeft(ExplosionsArr, maxExplosions))
            {
                gameState = gameOver;
            }
        }

        // Check for Collision & Lifepoints of Enemies
        for (int i = 0; i < maxEnem; i++)
        {
            if (EnemyArr[i] != nullptr)
            {
                if (EnemyArr[i]->life > 0 && !EnemyArr[i]->isOOB())
                {
                    EnemyArr[i]->Move();
                    EnemyArr[i]->CheckProjColl(ProjArr, maxProj);
                    EnemyArr[i]->CheckPlaneColl(p1);
                } else
                {
                    if (EnemyArr[i]->life <= 0)
                    {
                        EnemyArr[i]->Explode(ExplosionsArr, maxExplosions);
                    }

                    delete EnemyArr[i];
                    EnemyArr[i] = nullptr;
                    curEnem--;
                }
            }
        }

        // Deletes OOB Projectiles of Player
        for (int i = 0; i < maxProj; i++)
        {
            if (ProjArr[i] != nullptr)
            {
                if (ProjArr[i]->isOOB())
                {
                    delete ProjArr[i];
                    ProjArr[i] = nullptr;
                } else
                {
                    ProjArr[i]->Move();
                }
            }
        }

        // Go through Enemy Projectiles and moves or deletes them if they are OOB
        for (int i = 0; i < maxEnemProj; i++)
        {
            if (EnemProjArr[i] != nullptr)
            {
                if (EnemProjArr[i]->isOOB())
                {
                    delete EnemProjArr[i];
                    EnemProjArr[i] = nullptr;
                } else
                {
                    EnemProjArr[i]->Move();
                }
            }
        }

        // clear the previous screen
        gb.display.clear();

        /* -------------------------
         * DRAWING UI
         */

        // HULL
        Image hullSprite(hullSpriteData);
        gb.display.drawImage(0, 0, hullSprite);
        gb.display.setColor(YELLOW);
        int hullBarWidth = p1->life / 5;
        gb.display.fillRect(7, 0, hullBarWidth, 5);

        // AMMUNATION
        Image ammuSprite(ammuSpriteData);
        gb.display.drawImage(30, 0, ammuSprite);
        gb.display.setColor(RED);
        int ammuBarWidth = p1->ammunation;
        gb.display.fillRect(35, 0, ammuBarWidth, 5);

        // SCORE
        gb.display.setColor(WHITE);
        gb.display.setCursor(60, 0);
        gb.display.print(p1->score);

         //debug RAM print
         uint16_t ram = gb.getFreeRam();
         gb.display.print("RAM:");
         gb.display.println(ram);

        /* -------------------------
          * DRAWING ALL SPRITES
          */

        // Player Projectiles
        for (int j = 0; j < maxProj; j++)
        {
            if (ProjArr[j] != nullptr && !ProjArr[j]->isOOB())
            {
                ProjArr[j]->Draw();
            }
        }

        // Enemy Projectiles
        for (int j = 0; j < maxEnemProj; j++)
        {
            if (EnemProjArr[j] != nullptr && !EnemProjArr[j]->isOOB())
            {
                EnemProjArr[j]->Draw();
            }
        }

        // Draw Enemies Plane
        for (int j = 0; j < maxEnem; j++)
        {
            if (EnemyArr[j] != nullptr && !EnemyArr[j]->isOOB() && EnemyArr[j]->life > 0)
            {
                EnemyArr[j]->DrawPlane();
            }
        }

        // Draw Player Plane
        if (p1->life > 0)
        {
            p1->DrawPlane();
        }

        // Draw Explosions
        for (int i = 0; i < maxEnem + 1; i++)
        {
            if (ExplosionsArr[i] != nullptr && ExplosionsArr[i]->explodeTime > 0)
            {
                ExplosionsArr[i]->explodeTimer += 1;
                ExplosionsArr[i]->DrawExplosion();
            } else if (ExplosionsArr[i] != nullptr && ExplosionsArr[i]->explodeTime <= 0)
            {
                delete ExplosionsArr[i];
                ExplosionsArr[i] = nullptr;
            }
        }

    }

    else if (gameState = gameOver)
    {
        gb.display.clear();
        gb.sound.fx(mySfx);
        gb.display.print("PRESS A TO RESTART YOU NOOB");
        if (!deleted)
        {
            for (int i = 0; i < curEnem; i++)
            {
                if (EnemyArr[i] != nullptr)
                {
                    delete EnemyArr[i];
                    EnemyArr[i] = nullptr;
                }
            }

            for (int i = 0; i < maxProj; i++)
            {
                if (ProjArr[i] != nullptr)
                {
                    delete ProjArr[i];
                    ProjArr[i] = nullptr;
                }
            }

            for (int i = 0; i < curEnemProj; i++)
            {
                if (EnemProjArr[i] != nullptr)
                {
                    delete EnemProjArr[i];
                    EnemProjArr[i] = nullptr;
                }
            }
            projIndex = 0;
            curEnem = 0;
            curEnemProj = 0;
            deleted = 1;
        }
        if (gb.buttons.pressed(BUTTON_A))
        {
            delete p1;
            p1 = new Player(10, 10, 'a');
            gameState = inGame;
        }
    }
}
