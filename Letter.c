/*
  50 cm voor- achteruit rijden 
*/

#include "simpletools.h"                      // Include simple tools
#include "abdrive360.h"                       // Include abdrive header

int main()                                    // Main function
{
    drive_goto(15.38461538, 15.38461538);     // 5 cm vooruit   
    drive_goto(-25.56, 25.56);                // 90 graden links
    drive_goto(15.38461538, 15.38461538);     // 5 cm vooruit  
    drive_goto(-25.56, 25.56);                // 90 graden links
    drive_goto(15.38461538, 15.38461538);     // 5 cm vooruit   
    drive_goto(25.56, -25.56);                // 90 graden rechts
    drive_goto(15.38461538, 15.38461538);     // 5 cm vooruit  
    drive_goto(25.56, -25.56);                // 90 graden rechts
    drive_goto(61.53846154, 61.53846154);     // 20 cm vooruit
    drive_goto(25.56, -25.56);                // 90 graden rechts
    drive_goto(6.153846154, 6.153846154);     // 2 cm vooruit
    drive_goto(25.56, -25.56);                // 90 graden rechts
    drive_goto(15.38461538, 15.38461538);     // 5 cm vooruit 
    drive_goto(-25.56, 25.56);                // 90 graden links
    drive_goto(30.76923077, 30.76923077);     // 10 cm vooruit
    drive_goto(-41.18, 41.18);                // 145 graden links
    drive_goto(40, 40);                       // 13 cm vooruit
    drive_goto(34.08, -34.08);                // 120 graden rechts
    drive_goto(40, 40);                       // 13 cm vooruit               
}      

/* 
   1 tick = 0,325 cm

   15.38461538 = 5 cm
   30.76923077 = 10 cm
   40          = 13 cm
   61.53846154 = 20 cm
   6.153846154 = 2 cm
   
   Ticks for angle = angle * 0.284
   
   90 graden   = 25,56
   120 graden  = 34.08
   145 graden  = 41.18
*/
 