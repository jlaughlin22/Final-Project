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

extern Random my_num;

class Doctor{
private:
    int service_time;

public:
    Doctor(){
        service_time = 0;
        random_service();
    }

    void random_service(){
        service_time = my_num.random_doc_service();
    }

    int get_service_time(){
        return service_time;
    }


};

#endif // DOCTOR_H