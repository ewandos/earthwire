#include <Gamebuino-Meta.h>
#include "graphics.cpp"
#include "sounds.cpp"

class Projectile
{
  public:
    Projectile(int, int, int, bool); // x, y, speedX, fromPlayer
    ~Projectile();

    // Variables
    int speedX; // not an absolute value, sign gives direction (positive means moving eastward, negative means moving westward)
    int speedY;
    int x;
    int y;
    int damage;
    int speed;
    bool fromPlayer;

    // Functions
    void Draw();
    bool Move(); // this returns a bool to decide whether the object should be deleted because it's oob
};
