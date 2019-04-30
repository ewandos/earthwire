#include <Gamebuino-Meta.h>
#include "Ship.h"

 Player p1(5, 5, 'a');
 Projectile* ProjArr [5] = {nullptr}; //the purpose of this array is to limit the stuff that gets drawn on screen; might be able to get away with more than 5
 int i = 0;  

///////////////////////////////////// SETUP
void setup() {
  gb.begin();

}

///////////////////////////////////// LOOP
void loop() {

  while (!gb.update());
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

  if (gb.buttons.pressed(BUTTON_A))
  {
    ProjArr[i] = new Projectile(p1.x + 15, p1.y + 15);
    i++;
    if ( i >= 5)
    i = 0;
  }

  // clear the previous screen
  gb.display.clear();
  if (p1.Life < 1)
  {
    
  }
    //TODO: End Screen; Also, this check probably should be only called after a collission has been registered

  p1.Draw();
  for (int j = 0; j < 5; j++)
  {
    if (ProjArr[j] != nullptr)
      ProjArr[j]->Draw();
  }
}
