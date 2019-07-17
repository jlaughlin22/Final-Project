/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Medical_Records.h"
#include "Person.h"
#include "Patient.h"
#include "ServiceMap.h"
#include <queue>
#include <vector>
using namespace std;

class Hospital{
private:
    vector<Person *> town;
    priority_queue<Patient *> current_patients;
    vector<Medical_Records *> patient_records;
    int number_doctors;
    int number_nurses;
    double arrival_rate;
    ServiceMap * Emergancy_Room;

public:
    Hospital(vector<Person *> town, int arrival_rate, int number_doctors, int number_nurses){
        this->town = town;
        this->arrival_rate = arrival_rate / 60.0;
        this->number_doctors = number_doctors;
        this->number_nurses = number_nurses;
    }

    void update(int clock){
        if((rand() / RAND_MAX) < arrival_rate){
            int possible_patient;
            do{
                possible_patient = (rand()%2000) + 1;
            }while(town[possible_patient]->can_admit != true);
            Patient * new_pat = new Patient(clock, town[possible_patient]);
            current_patients.push(new_pat);
            if(new_pat->person->get_has_record() == false){
                patient_records.push_back(new Medical_Records(new_pat));
            }
        }
        if(!current_patients.empty()){
            if(current_patients.top()->visit->get_illness_severity() < 11){
                if(!Emergancy_Room->nurse_is_full()){
                    Emergancy_Room->service_patient_nurse(current_patients.top(), clock);
                    current_patients.pop();
                }else if(!Emergancy_Room->doctor_is_full()){
                    Emergancy_Room->service_patient_doctor(current_patients.top(), clock);
                    current_patients.pop();
                }else{
                    Emergancy_Room->update();
                }
            }
            //update service map
            //if queue is full unable to service front so do nothing else move to one of the service queue's
            //based on priority and whether or not nurse service or doctor service is full move it or leave it
        }
    }

    void menu(){

    }
};

#endif // HOSPITAL_H