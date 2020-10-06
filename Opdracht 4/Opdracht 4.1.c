/*
  50 cm voor- achteruit rijden 
*/

#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"                       // Include abdrive header

int main()                                    // Main function
{
  {
<<<<<<< Updated upstream
    drive_goto(256, 256);
    pause(200);
    drive_goto(26, -25);                      // Stop
=======
    drive_speed(30.76923077, 30.76923077);    // Drive speed forward = 30,8 tps left and right
    pause(5000);                              // Drive time = 5 s
    drive_speed(0.0, 0.0);                    // No drive speed
    pause(3000);                              // Stand still for 3 s
    drive_speed(-30.76923077, -30.76923077);  // Drive speed backward = 30,8 tps left and right
    pause(5000);                              // Drive time = 5 s
    drive_speed(0, 0);                        // Stop
>>>>>>> Stashed changes
  }
}      

// 1 tick = 0,325 cm
// 153,846154 ticks = 50 cm
// 153,846154 ticks/5 sec = 30.76923077 tps