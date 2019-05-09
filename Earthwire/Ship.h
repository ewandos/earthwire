// Ressources
#include <Gamebuino-Meta.h>
#include <cstdlib>
#include "graphics.cpp"
#include "sounds.cpp"

// Components
#include "Projectile.h"

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
    int explodeTime = 12; // frames for explosion animation
    float speed;

    // Functions
    virtual void CheckProjColl(Projectile*[], int maxProj) = 0; // Checks Collision based on Projectile Array
    virtual void Draw() = 0;  // Interface for child classes
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
  bool Move();
  Projectile* Shoot();
  void CheckProjColl(Projectile*[], int maxProj);
  void CheckPlaneColl(Ship*);
};
