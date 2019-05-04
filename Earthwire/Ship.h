#include <Gamebuino-Meta.h>

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
    void Draw();
    void Move(char);  // Changes Coordinates based on Input
};

class Player : public Ship
{
public:
  Player(int, int, char);
  
  // Variables
  char name;
  int score;
  int life;
};

class Enemy : public Ship
{
public:
  Enemy(int, int);
  Enemy();
  ~Enemy();
};

class Projectile
{
  public:
    Projectile(int, int, int); // x, y and speedX
    Projectile();
    ~Projectile();
    
    // Variables
    int speedX; // not an absolute value, sign gives direction (positive means moving eastward, negative means moving westward)
    int speedY;
    int x;
    int y;
    
    // Functions
    void Draw();
    bool Move(); // this returns a bool to decide whether the object should be deleted because it's oob
};
