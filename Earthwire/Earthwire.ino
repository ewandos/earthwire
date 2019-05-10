#include <Gamebuino-Meta.h>
#include "Ship.h"

/*
* =====================
* V A R I A B L E S - S E T U P
* =====================
*/

Player *p1 = new Player(8, 9, 'a');

//the purpose of this arrays is to limit the stuff that gets drawn on screen
// current values are for testing
const int maxProj = 5;
const int maxEnem = 2;
const int maxEnemProj = 5;

int curEnem = 0;  // current number of enemies on screen
int curEnemProj = 0;  // current number of enemie projectiles

Projectile* ProjArr [maxProj] = {nullptr};  // Array of Player Projectiles
Projectile* EnemProjArr [maxEnemProj] = {nullptr};  // Array of Enemy Projectiles
Enemy* EnemyArr [maxEnem] = {nullptr};  // Array of Enemies

// Array Indexes for going through the arrays
int projIndex = 0;


/*
* =====================
* G A M E B U I N O - S E T U P
* =====================
*/

void setup() {
  gb.begin();
}

/*
* =====================
* G A M E - L O O P
* =====================
*/

void loop() {
  while (!gb.update());

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
    if ( projIndex >= maxProj )
    {
      projIndex = 0;
    }
  }

  // Spawn new Enemy based on the max count of Enemies onscreen
  for (int j = 0; j < maxEnem; j++)
  {
    if (curEnem < maxEnem && EnemyArr[j] == nullptr) {
      EnemyArr[j] = new Enemy (100); // creating Enemy with shootingRate of 50 (testing!)
      curEnem++;
    }
  }

  // Evaluate which Enemies will shoot next based on the max count of Projectiles onscreen
  for (int j = 0; j < maxEnem; j++)
  { // goes through Enemies
    if (EnemyArr[j] != nullptr && curEnemProj < maxEnemProj)
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

  if (p1->life < 1)
  {
    // Destroy Player
  }

  // Check for Collision & Lifepoints of Enemies
  for (int i = 0; i < maxEnem; i++)
  {
    EnemyArr[i]->CheckProjColl(ProjArr, maxProj);
    if (EnemyArr[i]->life <= 0)
    {
      // Destroy Enemy
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

   /*
   //debug RAM print
   uint16_t ram = gb.getFreeRam();
   gb.display.print("RAM:");
   gb.display.println(ram);
   */


   /* -------------------------
    * DRAWING ALL SPRITES
    */

   // Player Projectiles
  for (int j = 0; j < maxProj; j++)
  {
    if (ProjArr[j] != nullptr)
    {
      if(!ProjArr[j] -> Move())
      {
        delete ProjArr[j];
        ProjArr[j] = nullptr;
      }
      if(ProjArr[j] != nullptr)
        ProjArr[j] -> Draw();
    }
  }

 // Enemy Projectiles
 for (int j = 0; j < maxEnemProj; j++)
 {
   if (EnemProjArr[j] != nullptr)
   {
     if(!EnemProjArr[j] -> Move()) // Moves the Projectile and checks if it is offscreen
     {  // its  offscreen
       delete EnemProjArr[j];
       EnemProjArr[j] = nullptr;
     }
     if(EnemProjArr[j] != nullptr)
     { // Projectule drawn
       EnemProjArr[j] -> Draw();
     }
   }
 }

  // Draw Enemies Plane
  for (int j = 0; j < maxEnem; j++)
  {
    if (!EnemyArr[j]->Move())
    {
      delete EnemyArr[j];
      EnemyArr[j] = nullptr;
      curEnem--;
    }
    if (EnemyArr[j] != nullptr)
    {
      EnemyArr[j]->Draw();
    }
  }

  // Draw Player Plane
  p1->Draw();

}
