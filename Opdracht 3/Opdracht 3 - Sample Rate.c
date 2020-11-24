#include "simpletools.h"                      
#include "abdrive.h"
#include "ping.h"
#include <sys/time.h>
#include <float.h>

void measure_ultrasonic_for_amount_of_times(int amount_of_times);
void measure_whiskers_for_amount_of_times(int amount_of_times);
void measure_buttons_for_amount_of_times(int amount_of_times);

int main()                                    
{
  // measure_ultrasonic_for_amount_of_times(100);
  measure_whiskers_for_amount_of_times(100);
  // measure_buttons_for_amount_of_times(100);
}

void measure_ultrasonic_for_amount_of_times(int amount_of_times)
{
  double single_measurement_duration_in_seconds = 0;
  double full_measurement_duration_in_seconds = 0;
  
  
  for(int i = 0; i < amount_of_times; i++)
  {
    struct timeval start, stop;

    gettimeofday(&start, NULL);

    int object_distance = ping_cm(8);                
    print("object_distance = %dcm\n", object_distance); 
    pause(20);                                         

    gettimeofday(&stop, NULL);
    
    single_measurement_duration_in_seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    print("single_measurement_duration_in_seconds = %fs\n", single_measurement_duration_in_seconds);
  
    int sample_rate = (1 / single_measurement_duration_in_seconds);
    print("sample_rate = %dHz\n", sample_rate);
    
    full_measurement_duration_in_seconds+= single_measurement_duration_in_seconds;
    print("full_measurement_duration_in_seconds = %fs\n", full_measurement_duration_in_seconds);
    print("\n");
  }
  
  print("full_measurement_duration_in_seconds = %fs\n", full_measurement_duration_in_seconds);
  
  double effective_sample_rate = 1 / (full_measurement_duration_in_seconds / amount_of_times);
  print("effective_sample_rate = %fHz\n", effective_sample_rate);
}    
    
void measure_whiskers_for_amount_of_times(int amount_of_times)
{
  float single_measurement_duration_in_seconds = 0;
  float full_measurement_duration_in_seconds = 0;
  
  for(int i = 0; i < amount_of_times; i++)
  {
    struct timeval start, stop;

    gettimeofday(&start, NULL);

    int left_whisker = input(9);
    int right_whisker = input(6);
    print("left_whisker = %d\n", left_whisker); 
    print("right_whisker = %d\n", right_whisker);                                                     

    gettimeofday(&stop, NULL);
    
    single_measurement_duration_in_seconds = (float)(stop.tv_usec - start.tv_usec) / 1000000 + (float)(stop.tv_sec - start.tv_sec);
    print("single_measurement_duration_in_seconds = %fs\n", single_measurement_duration_in_seconds);
  
    int sample_rate = (1 / single_measurement_duration_in_seconds);
    print("sample_rate = %dHz\n", sample_rate);
    
    full_measurement_duration_in_seconds+= single_measurement_duration_in_seconds;
    print("full_measurement_duration_in_seconds = %fs\n", full_measurement_duration_in_seconds);
    print("\n");
  }
  
  print("full_measurement_duration_in_seconds = %fs\n", full_measurement_duration_in_seconds);
  
  float effective_sample_rate = 1 / (full_measurement_duration_in_seconds / amount_of_times);
  print("effective_sample_rate = %fHz\n", effective_sample_rate);
}

void measure_buttons_for_amount_of_times(int amount_of_times)
{
  double single_measurement_duration_in_seconds = 0;
  double full_measurement_duration_in_seconds = 0;
  
  for(int i = 0; i < amount_of_times; i++)
  {
    struct timeval start, stop;

    gettimeofday(&start, NULL);

    int button1 = input(10);
    int button2 = input(6); 
    print("button1 = %d\n", button1); 
    print("button2 = %d\n", button2);                                                     

    gettimeofday(&stop, NULL);
    
    single_measurement_duration_in_seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    print("single_measurement_duration_in_seconds = %fs\n", single_measurement_duration_in_seconds);
  
    int sample_rate = (1 / single_measurement_duration_in_seconds);
    print("sample_rate = %dHz\n", sample_rate);
    
    full_measurement_duration_in_seconds+= single_measurement_duration_in_seconds;
    print("full_measurement_duration_in_seconds = %fs\n", full_measurement_duration_in_seconds);
    print("\n");
  }
  
  print("full_measurement_duration_in_seconds = %fs\n", full_measurement_duration_in_seconds);
  
  double effective_sample_rate = 1 / (full_measurement_duration_in_seconds / amount_of_times);
  print("effective_sample_rate = %fHz\n", effective_sample_rate);
}