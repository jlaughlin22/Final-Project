/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
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
    bool can_admit;
    //Medical_Records *medical_history;
    Person(){}
    Person(int age, string name){
        this->age = age;
        this->name = name;
        can_admit = true;
        //has_record = false;
        //medical_history = new Medical_Records();
    }

    bool get_can_admit(){
        return can_admit;
    }

    void set_can_admit(){
        if(can_admit == true){
            can_admit = false;
        }else if(can_admit == false){
            can_admit = true;
        }
    }

    int get_age(){ return age; }

    Medical_Records * get_medical_record(){
        return medical_history;
    }
    

};

#endif // PERSON_H