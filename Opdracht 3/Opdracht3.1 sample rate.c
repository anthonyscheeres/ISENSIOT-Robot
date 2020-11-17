/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      
#include <sys/time.h>
int main()                                    
{
  while(1)
  {
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);

    int whiskerL = input(9);                  // Left whisker = P9
    int whiskerR = input(6); 
                     // Right whisker = P6
    if(whiskerL == 0)                         // When left whisker makes contact
    {
      freqout(1, 1, 10000);                   // Speaker tone: P1, 1 ms, 10 KHz          
    }      
    if(whiskerR == 0)                         // When right whisker makes contact
    {          
      freqout(1, 1, 2000);                    // Speaker tone P1, 1 ms, 2 KHz
    }                            

    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f sec\n",secs);
  
    int SampleRate = (1/secs);
    printf("SampleRate %d Hz\n", SampleRate);
    //pause(200);
  }
}