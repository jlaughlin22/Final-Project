/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef PATIENT_H
#define PATIENT_H
#include <vector>
#include "Person.h"
#include "Current_visit.h"
using namespace std;

class Patient: public Person{//Public Person class patient is a person
private:
    int arrival_time;//Holds arrival time of patient (when placed in priority queue)
    int discharge_time;//Holds discharge time of patient (when done being treated)
    Current_Visit * visit;//pointer to current visit of patient
    Person * person;//pointer to this person
public:

    /**
     * Constructor used for creating a brand new person
     */
    Patient(int clock, string name, int age): Person(age, name){
        arrival_time = clock;//sets arrival time to current time
        discharge_time = -1;//sets discharge to a holder value
        visit = new Current_Visit(arrival_time);// Creates a new visit pointer which can be used to edit the current visit of patient
        medical_history = new Medical_Records();//Creates a new medical history for patient

    }

    /**
     * Constructor used for copying a person ie alread in records
     * shallow copy constructor
     */
    Patient(int clock, Person * person){
        this->person = person;//copys info of person to this person
        arrival_time = clock;//sets arrival time to current time
        discharge_time = -1;//sets discharge time to a holder value
        visit = new Current_Visit(arrival_time);// Creates a new visit pointer which can be used to edit the current visit of patient
        medical_history = person->get_medical_record();//Copies medical history of person to this persons medical history

    }


    /**
     * Returns a pointer to the current visit of this patient
     */
    Current_Visit * get_visit(){
        return visit;
    }

    /**
     * Overload of < operator
     */
	bool operator< (const Patient& other) const {
		if (this->visit->get_illness_severity() < other.visit->get_illness_severity()){//if ilness severity of this patient is less than other patient (true)
			return true;
        }else if (this->visit->get_illness_severity() > other.visit->get_illness_severity()){//if ilness severity of this patient is greater than other patient (false)
			return false;
        }else{
			return true;
        }   
	}

    /**
     * Prints medical record of patient
     */
    void print_medical_record(){
        cout << "Name: " << name << endl;//Name
        cout << "Age: " << age << endl;//Age
        medical_history->print_medical_record();//calls medical_records print method
    }

};

#endif // PATIENT_H