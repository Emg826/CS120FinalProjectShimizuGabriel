//  Time.cpp
//  IMPLEMENTATION OF TIME CLASS
#include "Time.h"
using namespace std;

// Default Time Constructor
Time::Time(){
  hour = 0;
  minute = 0;
}
  
// Parametrized Time Constructor
Time::Time(int hr, int min){
  hour = hr;
  minute = min;
}
  
// Elapse Time
static int Time::elapseMin(Time t1, Time t2){
  static int t1TotalMin = t1.minute + (t1.hour * 60);
  static int t2TotalMin = t2.minute + (t2.hour * 60);
  
  return t2TotalMin - t1TotalMin;
}
  
// Time in string form
string Time::toString(){
  string currentTime = hour + ":" + t1.minute
      
  return currentTime;
}
