/* 
  60 graden naar links en naar rechts op de plaats laten draaien
*/

<<<<<<< Updated upstream
#include "simpletools.h"
#include "abdrive360.h"
=======
#include "simpletools.h"                      // Include simple tools
#include "abdrive360.h"                       // Include abdrive header
>>>>>>> Stashed changes

int main()
{
<<<<<<< Updated upstream
  drive_goto(17.04, -17.04);          // Linkerwiel draait 17.04 ticks naar voor, rechterwiel draait 17.04 ticks naar achter
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(-17.04, 17.04);          // Linkerwiel draait 17.04 ticks naar achter, rechterwiel draait 17.04 ticks naar voor
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(-17.04, 17.04);          // Linkerwiel draait 17.04 ticks naar achter, rechterwiel draait 17.04 ticks naar voor
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(17.04, -17.04);          // Linkerwiel draait 17.04 ticks naar voor, rechterwiel draait 17.04 ticks naar achter
}
=======
    drive_speed(30.76923077, 30.76923077);    // Drive speed forward = 30,8 tps left and right
    pause(5000);                              // Drive time = 5 s
    drive_speed(0.0, 0.0);                    // No drive speed
    pause(3000);                              // Stand still for 3 s
    drive_speed(-30.76923077, -30.76923077);  // Drive speed backward = 30,8 tps left and right
    pause(5000);                              // Drive time = 5 s
    drive_speed(0, 0);                        // Stop
}      
>>>>>>> Stashed changes

// Ticks for angle = angle * 0.284
// Ticks for 60 degree angle = 60 * 0.284 = 17.04