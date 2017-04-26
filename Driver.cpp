#include "Driver.h"

Driver::Driver(string name)
{
	//sets name
	nameOfDriver = name;

	//Initializes stats
	TotalTips = 0;
	numOfDeliveries = 0;
	TotalMinDelivering = 0;
	TotalMinDriving = 0;
	
	//sets state: 0 for logged out, 1 for logged in and waiting, 2 for delivering
	stateOfDriver = 1;
	
}

void Driver::login() throw(logic_error)
{
	if (stateOfDriver == 1)
		throw logic_error("Driver is already logged in.");
	else
		stateOfDriver = 1;
}

void Driver::logout() throw(logic_error)
{
	if (stateOfDriver == 1)
		stateOfDriver--;
	else
		throw logic_error("Driver is not logged in and at the restaurant.");
}

void Driver::depart(Time time, Order o) throw(logic_error)
{
	if (stateOfDriver == 1)
	{
		stateOfDriver = 2;
		departureTime = time;
		currentOrder = o;
	}
		
}

void Driver::deliver(Time time, float tip) throw(logic_error)
{
	if (stateOfDriver != 2 || tip < 0)
		throw logic_error("Driver is not delivering or tip is negative.");
	else
	{
		numOfDeliveries++;
		stateOfDriver = 3;
		deliveryTime = time;
		TotalTips += tip;
		TotalMinDelivering += Time::elapseMin(departureTime, deliveryTime);
	}
}

void Driver::arrive(Time time) throw(logic_error)
{
	if (stateOfDriver == 3)
	{
		stateOfDriver = 1;
		arrivalTime = time;
		TotalMinDriving += Time::elapseMin(deliveryTime, arrivalTime);
	}
	else
		throw logic_error("Driver is not on the way back from a delivery.");
}

string Driver::getName()
{
	return nameOfDriver;
}

bool Driver::isLoggedIn()
{
	return (stateOfDriver == 1);
}

int Driver::getTotalDeliveries()
{
	return numOfDeliveries;
}

int Driver::getTotalMinDelivering()
{
	return TotalMinDelivering;
}

int Driver::getTotalMinDriving()
{
	return TotalMinDriving;
}

float Driver::getTotalTips()
{
	return TotalTips;
}

Order Driver::getOrder() throw(logic_error)
{
	if(stateOfDriver == 2)
		return currentOrder;
}

string Driver::toString()
{
	string driverInfo;
	string stateString;

	if (stateOfDriver == 0)
		stateString = "logged out.";
	if (stateOfDriver == 1)
		stateString = "logged in and at the restaurant.";
	if (stateOfDriver == 2)
		stateString = "delivering, " + departureTime.toString() + ", " + currentOrder.toString() + ".";
	if (stateOfDriver == 3)
		stateString = "driving back from a delivery.";

	driverInfo = nameOfDriver + stateString;

	return driverInfo;
}
