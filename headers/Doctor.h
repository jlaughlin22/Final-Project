/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef DOCTOR_H
#define DOCTOR_H
#include "Random.h"
using namespace std;

Random num;

class Doctor{
private:
    int service_time;

public:
    Doctor(){
        service_time = 0;
    }

    void random_service(){
        service_time = num.random_doc_service();
    }

    int get_service_time(){
        return service_time;
    }


};

#endif // DOCTOR_H