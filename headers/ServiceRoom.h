/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
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
    map<Doctor *, Patient*> doctors;//map with a key of doctor pointers and a value of patient pointers
    map<Nurse *, Patient*> nurses;//map with a key of nurse pointers and value of patient pointers 
    int num_nurses;//holds number of nurses
    int num_doctors;//holds number of doctors
public:
    /**
     * Constructor
     */
    ServiceRoom(int num_doctors, int num_nurses){
        this->num_doctors = num_doctors;//sets value of num_doctors
        this->num_nurses = num_nurses;//sets value of num_nurses
    }

    /**
     * Updates Doctor
     * If service time of a patient in the map of doctors is up adds the visit to patients records and erases map
     */
    void update_doctor(int clock){
        // had a issue with erase and the iterators after tons of searching cited the erase from https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it
        for(map<Doctor *, Patient *>::iterator i = doctors.begin(); i != doctors.end(); ){//iterates through doctor maps
            if(clock - (i->second->get_visit()->get_start_service_time()) > i->first->get_service_time()){//checks if service time is up for patient
                i->second->get_visit()->set_discharge_time(clock);//sets discharge time of patient to current time
                i->second->get_medical_record()->add_visit(i->second->get_visit());//adds this visit the the patient's records
                i->second->get_medical_record()->increment_visit_count();//increments the count for number of times patient has visited
                i = doctors.erase(i);//erases map
            }else{
                ++i;
            }
        }
    }

    /**
     * Updates Nurse
     * If service time of a patient in the map of doctors is up adds the visit to patients records and erases map
     */
    void update_nurse(int clock){
        // had a issue with erase and the iterators after tons of searching cited the erase from https://stackoverflow.com/questions/8234779/how-to-remove-from-a-map-while-iterating-it
        for(map<Nurse *, Patient *>::iterator i = nurses.begin(); i != nurses.end(); ){//iterates through nurse maps
            if(clock - (i->second->get_visit()->get_start_service_time()) > i->first->get_service_time()){//checks if service time is up for patient
                i->second->get_visit()->set_discharge_time(clock);//sets discharge time of patient to current time
                i->second->get_medical_record()->add_visit(i->second->get_visit());//adds this visit the the patient's records
                i->second->get_medical_record()->increment_visit_count();//increments the count for number of times patient has visited
                i = nurses.erase(i);//erases map
            }else{
                ++i;
            }
        }
    }
    
    /**
     * Returns the size of the doctor map
     * If map same size as number_doctors then all doctors used up
     */
    int get_doctors_size(){
        return doctors.size();
    }

    /**
     * Returns the size of the nurse map
     * If map same size as number_nurses then all nurses used up
     */
    int get_nurses_size(){
        return nurses.size();
    }


    /**
     * Services patient
     * Adds a doctor and a patient to a map
     * When service time of patient is up map is erased
     */
    void service_patient_doctor(Patient *patient, int clock){
        doctors.insert(make_pair(new Doctor , patient));
        patient->get_visit()->set_start_service_time(clock);
    }
    
    /**
     * Services patient
     * Adds a nurse and a patient to a map
     * When service time of patient is up map is erased
     */
    void service_patient_nurse(Patient *patient, int clock){
        nurses.insert(make_pair(new Nurse, patient ));
        patient->get_visit()->set_start_service_time(clock);
    }

    /**
     * Returns true if all nurses used up
     * Returns false if there is a nurse open for a patient
     */
    bool nurse_is_full(){
        if(nurses.size() == num_nurses){
            return true;
        }else{
            return false;     
        }  
    }

    /**
     * Returns true if all doctors used up
     * Returns false if there is a doctor open for a patient
     */
    bool doctor_is_full(){
        if(doctors.size() == num_doctors){
            return true;
        }else{
            return false;     
        }  
    }
};

#endif // SERVICEMAP_H