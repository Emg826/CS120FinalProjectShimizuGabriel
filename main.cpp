#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>

#include "Driver.h"
#include "Order.h"
#include "Restaurant.h"
#include "Time.h"

// Activate TEST_n by switching from 0 to 1
#define TEST_1  1
#define TEST_2  0

using namespace std;

int main() {
/*  Test driver - For our personal use   */
/*
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
    
    // Move the 3 orders to drivers
    while(myRestaurant.selectDriverToDeliver() != nullptr)
        myRestaurant.selectDriverToDeliver()->depart(timeToDepart, myRestaurant.departNextOrder());


    
    
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

    */
    
    // Test interface
    
    ifstream testFile;
    
    #if TEST_1
        testFile.open("TEST_1.txt");
    #else // TEST_2
        testFile.open("TEST_2.txt");
    #endif
    
    if(!testFile){       // if file does not open
        cerr << "\n***Error opening the test file" << endl;
        return -1;
    }
    
    
    Restaurant PizzaPlanet;
    
    // Read in from .txt
    string readIn;
    while(!testFile.eof()){
        
        testFile >> readIn;     // read in command (login, order, serve, etc.)
        
        if(readIn == "login"){
            testFile >> readIn;                         // read in name
            
            if(PizzaPlanet.getDriver(readIn) != nullptr)
                PizzaPlanet.getDriver(readIn)->login();
                
            else{
                Driver newDriver(readIn);
                PizzaPlanet.addDriver(newDriver);
            }
        }
    
        else if(readIn == "logout"){
            testFile >> readIn;                         // read in name
            PizzaPlanet.getDriver(readIn)->logout();    // logout that driver
        }
        
        else if(readIn == "order"){
            testFile >> readIn;                         // read in time
            
            int hour, minute;
            // http://stackoverflow.com/questions/24270236/how-to-convert-formatted-string-hhmmss-to-seconds-in-c
            sscanf(readIn.c_str(), "%i:%i", &hour, &minute);    // convert time to ints
            Time orderTime(hour, minute);

            string orderInfo;
            getline(testFile, orderInfo);
            
            Order newOrder(orderTime, orderInfo);
            PizzaPlanet.addOrder(newOrder);
        }
        
        else if(readIn == "serve"){
            PizzaPlanet.serveNextOrder();       // serve next order
        }

        else if(readIn == "depart"){
            testFile >> readIn;                 // read in time
            
            int hour, minute;
            sscanf(readIn.c_str(), "%i:%i", &hour, &minute);    // convert time to ints
            Time departTime(hour, minute);

            testFile >> readIn;                 // read in name
            PizzaPlanet.getDriver(readIn)->depart(departTime, PizzaPlanet.departNextOrder());
        }
        
        else if(readIn == "deliver"){
            testFile >> readIn;                 // read in time
            
            int hour, minute;
            sscanf(readIn.c_str(), "%i:%i", &hour, &minute);    // convert time to ints
            Time deliverTime(hour, minute);
            
            float tip;
            testFile >> readIn >> tip;
            PizzaPlanet.getDriver(readIn)->deliver(deliverTime, tip);
        }
        
        else if(readIn == "arrive"){
            testFile >> readIn;                 // read in time
            
            int hour, minute;
            sscanf(readIn.c_str(), "%i:%i", &hour, &minute);    // convert time to ints
            Time arrivalTime(hour, minute);
            
            testFile >> readIn;
            
            PizzaPlanet.getDriver(readIn)->arrive(arrivalTime);
        }

        else if(readIn == "status")
            PizzaPlanet.status();

        else if(readIn == "summary")
            PizzaPlanet.summary();

        else if(readIn == "quit")
            break;
    }
        
    testFile.close();
	return 0;
}
