<header>MAY 2, 2017 UPDATES - EG</header>
Great news: main.cpp with TEST_1.txt now fully works! Woohoo!
We still have a bit to do, but the project is really coming along!

Feel free to look over and/or change anything I added. 

I still need to add some interesting statistics to summary function, but 
otherwise, I think that we are close to being done. Just a few more 
things like writing a better TEST_1.txt and a writing a TEST_2.txt.

In a bit more detail, wrote main(), changed up some of the toString()
output messages, changed driverVector<Driver*> back to driverVector<Driver>,
and a few other things. Those are the main ones, though, that you might
want to look over.


APRIL 28, 2017 - EG
WHAT WE STILL NEED TO ADDRESS
1. Should there be a “cooking process”? If so, how should we do it?

2. Currently we are not using time for anything. Will probably do stuff (like wait times) later on.

3. I need to add more statistics to summary. 
4. I need to figure out a better way to handle what happens when selectDriverToDeliver 

UPDATES (Newest to Oldest)

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
