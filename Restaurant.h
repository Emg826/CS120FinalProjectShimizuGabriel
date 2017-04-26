//
//  Restaurant.hpp
//  
//
//  Created by Eric G on 4/26/17.
//
//

#ifndef Restaurant_hpp
#define Restaurant_hpp

#include <stdio.h>
#include <cstring>

using namespace std;

class Restaurant{
public:
    // Default Constructor
    // Pre: none
    // Post: creates restaurant in intial state w/out drivers or orders
    Restaurant();
    
    // Status of orders and drivers
    // Pre: none
    // Post: prints status of orders and logged-in drivers
    void status();
    
    // Summary statistics
    // Pre: none
    // Post: print summary statistics on orders and drivers
    void summary();
    
    // Return Driver name
    // Pre: driver exists (if not, return nullptr)
    // Post: logged in or not, returns pointer to driver
    Driver* getDriver(string driverName);
    
    // Employ a driver
    // Pre: none
    // Post: add a driver to the system
    void addDriver(Driver* driver);
    
    // Add order
    // Pre: none
    // Post: push order to cooking queue
    void addOrder(Order* order);
    
    // Serve next order
    // Pre: cooking queue not empty
    // Post: removes oldest order from cooking queue; enqueues for delivery
    void serveNextOrder() throw(logic_error);
    
    // Depart next order
    // Pre: none
    // Post: removes oldest order from departure queue and returns it
    Order* departNextOrder() throw(logic_error);
    
    // Deliver order
    // Pre: none
    // Post: order carried by driver delivered @ given time; drive gets tip
    void deliver(Driver* driver, Time time, float tip);
    
    
    
private:
    
};

#endif
