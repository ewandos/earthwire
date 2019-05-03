#include <Gamebuino-Meta.h>
#include "Ship.h"

 Player p1(8, 9, 'a');
 Projectile* ProjArr [5] = {nullptr}; //the purpose of this array is to limit the stuff that gets drawn on screen; might be able to get away with more than 5
 int i = 0;  

///////////////////////////////////// SETUP
void setup() {
  gb.begin();

}

///////////////////////////////////// LOOP
void loop() {
  while (!gb.update());

  /* 
   * CALCULATION
   */
   
  // Movement Input
  if (gb.buttons.repeat(BUTTON_UP, 1)) 
  {
    p1.Move('n');
  }
  if (gb.buttons.repeat(BUTTON_DOWN, 1)) 
  {
    p1.Move('s');
  }
  if (gb.buttons.repeat(BUTTON_LEFT, 1))
  {
    p1.Move('w');
  }

  if (gb.buttons.repeat(BUTTON_RIGHT, 1))
  {
    p1.Move('e');
  }

  // Spawn new Projectile (!Testing!)
  if (gb.buttons.pressed(BUTTON_A))
  {
    ProjArr[i] = new Projectile(p1.x + 15, p1.y + 15);
    i++;
    if ( i >= 5)
    i = 0;
  }

  // GameOver-Condition (should be only called after a collission has been registered)
  if (p1.life < 1)
  {
    // Player is dead -> what happens now
  }

  // clear the previous screen
  gb.display.clear();

  /* 
   * DRAWING
   */ 
   
  p1.Draw();
  for (int j = 0; j < 5; j++)
  {
    if (ProjArr[j] != nullptr)
      ProjArr[j]->draw();
  }
}
