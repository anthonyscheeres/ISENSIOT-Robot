#include "simpletools.h"

int startVal;
int endVal;

int main()
{
  print("Type values for startVal and \n");
  print("endVal.  Press Enter after each one. \n");

  startVal = getDec();
  endVal = getDec();
  putStr("\nCounting from ");
  putDec(startVal);
  putStr(" to ");
  putDec(endVal);
  putStr(".\n");
        
  for (int n = startVal; n <= endVal; n++)
  {
    print("i = %d\n", n);
  }

  print("\nDone!");
  
}
                   
