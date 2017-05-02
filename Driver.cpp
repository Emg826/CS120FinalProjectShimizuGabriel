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
	
	//sets state
	stateOfDriver = 1;
	
}

void Driver::login() throw(logic_error)
{
	if (stateOfDriver == 0)
		stateOfDriver = 1;
	else
		throw logic_error("Driver is already logged in, delivering, or driving.");
	
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
	else
		throw logic_error("Driver is not logged in or at the restaurant.");
		
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
		TotalMinDriving += Time::elapseMin(departureTime, arrivalTime);
	}
	else
		throw logic_error("Driver is not on the way back from a delivery.");
}

string Driver::getName() const
{
	return nameOfDriver;
}

bool Driver::isLoggedIn()
{
	return (stateOfDriver == 1);
}

int Driver::getTotalDeliveries() const
{
	return numOfDeliveries;
}

int Driver::getTotalMinDelivering() const
{
	return TotalMinDelivering;
}

int Driver::getTotalMinDriving() const
{
	return TotalMinDriving;
}

float Driver::getTotalTips() const
{
	return TotalTips;
}

Order Driver::getOrder() throw(logic_error)
{
	if (stateOfDriver == 2)
		return currentOrder;
	else
		throw logic_error("Driver is not delivering");
}

string Driver::toString()
{
	string driverInfo;
	string stateString;

	if (stateOfDriver == 0)
		stateString = " is logged out.";
	if (stateOfDriver == 1)
		stateString = " is logged in and at the restaurant.";
	if (stateOfDriver == 2)
		stateString = " is delivering.\n» Departed at " + departureTime.toString() + " with order..." + currentOrder.toString();
	if (stateOfDriver == 3)
		stateString = " is driving back from a delivery.";

	driverInfo = nameOfDriver + stateString;

	return driverInfo;
}

int Driver::getDriverState() const
{
	return stateOfDriver;
}
