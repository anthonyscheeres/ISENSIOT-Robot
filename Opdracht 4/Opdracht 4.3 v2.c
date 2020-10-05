/*
  Test WAV Volume.c

  Play back a .wav file and try a few different volume settings.   
  
  http://learn.parallax.com/propeller-c-simple-devices/play-wav-files
*/

#include "simpletools.h"
#include "wavplayer.h"

void deuntje(char bestandsNaam[], int volume, int looptijd);
    
int main()
{
  int DO = 22, CLK = 23, DI = 24, CS = 25;
  sd_mount(DO, CLK, DI, CS);
  
  char fluitSignaal1[] = "melodie.wav";
  char fluitSignaal2[] = "akkoord.wav";
  char nederlandsWoord1[] = "klinklar.wav";
  char nederlandsWoord2[] = "allekast.wav";
   
  deuntje(fluitSignaal1, 4, 8900);
  deuntje(fluitSignaal2, 4, 8900);
  deuntje(nederlandsWoord1, 5, 2900);
  deuntje(nederlandsWoord2, 5, 2900);
}

void deuntje(char bestandsNaam[], int volume, int looptijd) {
  wav_play(bestandsNaam);
 
  wav_volume(volume);
  pause(looptijd);

  wav_stop(); 
}