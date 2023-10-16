/*
  Original code sourced from theorycircuit.com
  Some code and wiring inspired by arduino.cc
*/

#include <openGLCD.h>
#include <bitmaps/BITMAP.1.h>
#define DELAY 2000 // ms delay between examples
void setup()
{
  GLCD.Init();
}
void loop()
{
  GLCD.ClearScreen();
  /*
     Display photo centered on Display
  */
  GLCD.DrawBitmap(_BITMAP.1, GLCD.Width/4 - 32, 0);
  delay(DELAY);

}
