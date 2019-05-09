#ifndef SOUNDS_CPP
#define SOUNDS_CPP
#include <Gamebuino-Meta.h>


// This is a sound for testing, to be overwritten later by either a wav file or an actual sound pattern

const Gamebuino_Meta::Sound_FX mySfx[] = {
    {Gamebuino_Meta::Sound_FX_Wave::NOISE,1,100,2,5,96,3},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,1,100,10,0,126,10},
    {Gamebuino_Meta::Sound_FX_Wave::SQUARE,0,120,-6,0,84,10},
};
#endif
