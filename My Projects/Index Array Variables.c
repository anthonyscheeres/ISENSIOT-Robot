/*
  Index Array Variables.c
  
  Use a for loop to display all the elements in an array.
  
  http://learn.parallax.com/propeller-c-start-simple/index-array-variables
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int p[] = {1*100, 2*100, 3*100, 5*100, 7*100, 11*100, 13*100, 17*100, 19*100, 23*100};              // Initialize the array
  for(int i = 0; i < sizeof(p) /sizeof(int); i++)                  // Count i from 0 to 5
  {
    print("p[%d] = %d\n", i, p[i]);           // Display array element & value
    pause(500);                             // 1/2 second pause
  }
}