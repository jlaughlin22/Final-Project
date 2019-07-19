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

class Doctor: public Caretaker{//Public Caretaker Doctor is a caretaker
public:

    /**
     * Constructor
     * When made creates a random service time for this instance
     */
    Doctor(): Caretaker(){
        random_service();
    }

    /**
     * Random service time for patient (ie how long takes this doctor to treat the patient)
     */
    void random_service(){
        service_time = my_num.random_time(20);//random value between 1 and 20
    }
};

#endif // DOCTOR_H