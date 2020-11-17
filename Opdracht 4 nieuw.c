#include "simpletools.h" 
#include "abdrive360.h"

void drive_distance_in_cm(double distanceInCm);
void turn_in_direction_by_degrees(char direction, double degrees);

const double tickDistance = 3.25; // 1 tick = 3.25mm

int main() 
{
  drive_distance_in_cm(16.0);
  pause(500);
  turn_in_direction_by_degrees('r', 60.0);
}

void drive_distance_in_cm(double distanceInCm)
{
  double distanceInMm = distanceInCm * 10; // 50 * 10 = 500mm
  double distanceInTicks = distanceInMm / tickDistance; // 500 : 3.25 = 153.84ticks

  drive_goto(distanceInTicks, distanceInTicks);
  pause(500);
  drive_goto(-distanceInTicks, -distanceInTicks);
}


void turn_in_direction_by_degrees(char direction, double degrees)
{
  const double fullTurnInMm = 664.76; // 360 graden draai in mm

  double turn = degrees / 360.0; // 60 : 360 = 0.166
  double turnDistanceInMm = turn * fullTurnInMm; // 0.166 * 664.76 = 110.35mm
  double turnDistanceInTicks = turnDistanceInMm / tickDistance; // 110.35 : 3.25 = 33.95ticks
  double turnDistancePerWheelInTicks = turnDistanceInTicks / 2.0; // 33.95 : 2 = 16.97ticks

  if(degrees < 61.0) 
  {
    if(direction == 'r') // als richting r, draai rechts 
    {
      drive_goto(turnDistancePerWheelInTicks, -turnDistancePerWheelInTicks); 
      pause(500);
      drive_goto(-turnDistancePerWheelInTicks, turnDistancePerWheelInTicks); 
    }
    if(direction == 'l') // als richting 'l', draai links 
    {
      drive_goto(-turnDistancePerWheelInTicks, turnDistancePerWheelInTicks); 
      pause(500);
      drive_goto(turnDistancePerWheelInTicks, -turnDistancePerWheelInTicks);
    } 
  }
}