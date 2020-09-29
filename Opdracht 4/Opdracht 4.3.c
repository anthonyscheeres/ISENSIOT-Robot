/*
  Programmeer twee herkenbare fluitsignalen
*/
#include "simpletools.h"

void fluit(int startNoot, int aantalStappen, int stapGrootte, int stapDuur);

int main()
{
  fluit(523, 784, 1, 10);
  
}

void fluit(int startNoot, int eindNoot, int stapGrootte, int stapDuur) 
{
  int aantalStappen = eindNoot - startNoot;
  for(int i = 0; i < aantalStappen; i++) 
  {
    freqout(4, stapDuur, startNoot);
    startNoot = startNoot + stapGrootte;
  }        
} 
