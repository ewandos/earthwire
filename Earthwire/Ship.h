#include <Gamebuino-Meta.h>

class Projectile
{
  public:
    Projectile(int, int, int); // x, y and speedX
    ~Projectile();

    // Variables
    int speedX; // not an absolute value, sign gives direction (positive means moving eastward, negative means moving westward)
    int speedY;
    int x;
    int y;
    int damage;

    // Functions
    void Draw();
    bool Move(); // this returns a bool to decide whether the object should be deleted because it's oob
};

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

    // Functions
    void Move(char);  // Changes Coordinates based on Input
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
  int life;

  // Functions
  void Draw();
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
  int life;

  // Functions
  void Draw();
  Projectile* Shoot();
  void CheckProjColl(Projectile*[], int maxProj);
};
