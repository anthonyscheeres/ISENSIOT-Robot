/* 
  60 graden naar links en naar rechts op de plaats laten draaien
*/

#include "simpletools.h"
#include "abdrive360.h"

int main()
{
  drive_goto(17.04, -17.04);          // Linkerwiel draait 17.04 ticks naar voor, rechterwiel draait 17.04 ticks naar achter
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(-17.04, 17.04);          // Linkerwiel draait 17.04 ticks naar achter, rechterwiel draait 17.04 ticks naar voor
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(-17.04, 17.04);          // Linkerwiel draait 17.04 ticks naar achter, rechterwiel draait 17.04 ticks naar voor
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(17.04, -17.04);          // Linkerwiel draait 17.04 ticks naar voor, rechterwiel draait 17.04 ticks naar achter
}

// Ticks for angle = angle * 0.284
// Ticks for 60 degree angle = 60 * 0.284 = 17.04