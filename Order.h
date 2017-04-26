// order class header
#ifndef ORDER_H
#define ORDER_H

#include <iostream>


using namespace std;

class Order
{
    public:
        Order();
        Order(Time time, string info);
        void depart() throw (logic_error);
        void deliver(Time time) throw (logic_error);
        int getMinToDelivery() throw (logic_error);
        string toString();

    private:

};

#endif
