#include "simpletools.h"
#include "ping.h"
#include "mstimer.h"

void measure_sensor_for_amount_of_times(int amount_of_times);
  void get_ultrasonic_measurement();
  void get_whiskers_measurement();
  void get_buttons_measurement();

int main()                                    
{
  measure_sensor_for_amount_of_times(1000);
} 
    
void measure_sensor_for_amount_of_times(int amount_of_times)
{
  clock_t start_loop;
  clock_t start_measurement;
  clock_t end_measurement;
  clock_t end_loop;
  
  start_loop = clock();
  
  for(int i = 0; i < amount_of_times; i++)
  {
    start_measurement = clock();

    // get_ultrasonic_measurement();
    // get_whiskers_measurement();
    get_buttons_measurement();          

    end_measurement = clock();
    
    double measurement_duration_in_ms = (end_measurement - start_measurement) * 1000. / CLOCKS_PER_SEC;
    print("measurement_duration_in_ms = %fms\n", measurement_duration_in_ms);
    
    print("\n");
    
    pause(1);
  }
  
  end_loop = clock();
  
  double loop_duration_in_s = (end_loop - start_loop) * 1. / CLOCKS_PER_SEC;
  double average_measurement_duration_in_s = loop_duration_in_s / amount_of_times;
  
  double sample_rate = 1. / average_measurement_duration_in_s;
  
  print("FINAL RESULTS\n");
  print("\n");
  
  print("loop_duration_in_s = %fs\n", loop_duration_in_s);
  print("sample_rate = %fHz\n", sample_rate);
}

void get_ultrasonic_measurement()
{
  int object_distance = ping_cm(8);
}

void get_whiskers_measurement()
{
  int left_whisker = input(9);
  int right_whisker = input(6);
}

void get_buttons_measurement()
{
  int left_button = input(10); 
  int right_button = input(6);                                     
}

