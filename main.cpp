#include <iostream>
#include <sstream>
#include <ctime>
#include <fstream>

#include "Driver.h"
#include "Order.h"
#include "Restaurant.h"
#include "Time.h"

//
// ACTIVATE TEST_n BY SWITCHING FROM 0 to 1
//
#define TEST_1  0
#define TEST_2  1

using namespace std;

int main() {
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
