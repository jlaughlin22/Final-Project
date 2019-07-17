/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */


#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include "Current_visit.h"
using std::string;
using std::vector;

class Person{
private:

    bool has_record;
    int age;
public:
    std::string name;
    bool can_admit;
    Person(int age, string name, int clock){
        this->age = age;
        this->name = name;
        can_admit = true;
        has_record = false;
    }
    
    void set_has_record(){
        has_record = !has_record;
    }
    
    bool get_can_admit(){
        return can_admit;
    }

    bool get_has_record(){
        return has_record;
    }

    void set_can_admit(){
        can_admit = !can_admit;
    }

    int get_age(){ return age; }

};

#endif // PERSON_H