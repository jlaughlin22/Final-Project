/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef NURSE_H
#define NURSE_H
#include "Random.h"
using namespace std;

extern Random my_num;

class Nurse{
private:
    int service_time;

public:
    Nurse(){
        service_time = 0;
        random_service();
    }

    void random_service(){
        service_time = my_num.random_nurse_service();
    }

    int get_service_time(){
        return service_time;
    }

};

#endif // NURSE_H