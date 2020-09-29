/*
  Get Text.c
*/

#include "simpletools.h"                      // Include simpletools library

char text[16];                                // Declare character array

int main()                                    // Main function
{
  print("Enter some text: ");                 // User prompt

  getStr(text, 15);                           // Tet string, max 15 characters

  print("You typed: %s \n", text);            // Display the characters
}