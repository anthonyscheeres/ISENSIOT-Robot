/* 
  60 graden naar links en naar rechts op de plaats laten draaien
*/

#include "simpletools.h"
#include "abdrive.h"

int main()                    
{
  drive_goto(17.04, -17.04);
  pause(200);
  drive_goto(-17.04, 17.04);
  pause(200);
  drive_goto(-17.04, 17.04);
  pause(200);
  drive_goto(17.04, -17.04);
}

// Ticks for angle = angle * 0.284
// Ticks for 60 degree angle = 60 * 0.284 = 17.04