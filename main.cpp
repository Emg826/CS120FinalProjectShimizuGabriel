#include <iostream>

#include "Driver.h"
#include "Order.h"
#include "Restaurant.h"
#include "Time.h"

using namespace std;

int main() {
/*  Test driver - For our personal use   */
    Restaurant myRestaurant;
    
    // Create and add drivers
    Driver driver1("1"), driver2("2"), driver3("3");
    
    myRestaurant.addDriver(driver1);
    myRestaurant.addDriver(driver2);
    myRestaurant.addDriver(driver3);
    
    
    // Create and add orders
    Time testTime1(11,11);
    
    Order order1(testTime1, "Anything but pizza");
    Order order2(testTime1, "Not pizza");
    Order order3(testTime1, "Pizza without the pizza");
    
    myRestaurant.addOrder(order1);
    myRestaurant.addOrder(order2);
    myRestaurant.addOrder(order3);

    myRestaurant.status();  // Should show 3 orders in cooking queue
    
    
    // Move orders from cooking to wait in departure queue
    Time timeToDepart(12,12);
    myRestaurant.serveNextOrder();
    myRestaurant.serveNextOrder();
    myRestaurant.serveNextOrder();
    
    myRestaurant.status(); // Should show 3 orders in departure queue
    
    // Move orders to drivers
    driver1.depart(timeToDepart, myRestaurant.departNextOrder());
    driver2.depart(timeToDepart, myRestaurant.departNextOrder());
    driver3.depart(timeToDepart, myRestaurant.departNextOrder());
        

    myRestaurant.status();  // should show all 3 drivers now have orders
    
    
    // Deliver all 3 orders
    Time timeToDeliver(13,13);
    
    driver1.deliver(timeToDeliver, 10.00);
    driver2.deliver(timeToDeliver, 100.00);
    driver3.deliver(timeToDeliver, 1000.00);
    
    myRestaurant.status();  // should show 3 drivers w/ tips and now driving back
    
    
    // Arrive back at restaurant
    Time timeToArrive(14,14);
    
    driver1.arrive(timeToArrive);
    driver2.arrive(timeToArrive);
    driver3.arrive(timeToArrive);
    
    myRestaurant.status();  // should show drivers back @ restaurant w/ tips
    
    
    
    myRestaurant.summary(); // should show 3 orders, 1110 in tips 

    return 0;
}
