/*
  LED P26 en P27 in- en uitschakelen door middel van twee drukknoppen
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  while(1)                                    // Endless loop
  {
    int button1 = input(10);                  // "On" button = P10
    int button2 = input(6);                   // "Off" button = P6
    if(button1 == 1)                          // If "On" button is pressed
    {
      high(26);                               // Turn on LED P26
      high(27);                               // Turn on LED P27
    }
    if(button1 == 0)                          // If "On" button is not pressed
    {
      pause(26);                              // Leave LED P26 in its current state
      pause(27);                              // Leave LED P27 in its current state
    }
    if(button2 == 1)                          // If "Off" button is pressed
    {
      low(26);                                // Turn off LED P26
      low(27);                                // Turn off LED P27
    }
  }
}                        
       
// Invoerbereik: 0 of 1
// Sampling rate: ?