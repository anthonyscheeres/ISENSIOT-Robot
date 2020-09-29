/*
  Piezo Beep.c
 
  Beep a piezo speaker connected to P4.
*/

#include "simpletools.h"                      // Include simpletools                   

int main()                                    // main function             
{
  freqout(3, 1000, 3000);                     // pin, duration, frequency
}