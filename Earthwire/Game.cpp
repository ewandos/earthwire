#include "Game.h"

Game::Game()
{
    randomSeed(analogRead(0));
    this->p1 = new Player(8, 9, 'a');

    this->curEnem = 0;
    this->curEnemProj = 0;
    this->projIndex = 0;
    this->enemySpawnTimer = 0;
    this->rank = MAX_HIGHSCORES+1;

    for(int i=0;i<MAX_HIGHSCORES;i++)   // load highscore
    {
      this->highscore[i] = 0;
      this->highscore[i] = gb.save.get(i);
    }
}

Game::~Game()
{
    delete p1;

    for (int i = 0; i < MAX_PLAYER_PROJECTILES; i++)
        delete ProjArr[i];

    for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
        delete EnemProjArr[i];

    for (int i = 0; i < MAX_ENEMIES_SPAWN; i++)
        delete EnemyArr[i];

    for (int i = 0; i < MAX_EXPLOSIONS; i++)
        delete ExplosionsArr[i];
}

void Game::PlayerShoots()
{
    if (ProjArr[projIndex] != nullptr)
    {
        delete ProjArr[projIndex];
        ProjArr[projIndex] = nullptr;
    }
    ProjArr[projIndex] = p1->Shoot();
    projIndex++;
    if (projIndex >= MAX_PLAYER_PROJECTILES)
    {
        projIndex = 0;
    }
}

void Game::SpawnEnemies()
{
    // creating Slots that are sized half the height of enemies prite-height
    // when enemy is created, the slot is reserved (bool array)
    // if enemy is deleted slot is free

    // slots array is the enemyArr BUT the spawning should be handled differently
    int randomSlot = random(MAX_ENEMIES_SPAWN);

    if (curEnem < MAX_ENEMIES_ON_SCREEN && EnemyArr[randomSlot] == nullptr)
    {
        if (enemySpawnTimer >= ENEMY_SPAWN_RATE)
        {
          EnemyArr[randomSlot] = new Enemy(8 * randomSlot, ENEMY_DIFFICULTY); // creating Enemy with shootingRate of 50 (testing!)
          curEnem++;
          enemySpawnTimer = 0;
        } else
        {
          enemySpawnTimer++;
        }
    }
}

void Game::LetEnemiesShoot()
{
    // Evaluate which Enemies will shoot next based on the max count of Projectiles onscreen
    for (int j = 0; j < MAX_ENEMIES_SPAWN; j++)
    { // goes through Enemies
        if (EnemyArr[j] != nullptr && curEnemProj < MAX_ENEMY_PROJECTILES && EnemyArr[j]->life > 0)
        { // Enemy Object found, Enemy is allowed to shoot
            for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
            { // goes through Projectiles
                if (EnemProjArr[i] == nullptr)
                { // it can be shooten
                    EnemProjArr[i] = EnemyArr[j]->Shoot();
                    // Shoot returns Projetile Pointer or nullptr based on its shooting rate
                }
            }
        }
    }
}

bool Game::CheckPlayerStatus()
{
    // Check for Collisions & Lifepoints of PLAYER
    p1->CheckProjColl(EnemProjArr, MAX_ENEMY_PROJECTILES);

    if (p1->life <= 0)
    {
        if (!p1->isDestroyed)
        {
            p1->Explode(ExplosionsArr, MAX_EXPLOSIONS);
        } else if (NoExplosionsLeft(ExplosionsArr, MAX_EXPLOSIONS))
        {
            return false;
        }
    }
    return true;
}

void Game::CheckEnemiesStatus()
{
    // Check for Collision & Lifepoints of Enemies
    for (int i = 0; i < MAX_ENEMIES_SPAWN; i++)
    {
        if (EnemyArr[i] != nullptr)
        {
            if (EnemyArr[i]->life > 0 && !EnemyArr[i]->isOOB())
            {   // Is Alive & On Screen
                EnemyArr[i]->Move();
                EnemyArr[i]->CheckProjColl(ProjArr, MAX_PLAYER_PROJECTILES);
                EnemyArr[i]->CheckPlaneColl(p1);
            } else
            {
                if (EnemyArr[i]->life <= 0)
                {   // killed Enemy
                    p1->score += POINTS_PER_KILLED_ENEMY;
                    EnemyArr[i]->Explode(ExplosionsArr, MAX_EXPLOSIONS);
                }

                if (EnemyArr[i]->isOOB() && p1->score >= MINUS_POINTS_PER_MISSED_ENEMY)
                {   // Player missed to kill enemy
                    p1->score -= MINUS_POINTS_PER_MISSED_ENEMY;
                }

                delete EnemyArr[i];
                EnemyArr[i] = nullptr;
                curEnem--;
            }
        }
    }
}

