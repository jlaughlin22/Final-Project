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
    Medical_Records *medical_history;//Pointer to this persons medical records

public:
    int age;//Holds age
    string name;//Holds name

    /**
     * Empty Constructor
     */
    Person(){}

    /**
     * Constructor of Person
     */
    Person(int age, string name){
        this->age = age;//Sets value of age
        this->name = name;//Sets value of name
    }

    /**
     * Returns a pointer to the medical history of this person
     */
    Medical_Records * get_medical_record(){
        return medical_history;
    }

    /**
     * Overload of ==
     * Determines if this person is equal to the other person
     */
    bool operator== (const Person * other) const{
        if(this->age == other->age && this->name == other->name && this->medical_history == other->medical_history){//if name age and medical history are same then same person
            return true;
        }else{
            return false;
        }
    }

};

#endif // PERSON_H