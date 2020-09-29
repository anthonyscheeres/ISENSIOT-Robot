/**
 * @file lcdParallel_direction.c
 *
 * @author Matthew Matz, Jeff Martin
 *
 * @version 0.5
 *
 * @copyright
 * Copyright (C) Parallax, Inc. 2018. All Rights MIT Licensed.
 *
 * @brief Display driver for character LCD screens based on Hitachi HD44780 
 * (or compatible) chipsets, which are found in most text-based LCDs. 
 * The library works with either 4 or 8 data lines in addition
 * to the rs, and enable lines.
 */


#include "lcdParallel.h"

// This is for text that flows Left to Right
void lcdParallel_leftToRight(lcdParallel *device) {
  device->_displaymode |= LCDP_ENTRYLEFT;
  lcdParallel_send(device, LCDP_ENTRYMODESET | device->_displaymode, LCDP_SEND_COMMAND);
}

// This is for text that flows Right to Left
void lcdParallel_rightToLeft(lcdParallel *device) {
  device->_displaymode &= ~LCDP_ENTRYLEFT;
  lcdParallel_send(device, LCDP_ENTRYMODESET | device->_displaymode, LCDP_SEND_COMMAND);
}

// This will 'right justify' text from the cursor
void lcdParallel_autoscroll(lcdParallel *device) {
  device->_displaymode |= LCDP_ENTRYSHIFTINCREMENT;
  lcdParallel_send(device, LCDP_ENTRYMODESET | device->_displaymode, LCDP_SEND_COMMAND);
}

// This will 'left justify' text from the cursor
void lcdParallel_noAutoscroll(lcdParallel *device) {
  device->_displaymode &= ~LCDP_ENTRYSHIFTINCREMENT;
  lcdParallel_send(device, LCDP_ENTRYMODESET | device->_displaymode, LCDP_SEND_COMMAND);
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
