#include <Gamebuino-Meta.h>
#include "graphics.cpp"
#include "sounds.cpp"

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
    int speed;

    // Functions
    void Draw();
    bool Move(); // this returns a bool to decide whether the object should be deleted because it's oob
};
