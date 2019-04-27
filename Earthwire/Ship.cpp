#include <Gamebuino-Meta.h>
#include "Ship.h"

Ship::Ship(int x, int y)
{
    this->x = x;
    this->y = y;
}

Ship::Ship()
{
}

void Ship::Draw()
{
    gb.display.fillRect(this->x, this->y, this->sizeX, this->sizeY);
}

Ship::~Ship()
{
}

void Ship::Move(char dir)
{
  switch(dir)
  {
    case 'w':
    this->x--;
    break;
    case 'e':
    this->x++;
    break;
    case 'n':
    this->y--;
    break;
    case 's':
    this->y++;
    break;
    default:
    break;
  }
}

Player::Player(int x, int y, char Name)
{
  this->x = x;
  this->y = y;
  this->Name = Name;
  this->life = 100;
}

Projectile::Projectile(int x, int y)
{
  this->x = x;
  this->y = y;
}

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

void Projectile::Draw()
{
  gb.display.fillRect(this->x, this->y, 5, 5);
}

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
