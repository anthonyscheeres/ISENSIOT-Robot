/*
  Count to Ten.c

  Version 0.94 for use with SimpleIDE 9.40 and its Simple Libraries
  
  http://learn.parallax.com/propeller-c-start-simple/counting-loops
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  for(int n = 0; n <= 200; n = n + 5)                // Count to ten
  {
    print("n = %d\n", n);                     // Display name & value of n
    pause(500);                               // 0.5 s between reps
  }
  for(int n = 190; n >=0; n = n - 10)
  {
  print("n = %d\n", n);                     // Display name & value of n
  pause(500);
  }  
  print("All done!");                         // Display all done
}
