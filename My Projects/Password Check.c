/*
 Password Check.c
*/

#include "simpletools.h"

char text[16];
char pass[7] = {"abc 123"};

int main()
{
  print("Enter password: ");
  
  for(int i = 0; i < 16; i++)
  {
    text[i] = getChar();
    putChar('*');
    if(text[i] == '\r' || text[i] == '\n')
    {
      putChar('\n');
      text[i] = 0;
      break;
    }
  }        
  
  if(!strcmp(pass, text))
  {
    print("(pass does match text)\n");
  }
  else
  {
    print("(pass DOES NOT match text)\n"); 
  }
}   