#include "Projectile.h"

Projectile::Projectile(int x, int y, int speedX, bool fromPlayer)
{
    this->x = x;
    this->y = y;
    this->speedX = speedX;
    gb.sound.fx(mySfx);
    this->damage = 10;
    this->fromPlayer = fromPlayer;
}

Projectile::~Projectile(){}

void Projectile::Draw()
{
    Image projectileImg(projectileImgData);
    gb.display.drawImage(this->x, this->y, projectileImg);
}

void Projectile::Move()
{
    this->x += this->speedX;
}

bool Projectile::isOOB()
{
    if (this->x > gb.display.width() || this->x < 0 || this->y < 0 || this->y > gb.display.height()) //checks for screen bounds
        return true;  // Returns true if Projectile is out of the window
    else
        return false;
}
