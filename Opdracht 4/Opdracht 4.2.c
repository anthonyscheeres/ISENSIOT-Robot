/*
  50 cm voor- achteruit rijden 
*/

<<<<<<< Updated upstream
#include "simpletools.h"                      // Include simple tools
#include "abdrive360.h"                       // Include abdrive header
=======
#include "simpletools.h"
#include "abdrive360.h"
>>>>>>> Stashed changes

int main()                                    // Main function
{
<<<<<<< Updated upstream
  drive_speed(30.76923077, 30.76923077);    // Drive speed forward = 30,8 tps left and right
  pause(5000);                              // Drive time = 5 s
  drive_speed(0.0, 0.0);                    // No drive speed
  pause(3000);                              // Stand still for 3 s
  drive_speed(-30.76923077, -30.76923077);  // Drive speed backward = 30,8 tps left and right
  pause(5000);                              // Drive time = 5 s
  drive_speed(0, 0);                        // Stop
=======
  drive_goto(-8.52, 8.52);          // Linkerwiel draait 17.04 ticks naar voor, rechterwiel draait 17.04 ticks naar achter
  pause(200);                         // Robot blijft 2 seconden op zijn plek
  drive_goto(8.52, -8.52);          // Linkerwiel draait 17.04 ticks naar achter, rechterwiel draait 17.04 ticks naar voor
  pause(8000);
>>>>>>> Stashed changes
}

// 1 tick = 0,325 cm
// 153,846154 ticks = 50 cm
// 153,846154 ticks/5 sec = 30.76923077 tps