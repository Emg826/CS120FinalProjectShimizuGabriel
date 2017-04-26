#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include "Time.h"
#include "Order.h"


using namespace std;

class Driver
{
	public:
		//Post: Creates a logged-in driver with the given name.
		Driver(string name);

		//Pre: Driver is not logged in. 
		//Post: Logs the driver in.
		void login() throw (logic_error);

		//Pre: Driver is logged in and at the restaurant. 
		//Post: Logs the driver out.
		void logout() throw (logic_error);

		//Pre: Driver is logged in and at the restaurant. 
		//Post: Driver is delivering.Departure time is recorded.
		void depart(Time time, Order o) throw (logic_error);

		//Pre: Driver is delivering, tip >= 0. 
		//Post: Driver is not delivering.Driver’s stats are updated.
		void deliver(Time time, float tip) throw (logic_error);

		//Pre: Driver is driving but not delivering. 
		//Post: Driver is at the restaurant.Driver’s stats are updated.
		void arrive(Time time) throw (logic_error);

		//Post: Returns the driver’s name. 
		string getName();

		//Post: Returns true if and only if the driver is logged in.
		bool isLoggedIn();

		//Post: Returns the total number of completed deliveries.
		int getTotalDeliveries();

		//Post: Returns the total minutes spent delivering(i.e., between “depart” and “deliver” commands).
		int getTotalMinDelivering();

		//Post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands).
		int getTotalMinDriving();

		//Post: Returns the total tips received, in dollars.
		float getTotalTips();

		//Pre: Driver is delivering. 
		//Post: Returns the order being delivered.
		Order getOrder() throw (logic_error);

		//Post: Returns a string containing the driver’s name, state (e.g., not logged in), 
		//and, if the driver is delivering an order, the departure time and toString of the order being delivered.
		string toString();


	private:

};

#endif
