/*
  Variables and Calculations.c
  
  Add two integer values together and display the result.
  
  http://learn.parallax.com/propeller-c-start-simple/variables-and-math
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int a = 17;                                 // Initialize a variable to 25
  int b = 25;                                 // Initialize b variable to 17
  int c = a + b;                              // Initialize c variable to a + b
  print("a = %d, b = %d\n", a, b);                        // Display decimal value of c
  print("a + b = %d\n", c);
  c = a - b;
  print("a = %d, b = %d, b = %d\n", a, b);
  print("a - b = %d\n", c);
}
