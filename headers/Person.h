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
#include "Medical_Records.h"
using namespace std;

class Person{
private:
    //bool has_record;
    int age;
public:
    std::string name;
    bool can_admit;
    Medical_Records *medical_history;
    Person(int age, string name){
        this->age = age;
        this->name = name;
        can_admit = true;
        //has_record = false;
        medical_history = new Medical_Records();
    }

    Medical_Records * get_med_record(){
        return medical_history;
    }
    
    /* void set_has_record(){
        has_record = !has_record;
    }*/
    
    bool get_can_admit(){
        return can_admit;
    }

    /*bool get_has_record(){
        return has_record;
    }*/

    void set_can_admit(){
        can_admit = !can_admit;
    }

    int get_age(){ return age; }

    


};

#endif // PERSON_H