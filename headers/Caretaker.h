/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef CARETAKER_H
#define CARETAKER_H

class Caretaker{
private:
    int service_time;

public:
    Caretaker(){
        service_time = 0;
        random_service();
    }

    virtual void random_service() = 0;

    virtual int get_service_time() = 0;
};

#endif // NURSE_H