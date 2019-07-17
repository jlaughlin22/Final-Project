/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */


#ifndef PATIENT_H
#define PACIENT_H
#include <string>
#include "Current_visit.h"
#include "Person.h"
#include <vector>
#include "Current_visit.h"
using std::string;
using std::vector;

class Patient{
private:
    
    int arrival_time;

    int discharge_time;
    

public:
    Current_Visit * visit;
    Person *person;
    Patient(int clock, Person *person){
        this->person = person;
        arrival_time = clock;
        discharge_time = -1;
        visit = new Current_Visit(arrival_time);
    }

	bool operator< (const Patient& other) const {
		if (this->visit->get_illness_severity() > other.visit->get_illness_severity())
			return true;
		else if (this->visit->get_illness_severity() > other.visit->get_illness_severity())
			return false;
		else
			return true;
	}

};

#endif // PATIENT_H