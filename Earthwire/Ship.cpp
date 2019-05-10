#include "Ship.h"
// Information for datastructures of the classes located in header-file

/*
* =====================
* S H I P
* =====================
*/

Ship::Ship(int x, int y)
{ // Set Start Coordinates
    this->x = x;
    this->y = y;
}

Ship::Ship(){}
Ship::~Ship(){}

/*
* =====================
* P L A Y E R - S H I P
* =====================
*/

Player::Player(int x, int y, char c)
{
    this->x = x;
    this->y = y;
    this->name = name;
    this->life = 100;
    this->sizeX = 7; // width of playerSprite
    this->sizeY = 9; // height of playerSprite
    this->speed = 1;
    this->ammunation = 15;
    this->score = 0;
}

Player::~Player()
{

}

bool Player::Move(char dir)
{
    switch (dir)
    {
    case 'w':
        if (this->x > 0)
        {
            this->x -= (int)this->speed;
            return true;
        }
        break;
    case 'e':
        if (this->x + this->sizeX < gb.display.width())
        {
            this->x += (int)this->speed;
            return true;
        }
        break;
    case 'n':
        if (this->y > 0)
        {
            this->y -= (int)this->speed;
            return true;
        }
        break;
    case 's':
        if (this->y + this->sizeY < gb.display.height())
        {
            this->y += (int)this->speed;
            return true;
        }
        break;
    default:
        return false;
        break;
    }
}

void Player::Draw()
{
    Image playerSprite(playerSpriteData);
    gb.display.drawImage(this->x, this->y, playerSprite);
}

Projectile* Player::Shoot()
{
  return new Projectile(this->x + (this->sizeX / 2), this->y + (this->sizeY / 2), 3);
}

void Player::CheckProjColl(Projectile* ProjArr[], int maxProj)
{
  // Check for Collisions with Projectiles
  for (int i = 0; i < maxProj; i++)
  {
    int projX = ProjArr[i]->x;
    int projY = ProjArr[i]->y;
    if (projX < (this->x + this->sizeX) && projX > this->x && projY < (this->y + this->sizeY) && projY > this->y)
    { // Plane hit!
      this->life -= ProjArr[i]->damage;
      delete ProjArr[i];
      ProjArr[i] = nullptr;
    }
  }
}

/*
* =====================
* E N E M Y - S H I P
* =====================
*/

Enemy::Enemy(int shootingRate)
{
    this->shootingRate = shootingRate;
    // Enemy needs no parameters for coords, cause of random generation
    randomSeed(analogRead(0));  // init Random Seed
    this->sizeX = 12; // width of playerSprite
    this->sizeY = 15; // height of playerSprite
    this->speed = 1;

    // set coords based on sprite-size
    this->x = gb.display.width(); // spawns outside of the screen
    this->y = random(gb.display.height() - this->sizeY);

    this->life = 100;
}

Enemy::~Enemy(){}

Projectile* Enemy::Shoot()
{
  int shooting = random(this->shootingRate);
  if (shooting == 0)
  { // e.g. shootingRate = 5 -> 1/5 Chance per Frame the enemy is actually shooting
    return new Projectile(this->x + (this->sizeX / 2), this->y + (this->sizeY / 2), -2);
  } else
  {
    return nullptr;
  }
}

void Enemy::Draw()
{
    Image enemySprite(enemySpriteData);
    gb.display.drawImage(this->x, this->y, enemySprite);
}

void Enemy::CheckProjColl(Projectile* ProjArr[], int maxProj)
{
  for (int i = 0; i < maxProj; i++)
  {
    int projX = ProjArr[i]->x;
    int projY = ProjArr[i]->y;
    if (projX < (this->x + this->sizeX) && projX > this->x && projY < (this->y + this->sizeY) && projY > this->y)
    { // Plane hit!
      this->life -= ProjArr[i]->damage;
      delete ProjArr[i];
      ProjArr[i] = nullptr;
    }
  }
}

bool Enemy::Move()
{
  this->x -= this->speed;
  if ((this->x + this->sizeX) < 0)
  { // left screen on the left side
    return false;
  } else
  {
    return true;
  }
}
