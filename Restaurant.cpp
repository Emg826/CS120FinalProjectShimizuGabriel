#include "Restaurant.h"

// Default Constructor
Restaurant::Restaurant() {};


// Status of orders and drivers
// Pre: none
// Post: prints status of orders and logged-in drivers
void Restaurant::status() {
	// Cooking order status
    	cout << "Orders in Cooking Queue Status: " << ordersInCooking << endl;
	
        // Departure order status
        cout << "Orders in Departure Queue Status: " << ordersInDeparture << endl;
        
        // Driver and their orders status 
	cout << "Driver Status: " << end;
	int loginStatus, 
	for(int i = 0; i < driverVector.size(); i++){
		   cout << driverVector[i].getName()
			<< driverVecto
			<< :
	}
}


// Summary statistics
// Pre: none
// Post: print summary statistics on orders and drivers
void Restaurant::summary() {
	// print 

}


// Return Driver object
Driver& Restaurant::getDriver(string driverName) {    
	for(int i = 0; i < driverVector.size(); i++) {
        	if(driverVector[i].getName() == driverName)
			return &driverVector[i];
    }
    
    // If haven't already returned, then driver does not exist
    return nullptr;
}


// Employ a driver
void Restaurant::addDriver(Driver driver) {
	driverVector.push_back(driver);
}


// Add order
void Restaurant::addOrder(Order order) {
	cookingQueue.push(order);
	ordersInCookingQueue++;
}


// Serve next order
// Pre: cooking queue not empty
// Post: removes oldest order from cooking queue; enqueues for delivery
void Restaurant::serveNextOrder() throw(logic_error) {
	if (cookingQueue.empty())
		throw logic_error("Error: cooking queue empty; cannot serve another order");

	Order readyForDelivery = cookingQueue.front();  // Copy order to move it to delivery
	
	cookingQueue.pop();                             // Remove readyForDelivery from cookingQueue
	ordersInCookingQueue--;

	departureQueue.push(readyForDelivery);           // Push readyForDeliver to departureQueue
	ordersInDeparture++;
}


// Depart next order
// Pre: none
// Post: removes oldest order from departure queue and returns it
Order Restaurant::departNextOrder() throw(logic_error) {
	if (departureQueue.empty())
		throw logic_error("Error: departure queue is empty; cannot deliver an order");

	Order oldestOrder = departureQueue.front();
	
	departureQueue.pop();
	ordersInDeparture--;
	
	// need way to select driver to deliver
	return oldestOrder;
}


// Deliver order
// Pre: none
// Post: order carried by driver delivered @ given time; driver gets tip
void Restaurant::deliver(Driver driver, Time time, float tip) {
	Driver driverWhoDelivered = getDriver(driver.getName());
	
	


}