bool Game::NoExplosionsLeft(Explosion** ExplosionsArr, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (ExplosionsArr[i] != nullptr)
            return false;
    }

    return true;
}

void Game::MoveProjectiles()
{
    // Deletes OOB Projectiles of Player
    for (int i = 0; i < MAX_PLAYER_PROJECTILES; i++)
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
    for (int i = 0; i < MAX_ENEMY_PROJECTILES; i++)
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
}

void Game::DrawProjectiles()
{
    // Player Projectiles
    for (int j = 0; j < MAX_PLAYER_PROJECTILES; j++)
    {
        if (ProjArr[j] != nullptr && !ProjArr[j]->isOOB())
        {
            ProjArr[j]->Draw();
        }
    }

    // Enemy Projectiles
    for (int j = 0; j < MAX_ENEMY_PROJECTILES; j++)
    {
        if (EnemProjArr[j] != nullptr && !EnemProjArr[j]->isOOB())
        {
            EnemProjArr[j]->Draw();
        }
    }
}

void Game::DrawEnemies()
{
    // Draw Enemies Plane
    for (int j = 0; j < MAX_ENEMIES_SPAWN; j++)
    {
        if (EnemyArr[j] != nullptr && !EnemyArr[j]->isOOB() && EnemyArr[j]->life > 0)
        {
            EnemyArr[j]->DrawPlane();
        }
    }
}

void Game::DrawPlayer()
{
    // Draw Player Plane
    if (this->p1->life > 0)
    {
        this->p1->DrawPlane();
    }
}

void Game::DrawExplosions()
{
    // Draw Explosions
    for (int i = 0; i < MAX_ENEMIES_SPAWN + 1; i++)
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

void Game::PlayerRecharges()
{
    if (!p1->recharging) // if the player presses B, the recharging logic gets started
        p1->recharging = true;
    p1->Recharge(); // basically just a setter for the ammo
    if (p1->ammunation >= 100) // if the ammo reaches 100, the recharging process gets terminated
        p1->recharging = false;


/*
    If this was to be done with a timer instead of being framerate-based, the logic would supposedly look something like this (absolutely untested, just mental gymnastics)
    if (!p1->recharging)
    {
        int timeFrame = 250; // how long it should take to charge
        p1->recharging = true;
        int timer = milis();
        int timerAux = 0;
        int timerEnd = millis() + timeFrame;
        int AmmoAux = 100 - this->ammunation; // get how much ammo is missing
        AmmoAux /= timeFrame; // how much ammo per ms (ammo is int?, might be problematic)        
    }
    timerAux = milis() - timer; // figure out how many ms have passed in the last frame
    for (int i = 0; i < (AmmoAux * timerAux); i++) // add as much ammo you need per ms times the ms that have passed
    {
        p1-Recharge(); // (Would need to check if the ammo is full in Recharge() for this, or find another way to terminate this)
    }

    timer = milis(); // capture frame time for the next frame


    if (p1->ammunation >= 100) // if the ammo reaches 100, the recharging process gets terminated
        p1->recharging = false;
*/
}

void Game::setHighscore()
{
  if (this->p1->score > this->highscore[MAX_HIGHSCORES-1])
  {
    for(int i=MAX_HIGHSCORES-1; i>=0; i--)
    {
      if(this->p1->score > this->highscore[i])
      {
        this->rank=i;
      }
    }
    for(int i=MAX_HIGHSCORES-1; i>this->rank; i--)
    {
          this->highscore[i] = this->highscore[i-1];
          gb.save.set(i,this->highscore[i]);
    }
    this->highscore[this->rank] = this->p1->score;
    gb.save.set(this->rank,this->highscore[this->rank]);
    this->p1->score = 0;
  }
}

void Game::printHighscore()
{
  gb.display.setCursor(20,7);
  gb.display.println("HIGHSCORE");
  gb.display.println();
  for(int i = 0; i < MAX_HIGHSCORES; i++)
  {
    if(i == this->rank)
    {
      gb.display.setColor(Color::red);
      gb.display.println(this->highscore[i]);
      gb.display.setColor(Color::white);
    }
    else
    {
      gb.display.println(this->highscore[i]);
    }
  }
}

