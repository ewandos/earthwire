#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H

#include <Gamebuino-Meta.h>
#include "graphics.cpp"
#define DEFAULT_ANIMATION_SPEED 3 // frames per image

class Explosion
{
public:
    Explosion(int,int);
    ~Explosion();

    int x;
    int y;
    int explodeTime; // delets Ship when < 0, duration gets calculated by animation-speed * number of images
    int explodeTimer = 0; //timer for explosion

    void DrawExplosion();
};

#endif