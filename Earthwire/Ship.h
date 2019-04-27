


class Ship 
{
public:
    Ship(int, int);
    Ship();
    ~Ship();
    void Draw();
    void Move(char);
    int Life = 100;
    int x, y = 0;
    int sizeX = 5; //TODO: Not 5, but variable
    int sizeY = 5;

};

class Player : public Ship
{
public:
  Player(int, int, char);
  char Name;
  int score;
  int life;
};

class Projectile
{
  public:
    Projectile(int, int);
    Projectile();
    ~Projectile();
    void Draw();
    int speedX;
    int speedY;
    int x;
    int y;
};

class Enemy : public Ship
{
public:
  Enemy(int, int);
  Enemy();
  ~Enemy();
};

