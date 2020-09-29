/*
  50 cm voor- achteruit rijden 
*/

#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"                       // Include abdrive header

int main()                                    // Main function
{
  {
    drive_goto(256, 256);
    pause(200);
    drive_goto(26, -25);                      // Stop
  }
}      

// 1 tick = 0,325 cm
// 153,846154 ticks = 50 cm
// 153,846154 ticks/5 sec = 30.76923077 tps