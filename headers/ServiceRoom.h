/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/17/19
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
#include"Caretaker.h"
using namespace std;

class ServiceRoom{
private:
    map<Doctor *, Patient*> doctors;
    map<Nurse *, Patient*> nurses;
    int num_nurses;
    int num_doctors;
public:
    ServiceRoom(int num_doctors, int num_nurses){
        this->num_doctors = num_doctors;
        this->num_nurses = num_nurses;
    }

    void update_doctor(int clock){
        for(map<Doctor *, Patient *>::iterator i = doctors.begin(); i != doctors.end(); ){// had a issue with erase and the iterators after tons of searching cited the erase from https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it
            if(clock - (i->second->get_visit()->get_start_service_time()) > i->first->get_service_time()){
                i->second->get_visit()->set_discharge_time(clock);
                i->second->get_medical_record()->add_visit(i->second->get_visit());
                i->second->set_can_admit();
                i = doctors.erase(i);
            }else{
                ++i;
            }
        }
    }
    void update_nurse(int clock){
        for(map<Nurse *, Patient *>::iterator i = nurses.begin(); i != nurses.end(); ){// had a issue with erase and the iterators after tons of searching cited the erase from https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it
            if(clock - (i->second->get_visit()->get_start_service_time()) > i->first->get_service_time()){
                i->second->get_visit()->set_discharge_time(clock);
                i->second->get_medical_record()->add_visit(i->second->get_visit());
                i->second->set_can_admit();
                i = nurses.erase(i);
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
        doctors.insert(make_pair(new Doctor , patient));
        patient->get_visit()->set_start_service_time(clock);
    }
    
    void service_patient_nurse(Patient *patient, int clock){
        nurses.insert(make_pair(new Nurse, patient ));
        patient->get_visit()->set_start_service_time(clock);
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