#include <Gamebuino-Meta.h>
#include "Game.h"

/*
* =====================
* V A R I A B L E S - S E T U P
* =====================
*/

Game *game = new Game();

enum GameState
{
    inGame, gameOver
};

int gameState = inGame;

/*
* =====================
* G A M E B U I N O - S E T U P
* =====================
*/

void setup()
{
    gb.begin();
}

/*
* =====================
* G A M E - L O O P
* =====================
*/

void loop()
{
    while (!gb.update());

    if (gameState == inGame)
    {

        /*
        * U S E R   I N P U T
        */

        if (gb.buttons.repeat(BUTTON_UP, 1))
            game->p1->Move('n');

        if (gb.buttons.repeat(BUTTON_DOWN, 1))
            game->p1->Move('s');

        if (gb.buttons.repeat(BUTTON_LEFT, 1))
            game->p1->Move('w');

        if (gb.buttons.repeat(BUTTON_RIGHT, 1))
            game->p1->Move('e');

        // Player's Ability to shoot (!Testing!)
        if (gb.buttons.pressed(BUTTON_A))
        {
            game->PlayerShoots();
        }
        // Recharging mechanic
        if (gb.buttons.pressed(BUTTON_B) || game->p1->recharging) // Right now this gets called per frame (mostly because it's the easiest and cleanest method)
        {
            game->PlayerRecharges();
        }

        /*
        * C A L C U L A T O N
        */

        game->SpawnEnemies();
        game->LetEnemiesShoot();
        game->CheckEnemiesStatus();
        game->MoveProjectiles();

        if (!game->CheckPlayerStatus())
        {
            gameState = gameOver;
        }


        gb.display.clear(); // clear the previous screen

        /*
         * D R A W I N G   U S E R  I N T E R F A C E
         */

        // HULL
        Image hullSprite(hullSpriteData);
        gb.display.drawImage(0, 0, hullSprite);
        gb.display.setColor(YELLOW);
        int hullBarWidth = game->p1->life / 5;
        gb.display.fillRect(8, 0, hullBarWidth, 5);
        gb.display.drawRect(7, 0, 22, 5);

        // AMMUNATION
        Image ammuSprite(ammuSpriteData);
        gb.display.drawImage(32, 0, ammuSprite);
        gb.display.setColor(RED);
        int ammuBarWidth = game->p1->ammunation / 5;
        gb.display.fillRect(38, 0, ammuBarWidth, 5);
        gb.display.drawRect(37, 0, 22, 5);

        // SCORE
        gb.display.setColor(WHITE);
        gb.display.setCursor(63, 0);
        gb.display.print(game->p1->score);

        /*
        //debug RAM print
        uint16_t ram = gb.getFreeRam();
        gb.display.setCursor(0, 59);
        gb.display.print("RAM:");
        gb.display.println(ram);
        */

        /*
        * D R A W I N G   S P R I T E S
        */

        game->DrawProjectiles();
        game->DrawEnemies();
        game->DrawPlayer();
        game->DrawExplosions();

    } else if (gameState == gameOver)
    {
        gb.display.clear();
        gb.sound.fx(mySfx);
        gb.display.setCursor(5, 35);
        gb.display.print("Press A to restart");

        delete game;
        game = new Game();

        if (gb.buttons.pressed(BUTTON_A))
        {
            gameState = inGame;
        }
    }

}
