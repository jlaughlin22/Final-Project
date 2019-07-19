/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef NURSE_H
#define NURSE_H
#include "Caretaker.h"
using namespace std;

class Nurse: public Caretaker{//Public Caretake Nurse is a caretaker
public:

    /**
     * Constructor
     * When made creates a random service time for this instance
     */
    Nurse(): Caretaker(){
        random_service();
    }

    /**
     * Random service time for patient ie how long takes this nurse to treat the patient
     */
    void random_service(){
        service_time = my_num.random_time(10);//random value between 1 and 10
    }
};

#endif // NURSE_H