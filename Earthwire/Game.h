#ifndef GAME_H
#define GAME_H

#include <Gamebuino-Meta.h>
#include "Ship.h"
#include "Explosion.h"

#define MAX_ENEMIES_SPAWN 2
#define MAX_PLAYER_PROJECTILES 10
#define MAX_ENEMY_PROJECTILES 5
#define MAX_EXPLOSIONS MAX_ENEMIES_SPAWN + 1

class Game
{
public:
    Game();

    ~Game();

    /*
     * V A R I A B L E S
     */

    Player *p1;

    int curEnem;  // current number of enemies on screen
    int curEnemProj;  // current number of enemie projectiles
    int projIndex;    // Array Indexes for going through the arrays

    //the purpose of this arrays is to limit the stuff that gets drawn on screen
    // current values are for testing
    Projectile *ProjArr[MAX_PLAYER_PROJECTILES] = {nullptr};    // Array of Player Projectiles
    Projectile *EnemProjArr[MAX_ENEMY_PROJECTILES] = {nullptr};     // Array of Enemy Projectiles
    Enemy *EnemyArr[MAX_ENEMIES_SPAWN] = {nullptr};    // Array of Enemies
    Explosion *ExplosionsArr[MAX_EXPLOSIONS] = {nullptr};   // Array of Explosions

    /*
     * F U N C T I O N S
     */

    // Calculation
    void PlayerShoots();
    void SpawnEnemies();
    void LetEnemiesShoot();

    bool CheckPlayerStatus();
    void CheckEnemiesStatus();
    bool NoExplosionsLeft(Explosion **ExplosionsArr, int arraySize);

    void MoveProjectiles();

    // Drawing
    void DrawProjectiles();
    void DrawEnemies();
    void DrawPlayer();
    void DrawExplosions();
};

#endif
