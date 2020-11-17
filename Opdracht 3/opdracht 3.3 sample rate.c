#include "simpletools.h"                      
#include "abdrive.h"
#include "ping.h"
#include <sys/time.h>

int main()                                    
{
  double totaalSeconden = 0;
  int intervallen = 100;
  
  for(int i = 0; i < intervallen; i++)
  {
    struct timeval start, stop;
    double seconden = 0;

    gettimeofday(&start, NULL);

    int cmDist = ping_cm(8);                
    print("cmDist = %d\n", cmDist);                                          

    gettimeofday(&stop, NULL);
    seconden = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f sec\n",seconden);
  
    int SampleRate = (1/seconden);
    printf("SampleRate %d Hz\n", SampleRate);
    printf("\n");
    
    totaalSeconden+= seconden;
    print("Totaal aantal seconden = %f\n", totaalSeconden);
  }
  
  print("Totaal aantal seconden = %f\n", totaalSeconden);
  
  double effective_sample_rate = 1 / (totaalSeconden / intervallen);
  print("Effectieve sample rate = %fHz\n", effective_sample_rate);
}
