#include "simpletools.h"                      // Include simpletools
#include "ping.h"                             // Include ping sensor

int main()                                    // main function
{
  while(1)                                    // Endless loop
  {
    while(ping_cm(8) >= 15);                  // If ping sensor measures object within 15 cm
    {
    high(3);                                  // Turn on LED in P3
    }
    while(ping_cm(8) <= 15);                  // If ping sensor measures object outside 15 cm
    {
    low(3);                                   // Turn off Led in P3
    }
  }     
} 

//  Invoerbereik: 3 cm tot 400 cm
// Sampling rate: ?