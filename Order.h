#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Time.h"


using namespace std;

class Order
{
	public:

		//Post: Creates an order with default values for data members.
		Order();

		//Post: Creates an order with the given order time and information. 
		Order(Time time, string info);

		//Pre: Order is at the restaurant. 
		//Post: Order is out for delivery.
		void depart() throw (logic_error);

		//Pre: Order is out for delivery. 
		//Post: Order is delivered.Time to delivery is recorded.
		void deliver(Time time) throw (logic_error);

		//Pre: Order is delivered. 
		//Post: Returns the minutes until the order is delivered(i.e., between “order” and “deliver” commands).
		int getMinToDelivery() throw (logic_error);

		//Post: Returns a string containing the order time and info. 
		string toString();

	private:

		string orderInfo;
		Time orderedTime;
		Time deliveredTime;
		int stateOfOrder; //0:at the restaurant, 1:out for delivery, 2:delivered



};

#endif
