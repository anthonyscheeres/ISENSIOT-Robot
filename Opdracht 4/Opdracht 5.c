#include "simpletools.h" 
#include "abdrive360.h"

void drive_distance_in_cm(double distanceInCm);
void turn_in_direction_by_degrees(char direction, double degrees);
void draw_letter(char letter);

const double tickDistance = 3.25; // 1 tick = 3.25mm

int main() 
{
  draw_letter('s');
  draw_letter('t');
  draw_letter('a');
}

void draw_letter(char letter)
{
  switch(letter)
  {
    case 's':
      drive_distance_in_cm(5.0);
      turn_in_direction_by_degrees('l', 90.0);
      drive_distance_in_cm(5.0);
      turn_in_direction_by_degrees('l', 90.0);
      drive_distance_in_cm(5.0);
      turn_in_direction_by_degrees('r', 90.0);
      drive_distance_in_cm(5.0);
      turn_in_direction_by_degrees('r', 90.0);
      drive_distance_in_cm(5.0);
      break;
    case 't':
      drive_distance_in_cm(10.0);
      turn_in_direction_by_degrees('r', 90.0);
      drive_distance_in_cm(2.0);
      turn_in_direction_by_degrees('r', 90.0);
      drive_distance_in_cm(5.0);
      turn_in_direction_by_degrees('l', 90.0);
      drive_distance_in_cm(8.0);
      break;
    case 'a':
      turn_in_direction_by_degrees('l', 145.0);
      drive_distance_in_cm(12.0);
      turn_in_direction_by_degrees('r', 120.0);
      drive_distance_in_cm(12.0);
      break;
  }  
}

void drive_distance_in_cm(double distanceInCm)
{
  double distanceInMm = distanceInCm * 10; // 50 * 10 = 500mm
  double distanceInTicks = distanceInMm / tickDistance; // 500 : 3.25 = 153.84ticks
  
  drive_goto(distanceInTicks, distanceInTicks);
  drive_goto(-distanceInTicks, -distanceInTicks);
  drive_goto(distanceInTicks, distanceInTicks);
  
  pause(250);
}

void turn_in_direction_by_degrees(char direction, double degrees)  
{
  const double fullTurnInMm = 664.76; // 360 graden draai in mm
  
  double turn = degrees / 360.0; // 60 : 360 = 0.166
  double turnDistanceInMm = turn * fullTurnInMm; // 0.166 * 664.76 = 110.35mm
  double turnDistanceInTicks = turnDistanceInMm / tickDistance; // 110.35 : 3.25 = 33.95ticks
  double turnDistancePerWheelInTicks = turnDistanceInTicks / 2.0; // 33.95 : 2 = 16.97ticks
  
  if(degrees < 181.0) 
  {
    if(direction == 'r')
    {
      drive_goto(turnDistancePerWheelInTicks, -turnDistancePerWheelInTicks); 
    }
    if(direction == 'l')
    {
      drive_goto(-turnDistancePerWheelInTicks, turnDistancePerWheelInTicks); 
    } 
  }
  
  pause(250);
}
