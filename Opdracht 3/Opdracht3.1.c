/*
  Twee verschillende tonen genereren met de piezo speaker,
  door de whiskers contact te laten maken met de 3-pin headers.
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  while(1)                                    // Endless loop
  {
    int whiskerL = input(9);                  // Left whisker = P9
    int whiskerR = input(6);                  // Right whisker = P6
    if(whiskerL == 0)                         // When left whisker makes contact
    {
      freqout(1, 1, 10000);                   // Speaker tone: P1, 1 ms, 10 KHz          
    }      
    if(whiskerR == 0)                         // When right whisker makes contact
    {          
      freqout(1, 1, 2000);                    // Speaker tone P1, 1 ms, 2 KHz
    }
  }
}   

//invoerbereik: -oneindig tot oneindig
//sampling rate: ?