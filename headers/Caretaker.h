/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef CARETAKER_H
#define CARETAKER_H
#include "Random.h"
using namespace std;

extern Random my_num;

class Caretaker{
protected:
    int service_time;

public:
    Caretaker(){
        service_time = 0;
    }

    virtual void random_service() = 0;

    int get_service_time(){
        return service_time;
    }


};

#endif // CARETAKER_H