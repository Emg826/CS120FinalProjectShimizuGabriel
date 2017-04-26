//Driver.h
#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>


using namespace std;

class Driver
{
    public:
        Driver(string name);
        void login() throw (logic_error);
        void logout() throw (logic_error);
        void depart(Time time, Order o) throw (logic_error);
        void deliver(Time time, float tip) throw (logic_error);
        void arrive(Time time) throw (logic_error);
        string getName();
        bool isLoggedIn();
        int getTotalDeliveries();
        int getTotalMinDelivering();
        int getTotalMinDriving();
        float getTotalTips();
        Order getOrder() throw (logic_error);
        string toString();


    private:

};

#endif
