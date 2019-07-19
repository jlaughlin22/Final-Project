/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef DOCTOR_H
#define DOCTOR_H
#include "Caretaker.h"
using namespace std;

class Doctor: public Caretaker{
public:
    Doctor(): Caretaker(){
        random_service();
    }

    void random_service(){
        service_time = my_num.random_time(20);
    }
};

#endif // DOCTOR_H