/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef SERVICEMAP_H
#define SERVICEMAP_H
#include <map>
#include <iostream>
#include <utility>
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Random.h"
using namespace std;

class ServiceMap{
private:
    map<Doctor *, Patient*> doctors;
    map<Nurse *, Patient*> nurses;
    int num_nurses;
    int num_doctors;


public:
    ServiceMap(int num_doctors, int num_nurses){
        this->num_doctors = num_doctors;
        this->num_nurses = num_nurses;
    }

    void update_doctor(int clock){
        for(map<Doctor *, Patient *>::iterator i = doctors.begin(); i != doctors.end(); ){// had a issue with erase and the iterators after tons of searching cited the erase from https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it
            cout << "check1Doctor" << endl;
            if(clock - (i->second->visit->get_start_service_time()) > i->first->get_service_time()){
                i->second->visit->set_discharge_time(clock);
                i->second->person->medical_history->add_visit(i->second->visit);
                i->second->person->set_can_admit();
                cout << "check2Doctor" << endl;
                i = doctors.erase(i);
                cout << "Doctor patient done, size: " << doctors.size() << endl;
            }else{
                ++i;
            }
        }
    }
    void update_nurse(int clock){
        for(map<Nurses *, Patient *>::iterator i = nurses.begin(); i != nurses.end(); ){// had a issue with erase and the iterators after tons of searching cited the erase from https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it
            cout << "check1Nurse" << endl;
            if(clock - (i->second->visit->get_start_service_time()) > i->first->){
                i->second->visit->set_discharge_time(clock);
                i->second->person->medical_history->add_visit(i->second->visit);
                i->second->person->set_can_admit();
                cout << "check2Nurse" << endl;
                i = nurses.erase(i);
                cout << "Nurse patient done, size: " << nurses.size() << endl;
            }else{
                ++i;
            }
        }
    }

    int get_doctors_size(){
        return doctors.size();
    }

    int get_nurses_size(){
        return nurses.size();
    }

    void service_patient_doctor(Patient *patient, int clock){
        doctors.insert(make_pair(my_ran.random_doc_service() , patient));
        cout << "Inserting doctor patient, size: " << doctors.size()<< endl;
        patient->visit->set_start_service_time(clock);
    }
    
    void service_patient_nurse(Patient *patient, int clock){
        nurses.insert(make_pair(my_ran.random_nurse_service() , patient ));
        cout << "Inserting nurse patient, size:" << nurses.size() << endl;
        patient->visit->set_start_service_time(clock);
    }

    bool nurse_is_full(){
        if(nurses.size() == num_nurses){
            return true;
        }else{
            return false;     
        }  
    }

    bool doctor_is_full(){
        if(doctors.size() == num_doctors){
            return true;
        }else{
            return false;     
        }  
    }
};

#endif // SERVICEMAP_H