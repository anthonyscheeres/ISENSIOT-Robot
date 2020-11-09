#include "simpletools.h" 
#include "abdrive.h"
#include "ping.h"

void drive_distance_in_cm(double distanceInCm);
void turn_in_direction_by_degrees(char direction, double degrees);

const double tickDistance = 3.25; // 1 tick = 3.25mm

int main()
{
  int closest_object_distance = 330;
  int position_of_closest_object_in_degrees;
  
  while (1)
  {
    for(int i = 0; i < 6; i++)
    {
      turn_in_direction_by_degrees('r', 20);
      pause(500);
      int object_distance = ping_cm(8);
      int current_position_in_degrees = (i * 20) + 20;
      
      print("object distance at %d = %d\n", current_position_in_degrees, object_distance);
      
      if (object_distance < closest_object_distance)
      {
        closest_object_distance = object_distance;
        position_of_closest_object_in_degrees = current_position_in_degrees;
        print("the closest object distance = %d\n", closest_object_distance);
      }      
      
      pause(500);
    }
    
    int degrees_to_turn_back_to_closest_object = 120 - position_of_closest_object_in_degrees;
    int total_drive_distance = closest_object_distance + 5;
  
    turn_in_direction_by_degrees('l', degrees_to_turn_back_to_closest_object);
    drive_distance_in_cm(total_drive_distance);
    turn_in_direction_by_degrees('l', position_of_closest_object_in_degrees);
    
    closest_object_distance = 330;
    position_of_closest_object_in_degrees = 0;
    pause(1000);
  }  
}

void drive_distance_in_cm(double distanceInCm)
{
  double distanceInMm = distanceInCm * 10; // 50 * 10 = 500mm
  double distanceInTicks = distanceInMm / tickDistance; // 500 : 3.25 = 153.84ticks
  
  drive_goto(distanceInTicks, distanceInTicks);
  drive_goto(-distanceInTicks, -distanceInTicks);
  
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