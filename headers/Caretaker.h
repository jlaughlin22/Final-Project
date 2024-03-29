/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef CARETAKER_H
#define CARETAKER_H
#include "Random.h"
using namespace std;

extern Random my_num; //Allows access to the global variable defined in Simulation.h 

class Caretaker{//Pure virtual class
protected:
    int service_time;//Holds the service time of the caretaker
public:

    /**
     * Constructor
     */
    Caretaker(){
        service_time = 0;//sets service time to 0
    }


    /**
     * Pure virtual method all subclasses must implement
     */
    virtual void random_service() = 0;

    /**
     * Returns the service time of the caretaker
     */
    int get_service_time(){
        return service_time;
    }


};

#endif // CARETAKER_H