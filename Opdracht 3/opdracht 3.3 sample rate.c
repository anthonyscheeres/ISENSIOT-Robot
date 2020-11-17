/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      
#include "abdrive.h"
#include "ping.h"
#include <sys/time.h>
int main()                                    
{
  while(1)
  {
    struct timeval start, stop;
    double secs = 0;

    gettimeofday(&start, NULL);

    int cmDist = ping_cm(8);                 
    print("cmDist = %d\n", cmDist);           
   // pause(200);                               

    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f sec\n",secs);
  
    int SampleRate = (1/secs);
    printf("SampleRate %d Hz\n", SampleRate);
  }
}