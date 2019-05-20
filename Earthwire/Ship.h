// Ressources
#include <Gamebuino-Meta.h>
#include <cstdlib>
#include "graphics.cpp"
#include "sounds.cpp"
#include "Projectile.h"
#include "Explosion.h"

class Ship
{
public:
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
    int speed;
    bool isDestroyed;

    // Functions
    void Explode(Explosion**, int);
    virtual void CheckProjColl(Projectile*[], int maxProj) = 0; // Checks Collision based on Projectile Array
    virtual void DrawPlane() = 0;  // Interface for child classes
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
  int ammunation;
  bool recharging; // determines, if the player is currently restocking ammo

  // Functions
  void DrawPlane();
  bool Move(char);  // Changes Coordinates based on Input
  Projectile* Shoot();
  void CheckProjColl(Projectile*[], int maxProj);
  void Recharge(); // handles refilling of Ammo
};

class Enemy : public Ship
{
public:
  Enemy(int y, int shootingRate);
  ~Enemy();

  // Variables
  int shootingRate; // how often the enemy shoots
  int movementRange; // how far the enemy moved
  int movementRate; // enemy moves every x frames

  // Functions
  void DrawPlane();
  void Move();
  bool isOOB();
  Projectile* Shoot();
  void CheckProjColl(Projectile*[], int maxProj);
  void CheckPlaneColl(Ship*);
};
