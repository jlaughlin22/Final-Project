/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Patient.h"
#include "ServiceRoom.h"
#include <queue>
#include <vector>
#include "Random.h"
using namespace std;

extern Random my_num;

class Hospital{
private:
    vector<Person *> town;
    priority_queue<Patient *> current_patients;
    vector<Patient*> patient_records;
    double arrival_rate;
    ServiceRoom * Emergency_Room;
    int number_doctors;
    int number_nurses;

public:
    Hospital(vector<Person *> town, int arrival_rate, int number_doctors, int number_nurses){
        this->town = town;
        this->arrival_rate = arrival_rate / 60.0;
        this->number_doctors = number_doctors;
        this->number_nurses = number_nurses;
        Emergency_Room = new ServiceRoom(number_doctors, number_nurses);
    }

    void update(int clock){
        if(my_num.random_dbl() < arrival_rate){
            int possible_patient;
            do{
                possible_patient = (my_num.random_person());
            }while(town[possible_patient]->can_admit != true);
            Patient * new_pat = new Patient(clock, town[possible_patient]);
            current_patients.push(new_pat);
            if(check_insert(new_pat)){
                patient_records.push_back(new_pat);
            }
            new_pat->person->set_can_admit();
            //cout << "New person in waiting room" << endl;
        }
        if(!current_patients.empty()){
            if(current_patients.top()->get_visit()->get_illness_severity() < 11){
                if(!Emergency_Room->nurse_is_full()){
                    Emergency_Room->service_patient_nurse(current_patients.top(), clock);
                    current_patients.pop();
                }else if(!Emergency_Room->doctor_is_full()){
                    Emergency_Room->service_patient_doctor(current_patients.top(), clock);
                    current_patients.pop();
                }else{
                    if(Emergency_Room->get_doctors_size()!=0){
                        Emergency_Room->update_doctor(clock);
                    }
                    if(Emergency_Room->get_nurses_size()!=0){
                        Emergency_Room->update_nurse(clock);
                    }
                }
            }else if(current_patients.top()->get_visit()->get_illness_severity() < 21){
                if(!Emergency_Room->doctor_is_full()){
                    Emergency_Room->service_patient_doctor(current_patients.top(), clock);
                    current_patients.pop();
                }else{
                    if(Emergency_Room->get_doctors_size()!=0){
                        Emergency_Room->update_doctor(clock);
                    }
                }
            }
        }
    }
    bool check_insert(Patient* patient){
        for(int i = 0; i < patient_records.size(); i++){
            if (patient_records[i]->person == patient->person){
                return false;
            }
        }
        return true;
    }

    void records(){
        cout << patient_records.size();
        /*for (int i = 0; i < patient_records.size(); i++){
            patient_records[i]->person->print_medical_record();
        }*/
    }

    void menu(){

    }
};

#endif // HOSPITAL_H