/*
  Keyboard Controlled ActivityBot.c
*/

#include "simpletools.h"                      // Library includes
#include "abdrive.h"

terminal *term;                               // For full duplex serial terminal
char c = 0;                                   // Stores character input

int main()                                    // Main function
{
  simpleterm_close();                         // Close default same-cog terminal
  term = fdserial_open(31, 30, 0, 115200);    // Set up other cog for terminal
 
  drive_speed(0, 0);                          // Start drive system at 0 speed

  // Display user instructions and prompt.  
  dprint(term, "Check Echo On in SimpleIDE Terminal\n\n");
  dprint(term, "f = Forward\nb = Backward\nl = Left\nr = Right\n\n>");

  while(1)                                    // Main loop
  {
    c = fdserial_rxTime(term, 50);            // Get character from terminal
    if(c == 'w') drive_speed(32, 32);         // If 'w' then forward
    if(c == 's') drive_speed(-32, -32);       // If 's' then backward
    if(c == 'a') drive_speed(-32, 32);        // If 'a' then left
    if(c == 'd') drive_speed(32, -32);        // If 'd' then right
    if(c == 'b') drive_speed(0, 0);           // If 'b' then stop
  }  
}