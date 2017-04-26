#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time{
public:
  // Default Time Constructor
  // Pre: none
  // Post: creates Time object with default values
  Time();
  
  // Parametrized Time Constructor
  // Pre: 0 <= hour <= 23 and 0 <= min <= 59
  // Post: creates Time object with given values
  Time(int hr, int min);
  
  // Elapse Time
  // Pre: none
  // Post: returns difference in minutes between t1 and t2
  //       0 minutes <= |t2-t1| <= 1439 minutes
  static int elapseMin(Time t1, Time t2);
  
  // Time in string form
  // Pre: none
  // Post: returns time as string as military time
  string toString();
  
private:
  int hour;
  int minute;
  
}
#endif
