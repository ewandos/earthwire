#include "Ship.h"
#include "graphics.cpp"
#include "sounds.cpp"

// Information for datastructures of the classes located in header-file

/* 
 * ================
 * SHIP
 * ================
 */

Ship::Ship(int x, int y)
{ // Set Start Coordinates
    this->x = x;
    this->y = y;
}

Ship::Ship()
{
}

void Ship::Draw()
{
    Image playerSprite(playerSpriteData);
    gb.display.drawImage(this->x, this->y, playerSprite);
}

Ship::~Ship()
{
}

void Ship::Move(char dir)
{
    switch (dir)
    {
    case 'w':
        if (this->x > 0)
        {
            this->x--;
        }
        break;
    case 'e':
        if (this->x + this->sizeX < gb.display.width())
        {
            this->x++;
        }
        break;
    case 'n':
        if (this->y > 0)
        {
            this->y--;
        }
        break;
    case 's':
        if (this->y + this->sizeY < gb.display.height())
        {
            this->y++;
        }
        break;
    default:
        break;
    }
}

/* 
 * ================
 * PLAYER (Child Class of Ship)
 * ================
 */

Player::Player(int x, int y, char c)
{
    this->x = x;
    this->y = y;
    this->name = name;
    this->life = 100;
    this->sizeX = 7; // width of playerSprite
    this->sizeY = 9; // height of playerSprite
}

/* 
 * ================
 * ENEMY (Child Class of Ship)
 * ================
 */

Enemy::Enemy(int x, int y)
{
    this->x = x;
    this->y = y;
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

/* 
 * ================
 * PROJECTILE
 * ================
 */

Projectile::Projectile(int x, int y, int speedX)
{
    this->x = x;
    this->y = y;
    this->speedX = speedX;
    gb.sound.fx(mySfx);
}

Projectile::Projectile()
{
}

Projectile::~Projectile()
{

}

void Projectile::Draw()
{
    Image ammuSprite(ammuSpriteData);
    gb.display.drawImage(this->x, this->y, ammuSprite);
}

bool Projectile::Move()
{
    this->x += this->speedX;
    if (this->x > gb.display.width()) //checks for screen bounds
            return true;
    else return false;
}



