/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H
//#include "Medical_Records.h"
//#include "Person.h"
#include "Patient.h"
#include "ServiceMap.h"
#include <queue>
#include <vector>
#include "Rand.h"
using namespace std;

class Hospital{
private:
Rand my_num;
    vector<Person *> town;
    priority_queue<Patient *> current_patients;
    vector<Medical_Records *> patient_records;

    double arrival_rate;
    ServiceMap * Emergancy_Room;
    int number_doctors;
    int number_nurses;

public:
    Hospital(vector<Person *> town, int arrival_rate, int number_doctors, int number_nurses){
        this->town = town;
        this->arrival_rate = arrival_rate / 60.0;
        this->number_doctors = number_doctors;
        this->number_nurses = number_nurses;
        Emergancy_Room = new ServiceMap(number_doctors, number_nurses);
    }

    void update(int clock){
        if((my_num.next_double()) < arrival_rate){
            int possible_patient;
            do{
                possible_patient = (rand()%2000);
            }while(town[possible_patient]->can_admit != true);
            Patient * new_pat = new Patient(clock, town[possible_patient]);
            current_patients.push(new_pat);
            new_pat->person->set_can_admit();
            cout << "New person in waiting room" << endl;
        }
        if(!current_patients.empty()){
            Emergancy_Room->update_doctor(clock);
            Emergancy_Room->update_nurse(clock);
            if(current_patients.top()->visit->get_illness_severity() < 11){
                if(!Emergancy_Room->nurse_is_full()){
                    Emergancy_Room->service_patient_nurse(current_patients.top(), clock);
                    cout << "service nurse patient, severity: " << current_patients.top()->visit->get_illness_severity() << endl;
                    current_patients.pop();
                }else if(!Emergancy_Room->doctor_is_full()){
                    Emergancy_Room->service_patient_doctor(current_patients.top(), clock);
                    cout << "service doctor patient, severity: " << current_patients.top()->visit->get_illness_severity() << endl;
                    current_patients.pop();
                }else{
                    if(Emergancy_Room->get_doctors_size()!=0){
                        Emergancy_Room->update_doctor(clock);
                    }
                    if(Emergancy_Room->get_nurses_size()!=0){
                        Emergancy_Room->update_nurse(clock);
                    }
                }
            }else if(current_patients.top()->visit->get_illness_severity() < 21){
                if(!Emergancy_Room->doctor_is_full()){
                    Emergancy_Room->service_patient_doctor(current_patients.top(), clock);
                    cout << "service doctor patient, severity: " << current_patients.top()->visit->get_illness_severity() << endl;
                    current_patients.pop();
                }else{
                    if(Emergancy_Room->get_doctors_size()!=0){
                        Emergancy_Room->update_doctor(clock);
                    }
                }
                //Emergancy_Room->update_doctor(clock);
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