/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */


#ifndef PERSON_H
#define PERSON_H
#include <vector>
#include "Medical_Records.h"
using namespace std;

class Person{
protected:
    Medical_Records *medical_history;

public:
    int age;
    std::string name;
    Person(){}
    Person(int age, string name){
        this->age = age;
        this->name = name;
    }
    int get_age(){ return age; }

    Medical_Records * get_medical_record(){
        return medical_history;
    }


    bool operator== (const Person * other) const{
        if(this->age == other->age && this->name == other->name && this->medical_history == other->medical_history){
            return true;
        }else{
            return false;
        }
    }

};

#endif // PERSON_H