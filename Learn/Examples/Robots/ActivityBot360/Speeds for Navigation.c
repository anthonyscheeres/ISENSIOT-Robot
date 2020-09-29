/* 
  Speeds for Navigation.c
  
  Navigate by making your ActivityBot go certain speeds for certain amounts
  of time.

  http://learn.parallax.com/activitybot/set-certain-speeds
*/


#include "simpletools.h"                      // simpletools library
#include "abdrive360.h"                          // abdrive library

int main()                   
{
  drive_ramp(64, 64);                       // Forward 64 tps for 2 s
  pause(2000);
  drive_ramp(0, 0);

  drive_ramp(26, 0);                        // Turn 26 tps for 1 s
  pause(1000);
  drive_ramp(0, 0);

  drive_ramp(128, 128);                     // Forward 128 tps for 1 s
  pause(1000);
  drive_ramp(0, 0);
}