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
		string getName() const;

		//Post: Returns true if and only if the driver is logged in.
		bool isLoggedIn();

		//Post: Returns the total number of completed deliveries.
		int getTotalDeliveries() const;

		//Post: Returns the total minutes spent delivering(i.e., between “depart” and “deliver” commands).
		int getTotalMinDelivering() const;

		//Post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands).
		int getTotalMinDriving() const;

		//Post: Returns the total tips received, in dollars.
		float getTotalTips() const;

		//Pre: Driver is delivering. 
		//Post: Returns the order being delivered.
		Order getOrder() throw (logic_error);

		//Post: Returns a string containing the driver’s name, state (e.g., not logged in), 
		//and, if the driver is delivering an order, the departure time and toString of the order being delivered.
		string toString() const;

		//Post: Gets the state of a driver
		//0:logged out, 1:logged in and at the restaurant
		//2:delivering, 3:driving
		int getDriverState() const;


	private:

		Order currentOrder;
		string nameOfDriver;
		Time departureTime;
		Time deliveryTime;
		Time arrivalTime;
		float TotalTips;
		int numOfDeliveries;
		int TotalMinDelivering;
		int TotalMinDriving;
		int stateOfDriver; //0:logged out, 1:logged in and at the restaurant
						   //2:delivering, 3:driving
};

#endif

