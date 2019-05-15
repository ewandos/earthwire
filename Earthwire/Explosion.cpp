#include "Explosion.h"

Explosion::Explosion(int x, int y)
{
    this->x = x;
    this->y = y;
}

Explosion::~Explosion()
{
}

void Explosion::DrawExplosion()
{
    Image enemyExplode(enemyExplodeData);
    int animSpeed = DEFAULT_ANIMATION_SPEED;
    int curImg = 1 + (this->explodeTimer - 1) / animSpeed; //current image of animation
    for (int i = 1; i < curImg; i++)
    {
        enemyExplode.frame_handler->next(); //gives drawImage-function information to refer to next image of the animation

        if (i <= 2)
            gb.lights.fill(YELLOW);
        else
            gb.lights.fill(BLACK);
    }
    this->explodeTime = (enemyExplode.frames * animSpeed) - this->explodeTimer;

    gb.display.drawImage(this->x, this->y, enemyExplode);
}