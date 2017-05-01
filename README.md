WHAT WE STILL NEED TO ADDRESS
1. Should there be a “cooking process”? If so, how should we do it?

2. Currently we are not using time for anything. Will probably do stuff (like wait times) later on.

3. I need to add more statistics to summary. 
4. I need to figure out a better way to handle what happens when selectDriverToDeliver 

UPDATES (Newest to Oldest)

April 28, 2017
Time.cpp 
+ added to_string for string concatenation in toString function (line35)

Time.h
+ colon @ end of class definition (line 36)

Restaurant.cpp
+ new status function 
+ fixed getDriver function
+ fixed addOrder
+ changed Driver  to Driver* for first parameter type of deliver
+ eliminated deliver function; it is redundant in this class, can just 	use the one in Driver class
+ added selectDriverToDeliver to randomly select available driver
+ made driverVector of pointers so as to access original driver objs
+ made addDriver parameter a pass by address

Restaurant.h
+ (line 34) changed Driver to Driver* return type on getDriver
+ line 59) changed Driver  to Driver* for first parameter type
+ eliminated deliver function; it is redundant in this class, can just 	use the one in Driver class
+ added selectDriverToDeliver to randomly select available driver
