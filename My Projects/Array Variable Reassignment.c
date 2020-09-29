/* 
  Array Variables.c  
   
  Declare and initialize an array and display a couple of its elements.
  
  http://learn.parallax.com/propeller-c-start-simple/array-variables
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  int p[] = {1, 2, 3, 5, 7, 11};              // Initialize the array
  print("p[0] = %d\n", p[0]);                 // Display what p[0] stores
  print("p[3] = %d\n", p[3]);                 // display what p[3] stores
  p[0] = 11;
  p[1] = 7;
  p[2] = 5;
  p[3] = 3;
  p[4] = 2;
  p[5] = 1;
  p[3] = 101;
  print ("p[0] = %d\n", p[0]);
  print ("p[1] = %d\n", p[1]);
  print ("p[2] = %d\n", p[2]);
  print ("p[3] = %d\n", p[3]);
  print ("p[4] = %d\n", p[4]);
  print ("p[5] = %d\n", p[5]);
}
