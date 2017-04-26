#include "Restaurant.h"

// Default Constructor
Restaurant::Restaurant() {};

// Status of orders and drivers
// Pre: none
// Post: prints status of orders and logged-in drivers
void Restaurant::status() {

}

// Summary statistics
// Pre: none
// Post: print summary statistics on orders and drivers
void Restaurant::summary() {

}

// Return Driver name
// Pre: driver exists (if not, return nullptr)
// Post: logged in or not, returns pointer to driver
Driver Restaurant::getDriver(string driverName) {

}

// Employ a driver
void Restaurant::addDriver(Driver driver) {
	driverVector.push_back(driver);
}

// Add order
void Restaurant::addOrder(Order order) {
	cookingQueue.push(order);
}

// Serve next order
// Pre: cooking queue not empty
// Post: removes oldest order from cooking queue; enqueues for delivery
void Restaurant::serveNextOrder() throw(logic_error) {
	if (cookingQueue.empty())
		throw logic_error("Error: cooking queue empty; cannot serve another order");

	Order readyForDelivery = cookingQueue.front();  // Copy order to move it to delivery
	cookingQueue.pop();                             // Remove readyForDelivery from cookingQueue
	departureQueue.push(readyForDelivery);           // Push readyForDeliver to departureQueue
}

// Depart next order
// Pre: none
// Post: removes oldest order from departure queue and returns it
Order Restaurant::departNextOrder() throw(logic_error) {
	if (departureQueue.empty())
		throw logic_error("Error: departure queue is empty; cannot deliver an order");

	Order oldestOrder = departureQueue.front();
	departureQueue.pop();

	// need way to select driver to deliver

	return oldestOrder;
}

// Deliver order
// Pre: none
// Post: order carried by driver delivered @ given time; driver gets tip
void Restaurant::deliver(Driver driver, Time time, float tip) {
	Driver driverInVector = getDriver(driver.getName());


}
