#include "Ship.h"
// Information for datastructures of the classes located in header-file

/*
* =====================
* S H I P
* =====================
*/

Ship::Ship()
{
    this->isDestroyed = false;
}

Ship::~Ship()
{
}

void Ship::Explode(Explosion** Arr, int max)
{
    this->life = 0;
    for (int i = 0; i < max; i++)
    {
        if (Arr[i] == nullptr)
        {
            Arr[i] = new Explosion(this->x, this->y);
        } else if (Arr[max-1] != nullptr) {
            delete Arr[0];
            Arr[0] = new Explosion(this->x, this->y);
        }
    }
    this->isDestroyed = true;
}

/*
* =====================
* P L A Y E R - S H I P
* =====================
*/

Player::Player(int x, int y, char c)
{
    this->x = x;
    this->y = y;
    this->name = name; // Not used yet anyway, but maybe this->name = c; intended?
    this->life = 100;
    this->sizeX = 7; // width of playerSprite
    this->sizeY = 9; // height of playerSprite
    this->speed = 1;
    this->ammunation = 100;
    this->score = 0;
    this->wingX1 = 2; //wing-position of playerSprite
    this->wingX2 = 4;
    this->recharging = 0; // player does start out with full ammo, not in the process of recharging
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
                this->x -= (int) this->speed;
                return true;
            }
            break;
        case 'e':
            if (this->x + this->sizeX < gb.display.width())
            {
                this->x += (int) this->speed;
                return true;
            }
            break;
        case 'n':
            if (this->y > 0)
            {
                this->y -= (int) this->speed;
                return true;
            }
            break;
        case 's':
            if (this->y + this->sizeY < gb.display.height())
            {
                this->y += (int) this->speed;
                return true;
            }
            break;
        default:
            return false;
    }
}

void Player::DrawPlane()
{
    Image playerSprite(playerSpriteData);
    gb.display.drawImage(this->x, this->y, playerSprite);
}

Projectile *Player::Shoot()
{
    if (this->recharging) // if the player is restocking ammo, do not shoot
    {
        return nullptr;
    }
    if (this->ammunation <= 0) // if the player does not have any ammo left, play a sound and then do not shoot
    {
        gb.sound.fx(mySfx);
        return nullptr;
    }
    this->ammunation--; // the player shoots, so ammunation is being taken out of his plane
    return new Projectile(this->x + (this->sizeX / 2), this->y + (this->sizeY / 2), 3, true);
}

void Player::CheckProjColl(Projectile *ProjArr[], int maxProj)
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

void Player::Recharge()
{
    this->ammunation++;  // core ammo setter, right now it adds 1 shot per frame, might want to mess with that for balance settings in the future? Works well enough now though
}

/*
* =====================
* E N E M Y - S H I P
* =====================
*/

Enemy::Enemy(int y, int shootingRate)
{
    this->shootingRate = shootingRate;
    // Enemy needs no parameters for coords, cause of random generation
    // init Random Seed
    this->sizeX = 12; // width of playerSprite
    this->sizeY = 15; // height of playerSprite
    this->wingX1 = 4;
    this->wingX2 = 6;
    this->speed = 1;
    this->movementRate = 2;
    this->movementRange = 0;

    this->x = gb.display.width(); // spawns outside of the screen
    this->y = y;
    this->life = 30;
}

Enemy::~Enemy()
{
}

Projectile *Enemy::Shoot()
{
    int shooting = random(this->shootingRate);
    if (shooting == 0)
    { // e.g. shootingRate = 5 -> 1/5 Chance per Frame the enemy is actually shooting
        return new Projectile(this->x + (this->sizeX / 2), this->y + (this->sizeY / 2), -2, false);
    } else
    {
        return nullptr;
    }
}

void Enemy::DrawPlane()
{
    Image enemySprite(enemySpriteData);
    gb.display.drawImage(this->x, this->y, enemySprite);
}

void Enemy::CheckProjColl(Projectile *ProjArr[], int maxProj)
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

void Enemy::CheckPlaneColl(Ship *player)
{
    // Check for Collisions with Player
    if (this->x + this->wingX1 <= player->x + player->wingX2 && this->x + this->wingX2 >= player->x + player->wingX1 && this->y < player->y + player->sizeY && this->y + this->sizeY > player->y)
    { // Plane hit!
        player->life = 0;
        this->life = 0;
    }
}

void Enemy::Move()
{
    // Used to slow down enemy planes and let them move every x = movementRate frames
    this->movementRange++;
    if (this->movementRange % this->movementRate == 0)
    {
        this->x -= this->speed;
        this->movementRange = 0;
    }
}

bool Enemy::isOOB()
{
    if ((this->x + this->sizeX) < 0)
    { // left screen on the left side
        return true;
    } else
    {
        return false;
    }
}
