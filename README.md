# MAY 3, 2017 IN LAB BUGS FOUND - SS
-INPUT-
login David  
order 12:12 pizza with no cheese, bread, or sauce  
serve  
login Byrnes  
order 12:50 pizza with cheese  
depart 13:13 David  
serve  
depart 13:45 Byrnes  
deliver 14:14 David 12.34
deliver 15:00 Byrnes 7.58
arrive 15:15 David
arrive 15:55 Byrnes
logout David
order 16:12 pizza with no cheese
order 16:50 pizza with cheese
serve
login Sommer
status
summary
quit

-OUTPUT-
STATUS OF COOKING QUEUE
Orders in Cooking Queue: 1

STATUS OF DEPARTURE QUEUE
Orders in Departure Queue: 1

STATUS OF DELIVERY DRIVERS
Driver 1: David is logged out.
Tips: 12.34
Minutes Delivering: 61
Deliveries: 1

Driver 2: Byrnes is logged in and at the restaurant.
Tips: 7.58
Minutes Delivering: 61  //This should be 75. Need to distinguish drivers' names.
Deliveries: 1

Driver 1: Sommer is logged in and at the restaurant.
Tips: 0
Minutes Delivering: 0
Deliveries: 0

RESTAURANT SUMMARY

Total tips: 19.92
Total minutes driving: 122 //Should be 116
Total orders delivered: 2

Average tip per driver: $6.64
Average minutes driving per driver: 40.6667  //Wrong because Total minutes driving is not correct
Average deliveries per driver: 0.666667





# MAY 2, 2017 UPDATES - EG

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


# APRIL 28, 2017 - EG
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
