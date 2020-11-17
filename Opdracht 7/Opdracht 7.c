#include "simpletools.h" 
#include "abdrive360.h"
#include "ping.h"

void scan_area_in_degrees_by_amount_of_turns(double area_in_degrees, int amount_of_turns);
int measure_object_distance();
void drive_distance_in_cm(double distanceInCm);
void turn_in_direction_by_degrees(char direction, double degrees);

const double tickDistance = 3.25; // 1 tick = 3.25mm

int main()
{
  while(1)
  {  
    scan_area_in_degrees_by_amount_of_turns(120, 12);
  }  
}

void scan_area_in_degrees_by_amount_of_turns(double area_in_degrees, int amount_of_turns)
{
  double degrees_per_turn = area_in_degrees / amount_of_turns;
  print("degrees per turn = %f\n", degrees_per_turn);
  
  int object_distance;
  
  int closest_object_distance = measure_object_distance();
  double closest_object_position_in_degrees = 0;
  print("the closest object distance = %d at %f degrees\n", closest_object_distance, closest_object_position_in_degrees);
  
  int furthest_object_distance = 0;
  print("the furthest object distance = %d\n", furthest_object_distance);
  
  for(int i = 0; i < amount_of_turns; i++)
  {
    turn_in_direction_by_degrees('r', degrees_per_turn);
    object_distance = measure_object_distance();
    
    if(object_distance < closest_object_distance)
    {
      closest_object_distance = object_distance;
      closest_object_position_in_degrees = (i * degrees_per_turn) + degrees_per_turn;
      print("the closest object distance = %d at %f degrees\n", closest_object_distance, closest_object_position_in_degrees);
    }
    
    if(object_distance > furthest_object_distance && object_distance < 200)
    {
      furthest_object_distance = object_distance;
      print("the furthest object distance = %d\n", furthest_object_distance);
    }
  }
  
  int closest_object_position_in_turns = closest_object_position_in_degrees / degrees_per_turn;
  int amount_of_turns_back_to_closest_object = amount_of_turns - closest_object_position_in_turns;
  
  for(int i = 0; i < amount_of_turns_back_to_closest_object; i++)
  {
    turn_in_direction_by_degrees('l', degrees_per_turn);
  }  
  
  drive_distance_in_cm(furthest_object_distance);
  
  int amount_of_turns_back_to_base_position = amount_of_turns - amount_of_turns_back_to_closest_object;
  
  for(int i = 0; i < amount_of_turns_back_to_base_position; i++)
  {
    turn_in_direction_by_degrees('l', degrees_per_turn);
  }  
  
  // turn_in_direction_by_degrees('l', area_in_degrees - closest_object_position_in_degrees);
  // drive_distance_in_cm(furthest_object_distance);
  // turn_in_direction_by_degrees('l', closest_object_position_in_degrees);
}

int measure_object_distance()
{
  int object_distance = ping_cm(8);
  
  return object_distance;
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