#ifndef GAME_H
#define GAME_H

#include <Gamebuino-Meta.h>
#include "Ship.h"
#include "Explosion.h"

/*
* ====================
* G A M E - C L A S S
* ====================
* Contains every function to calculate or draw game mechanics.
* This makes it possible to dynamically delete Games, create new ones.
* For testing the core settings of the game are set by macros like MAX_EXPLOSIONS.
* In future this could be changed to Constructor-Parameters to be capable of
* changing the difficulty of a new level.
*
* The functions remained the same. There a just a few name changes.
* I quit to use the "this->" pointer, cause the class takes no parameters or extern
* variables.
*/

#define MAX_ENEMIES_SPAWN 7 // actually number of slots where enemys can spawn, to prevent that they flying behind each other
#define ENEMY_SPAWN_RATE 20 // spawn enemy every x frames after another
#define MAX_ENEMIES_ON_SCREEN 1 // maximum enemies that are on screen at the same time
#define MAX_PLAYER_PROJECTILES 10
#define MAX_ENEMY_PROJECTILES 5
#define MAX_EXPLOSIONS MAX_ENEMIES_SPAWN + 1
#define POINTS_PER_KILLED_ENEMY 5
#define MINUS_POINTS_PER_MISSED_ENEMY 10
#define MAX_HIGHSCORES 5

class Game
{
public:
    Game();
    ~Game();

    /*
     * V A R I A B L E S
     */

    Player *p1;
    int difficultyTimer;
    int currMaxEnemiesOnScreen;

    int curEnem;  // current number of enemies on screen
    int curEnemProj;  // current number of enemie projectiles
    int projIndex;    // Array Indexes for going through the arrays
    int enemySpawnTimer;
    int highscore[MAX_HIGHSCORES];
    int rank;

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
    void LevelProgress(); // calculates Time and changes values

    void PlayerShoots();
    void PlayerRecharges(); // wrapper function for ammo recharge
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
    void DrawPause();

    void setHighscore();
    void printHighscore();
};

#endif
