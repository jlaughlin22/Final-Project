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
#include <utility>
#include <vector>
#include "Patient.h"
#include "Doctor.h"
using namespace std;

class ServiceMap{
private:
    /*map<Doctor, Patient*> doctors;*/
    map<string, Patient*> nurses;
    vector<map<Doctor, Patient*>> doctors;
    int nurse_number = 1;
    int num_nurses;
    int num_doctors;


public:
    ServiceMap(int num_doctors, int num_nurses){
        this->num_doctors = num_doctors;
        this->num_nurses = num_nurses;
    }

    void update(){
        if(nurse_is_full()){
            for(map<string, Patient *>::iterator i = nurse.lower_bound("nurse1"); i != gondor.upper_bound("Aragorn"); i++)
        cout << i->first << ": " << i->second << endl;
        }
    }

    int get_doctors_size(){
        return doctors.size();
    }

    int get_nurses_size(){
        return nurses.size();
    }

    void service_patient_doctor(Patient *patient, int clock){
        doctors.insert(make_pair( Doctor , patient ));
        patient->visit->set_start_service_time(clock);
    }
    
    void service_patient_nurse(Patient *patient, int clock){
        nurses.insert(make_pair("nurse"+nurse_number, patient ));
        patient->visit->set_start_service_time(clock);
        nurse_number++;
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