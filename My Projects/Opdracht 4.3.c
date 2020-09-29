/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/

#include "simpletools.h"                      // Include simple tools
#include "text2speech.h"

int main()                                    // Main function
{
  tts_talk = talk_run(26, 27);
  talk_set_speaker(tts_talk, 1, 100);
  while (1) 
  {
    talk_say(tts_talk, "heloa");
  }
}     
