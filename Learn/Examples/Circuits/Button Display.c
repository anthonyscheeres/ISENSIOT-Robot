/*
  Button Display.c
 
  Displays the state of the P3 button in the SimpleIDE Terminal.
  1 -> button pressed, 0 -> button not pressed.
*/

#include "simpletools.h"                      // Include simpletools

int main()                                    // main function
{
  while(1)
  {
    int button = input(3);
    
    if(button == 1) 
      {
      high(26);            
      }
    else
     {
      low(26);
     }
   }
}      
 