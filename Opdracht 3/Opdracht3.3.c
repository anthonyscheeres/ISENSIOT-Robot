/*
  Met behulp van de ping sensor een LED laten branden, 
  zodra er een object binnen 15 cm aanwezig is.
*/

#include "simpletools.h"                      // Include simpletools
#include "ping.h"                             // Include ping sensor

int main()                                    // main function
{
  while(1)                                    // Endless loop
  {
    int cmDist = ping_cm(8);                 // Get cm distance from Ping)))
    for(int n = 1; n <= 1000; n++);                // Count to ten
    
    print("cmDist = %d\n, n = %d\n", n, cmDist);           // Display distance
    pause(200);                               // Wait 1/5 second
    
    while(ping_cm(8) >= 15);                  // If ping sensor measures object within 15 cm
    {
      high(3);                                // Turn on LED in P3
    }
    while(ping_cm(8) < 15);                   // If ping sensor measures object outside 15 cm
    {
      low(3);                                 // Turn off LED in P3
    }      
  }
}                        
       
// Invoerbereik: 0 of 1
// Sampling rate: ?

/*1. funtie maken met losse meting
 *2. Libraries zoeken voor tijdmetingen
 *3. Meetloop maken (niet oneindig)
 *4. Metingen uitrekenen
 *5. Sample rate printen
 *
 *Sample rate moet effectief zijn, controleren door demo uit te voeren
*/
