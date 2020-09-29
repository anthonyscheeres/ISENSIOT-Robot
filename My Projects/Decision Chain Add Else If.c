/*
  Decision Chain.c

  Check a series of conditions, but only act on the first one that's true.
  
  http://learn.parallax.com/propeller-c-start-simple/make-several-decisions
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int a = -1;                                 // Initialize a variable to 25
  int b = 1000;                                 // Initialize b variable to 17
  print("a = %d, b = %d\n", a, b);            // Print all
  if(a > 0)                                   // If a > b condition is true
  {
    print("a is positive \n");                  // Then print this message
  }
  else if (a == 0)
  {
  print("a is zero \n");
  }  
  else if (a < 0)                             // a > b not true? check a < b
  {
    print("a is negative\n");                  // If true, print this instead
  }
}
