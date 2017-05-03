#include "Restaurant.h"

// Default Constructor
Restaurant::Restaurant() {};


// Status of orders and drivers
void Restaurant::status() const {
	// Cooking order status
    cout << "STATUS OF COOKING QUEUE" << endl;
    cout << "Orders in Cooking Queue: " << ordersInCooking << endl << endl; // # of orders in cooking
	
    // Departure order status
    cout << "STATUS OF DEPARTURE QUEUE" << endl;
    cout << "Orders in Departure Queue: " << ordersInDeparture << endl << endl; // # orders in departure
        
    // Drivers and their orders status
	cout << "STATUS OF DELIVERY DRIVERS" << endl;
	for(int i = 0; i < driverVector.size(); i++) {
        cout << "Driver " << i+1 << ": ";                    // driver number
        cout << driverVector[i].toString() << endl;        // name and what driver is doing
		        
        cout << "Tips: " << driverVector[i].getTotalTips() << endl;   // tips
        cout << "Minutes Delivering: " << driverVector[i].getTotalMinDriving() << endl; // drive min
        cout << "Deliveries: " << driverVector[i].getTotalDeliveries() << endl; // deliveries
        
        cout << endl;
	}
    
    cout << endl << endl;
}


// Summary statistics
// * will add more statistics later on...just want to see if this all works first
void Restaurant::summary() const {
    float totalTips = 0, totalDriveMins = 0, totalDeliveries = 0;
    
    for(int i = 0; i < driverVector.size(); i++) {
        totalTips += driverVector[i].getTotalTips();
        totalDriveMins += driverVector[i].getTotalMinDriving();
        totalDeliveries += driverVector[i].getTotalDeliveries();
    }
    
    cout << "\n\n\n\n\n";
    cout << "RESTAURANT SUMMARY" << endl << endl;
    
    // Totals
    cout << "Total tips: \t" << totalTips << endl;
    cout << "Total minutes driving: \t" << totalDriveMins << endl;
    cout << "Total orders delivered: \t"    << totalDeliveries << endl << endl;
    
    // Averages
    cout << "Average tip per driver: \t$" << totalTips / driverVector.size() << endl;
    cout << "Average minutes driving per driver: \t" << totalDriveMins / driverVector.size() << endl;
    cout << "Average deliveries per driver: \t" << totalDeliveries / driverVector.size() << endl << endl;
    
}


// Return Driver object
Driver* Restaurant::getDriver(const string driverName) {
	for(int i = 0; i < driverVector.size(); i++) {
        	if(driverVector[i].getName() == driverName)
                return &driverVector[i];
    }
    
    return nullptr; // if haven't already returned, then driver does not exist
}


// Employ a driver
void Restaurant::addDriver(Driver& driver) {
	driverVector.push_back(driver);
}


// Add order
void Restaurant::addOrder(const Order order) {
	cookingQueue.push(order);
	ordersInCooking++;
}


// Serve next order
void Restaurant::serveNextOrder() throw(logic_error) {
	if (cookingQueue.empty())
		throw logic_error("Error: cooking queue empty; cannot serve another order\n");

	Order readyForDelivery = cookingQueue.front();  // copy order to move it to delivery
	
	cookingQueue.pop();                             // remove readyForDelivery from cookingQueue
	ordersInCooking--;

	departureQueue.push(readyForDelivery);          // push readyForDeliver to departureQueue
	ordersInDeparture++;
}


// Depart next order
// * would do something like:  driverXYZ.depart(currentTime, restaurantZYX.departNextOrder())
Order Restaurant::departNextOrder() throw(logic_error) {
	if (departureQueue.empty())
		throw logic_error("Error: departure queue is empty; cannot deliver an order\n");

	Order oldestOrder = departureQueue.front();
	
	departureQueue.pop();
	ordersInDeparture--;
	
	return oldestOrder;
}

// Select driver to deliver oldest order in departureQueue
Driver* Restaurant::selectDriverToDeliver() throw(logic_error){
    vector<Driver> availableDrivers;
    
    for(int i = 0; i < driverVector.size(); i++) {  // compile list of available drivers
        if(driverVector[i].getDriverState() == 1)
            availableDrivers.push_back(driverVector[i]);
    }
    
    if(!availableDrivers.empty()){    // if there are available drivers
        srand(int(time(NULL)));
        int randIndex = rand() % availableDrivers.size();
        return getDriver(availableDrivers[randIndex].getName());    // Return random but available driver
    }
    
    
    return nullptr; // if haven't already returned, then driver no available drivers
}

