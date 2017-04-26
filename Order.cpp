#include <string>
#include "Order.h"

Order::Order()
{
	stateOfOrder = 0;
}

Order::Order(Time time, string info)
{
	stateOfOrder = 0;
	orderedTime = time;
	orderInfo = info;
}

void Order::depart() throw(logic_error)
{
	if (stateOfOrder == 0)
		stateOfOrder++;
	else
		throw logic_error("Order is not at the restaurant.");
}

void Order::deliver(Time time) throw(logic_error)
{
	if (stateOfOrder == 1)
	{
		stateOfOrder++;
		deliveredTime = time;
	}
	else
		throw logic_error("Order is not out for delivery.");
}

int Order::getMinToDelivery() throw(logic_error)
{
	if (stateOfOrder == 2)
	{
		return Time::elapseMin(deliveredTime, orderedTime);
	}
	else
		throw logic_error("Order is not delivered.");
}

string Order::toString()
{
	string timeAndInfo = orderedTime.toString() + orderInfo;
	return timeAndInfo;
}
