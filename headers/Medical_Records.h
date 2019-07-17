/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef MEDICAL_RECORDS_H
#define MEDICAL_RECORDS_H
#include "Person.h"
#include "Current_visit.h"
#include <vector>
using std::vector;

class Medical_Records{
private:
    int number_visits;
    vector<Current_Visit *> visit_record;

public:
    Patient *patient;
    Medical_Records(Patient *patient){
        number_visits = 0;
        this->patient = patient;
    }

    
    void add_visit(Current_Visit * visit){
        visit_record.push_back(visit);
    }

    
    void print_medical_record(){

    }
    
    
    bool operator== (const Patient * other) const {
		if (this->patient->person->get_has_record() == other->person->get_has_record()){
            return true;
        }else{
            return false;
        }
	}

};

#endif // MEDICAL_RECORDS_H
