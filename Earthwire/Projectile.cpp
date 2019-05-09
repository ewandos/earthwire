#include "Projectile.h"

Projectile::Projectile(int x, int y, int speedX)
{
    this->x = x;
    this->y = y;
    this->speedX = speedX;
    gb.sound.fx(mySfx);
    this->damage = 10;
}

Projectile::~Projectile(){}

void Projectile::Draw()
{
    Image projectileImg(projectileImgData);
    gb.display.drawImage(this->x, this->y, projectileImg);
}

bool Projectile::Move()
{
    this->x += this->speedX;
    if (this->x > gb.display.width() || this->x < 0 || this->y < 0 || this->y > gb.display.height()) //checks for screen bounds
            return false;  // Returns false if Projectile is out of the window

    else return true;
}
