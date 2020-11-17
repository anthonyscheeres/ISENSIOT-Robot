/*
  LED P26 en P27 in- en uitschakelen door middel van twee drukknoppen
*/

#include "simpletools.h"                      // Include simpletools
#include <sys/time.h>

int main()                                    // main function
{
  while(1)                                    // Endless loop
  {
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);
    
    int button1 = input(10);                  // "On" button = P10
    int button2 = input(6);                   // "Off" button = P6
    if(button1 == 1)                          // If "On" button is pressed
    {
      high(26);                               // Turn on LED P26
      high(27);                               // Turn on LED P27
    }
    if(button2 == 1)                          // If "Off" button is pressed
    {
      low(26);                                // Turn off LED P26
      low(27);                                // Turn off LED P27
    }
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f\n",secs);
  
    int SampleRate = (1/secs);
    printf("SampleRate %d Hz\n", SampleRate);
    pause(200);
  }
}                        
       
// Invoerbereik: 0 of 1
// Sampling rate: ?