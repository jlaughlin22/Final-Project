/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */


#ifndef PATIENT_H
#define PATIENT_H
#include <vector>
#include "Person.h"
#include "Current_visit.h"
using namespace std;

class Patient: public Person{
private:
    int arrival_time;
    int discharge_time;
    Current_Visit * visit;
    Person * person;
public:
    Patient(int clock, string name, int age): Person(age, name){
        arrival_time = clock;
        discharge_time = -1;
        visit = new Current_Visit(arrival_time);
        medical_history = new Medical_Records();

    }

    Patient(int clock, Person * person){
        this->person = person;
        arrival_time = clock;
        discharge_time = -1;
        visit = new Current_Visit(arrival_time);
        medical_history = person->get_medical_record();

    }

    Current_Visit * get_visit(){
        return visit;
    }

	bool operator< (const Patient& other) const {
		if (this->visit->get_illness_severity() > other.visit->get_illness_severity()){
			return true;
        }else if (this->visit->get_illness_severity() > other.visit->get_illness_severity()){
			return false;
        }else{
			return true;
        }   
	}

    void print_medical_record(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        medical_history->print_medical_record();
    }

};

#endif // PATIENT_H