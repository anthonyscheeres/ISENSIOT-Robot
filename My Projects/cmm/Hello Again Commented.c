/*
  Hello Message.c
  
  Display a hello message in the serial terminal. 
  
  http://learn.parallax.com/propeller-c-start-simple/simple-hello-message
*/

#include "simpletools.h"                      // Include simpletools header

int main()                                    // main function
{
  print("Hello!!!\n");                          // Send "hello message"
  print("Hello again!!!");                    // 2nd "hello" message on new line
}
