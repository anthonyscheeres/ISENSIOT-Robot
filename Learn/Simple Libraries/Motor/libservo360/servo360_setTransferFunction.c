/*
  @file servo360_setControlSys.c

  @author Parallax Inc

  @copyright
  Copyright (C) Parallax Inc. 2017. All Rights MIT Licensed.  See end of file.
 
  @brief 
*/


#include "simpletools.h"  
#include "servo360.h"

int servo360_setTransferFunction(int pin, int constant, int value)
{
  if(!_fb360c.servoCog) servo360_run();
  int p = servo360_findServoIndex(pin);
  if(p == -1)return -1;
  
  switch(constant)
  {
    case S360_SETTING_VM_CCW:
      _fs[p].vmCcw = value;
      break;
    case S360_SETTING_VM_CW:
      _fs[p].vmCw = value;
      break;
    case S360_SETTING_VB_CCW:
      _fs[p].vbCcw = value;
      break;
    case S360_SETTING_VB_CW:
      _fs[p].vbCw = value;
      break;
  } 
  return p; 
}    


/**
 * TERMS OF USE: MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
