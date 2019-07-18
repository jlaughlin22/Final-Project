/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef NURSE_H
#define NURSE_H
#include "Caretaker.h"
using namespace std;

class Nurse: public Caretaker{
public:
    Nurse(): Caretaker(){
        random_service();
    }

    void random_service(){
        service_time = my_num.random_time(10);
    }
};

#endif // NURSE_H