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

    bool get_can_admit(){
        return can_admit;
    }

    void set_can_admit(){
        can_admit = !can_admit;
    }

    int get_age(){ return age; }


    void print_medical_record(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        medical_history->print_medical_record();
    }
    


};

#endif // PERSON_H