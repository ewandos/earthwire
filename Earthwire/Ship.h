// Ressources
#include <Gamebuino-Meta.h>
#include <cstdlib>
#include "graphics.cpp"
#include "sounds.cpp"

// Components
#include "Projectile.h"

#define DEFAULT_ANIMATION_SPEED 3 // frames per image

class Ship
{
public:
    Ship(int, int);
    Ship();
    ~Ship();

    // Variables
    int life = 100;
    int x = 0;  // Coordinates
    int y = 0;
    int sizeX = 5;  // Size for Collision
    int sizeY = 5;
    int wingX1;     // x-position of Wings
    int wingX2;
    int explodeTime; // delets Ship when < 0, duration gets calculated by animation-speed * number of images
    int explodeTimer = 0; //timer for explosion
    float speed;

    // Functions
    virtual void CheckProjColl(Projectile*[], int maxProj) = 0; // Checks Collision based on Projectile Array
    virtual void Draw() = 0;  // Interface for child classes
    virtual void Explode() = 0; // Interface for child classes
    virtual Projectile* Shoot() = 0;  // Interface for child classes
};

class Player : public Ship
{
public:
  Player(int, int, char);
  ~Player();
  // Variables
  char name;
  int score;

  // Functions
  void Draw();
  void Explode();
  bool Move(char);  // Changes Coordinates based on Input
  Projectile* Shoot();
  void CheckProjColl(Projectile*[], int maxProj);
};

class Enemy : public Ship
{
public:
  Enemy(int shootingRate);
  ~Enemy();

  // Variables
  int shootingRate; // how often the enemy shoots

  // Functions
  void Draw();
  void Explode();
  bool Move();
  Projectile* Shoot();
  void CheckProjColl(Projectile*[], int maxProj);
  void CheckPlaneColl(Ship*);
};
