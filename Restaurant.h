#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h>
#include <cstring>
#include <queue>
#include <string>
#include "Driver.h"
#include "Order.h"
#include "Time.h"

using namespace std;

class Restaurant {
public:
	// Default Constructor
	// Pre: none
	// Post: creates restaurant in intial state w/out drivers or orders
	Restaurant();

	// Status of orders and drivers
	// Pre: none
	// Post: prints status of orders and logged-in drivers
	void status() const;

	// Summary statistics
	// Pre: none
	// Post: print summary statistics on orders and drivers
	void summary() const;

	// Return Driver name
	// Pre: driver exists (if not, return nullptr)
	// Post: logged in or not, returns pointer to driver
	Driver* getDriver(const string driverName);

	// Employ a driver
	// Pre: none
	// Post: add a driver to the system
	void addDriver(Driver& driver);

	// Add order
	// Pre: none
	// Post: push order to cooking queue
	void addOrder(const Order order);

	// Serve next order
	// Pre: cooking queue not empty
	// Post: removes oldest order from cooking queue; enqueues for delivery
	void serveNextOrder() throw(logic_error);

	// Depart next order
	// Pre: departure queue is not empty
	// Post: removes oldest order from departure queue and returns it
	Order departNextOrder() throw(logic_error);
    
private:
	queue<Order> cookingQueue;
	queue<Order> departureQueue;
	vector<Driver> driverVector;
	
	int ordersInCooking = 0, ordersInDeparture = 0;
};

#endif
