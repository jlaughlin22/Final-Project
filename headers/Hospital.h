/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "ServiceRoom.h"
#include "Current_visit.h"
#include "Medical_Records.h"
#include <queue>
#include <vector>
#include "read_int.h"
#include "Random.h"
#include <iomanip>
#include "binary_sort_person.h"
using namespace std;

extern Random my_num;

class Hospital{
private:
    binary_sort_person person_sort;
    read_int read_int;
    vector<Person *> town;
    priority_queue<Patient *> current_patients;
    vector<Person*> patient_records;
    double arrival_rate;
    ServiceRoom * Emergency_Room;
    int number_doctors;
    int number_nurses;

public:
    Hospital(vector<Person *> &town, double arrival_rate, int number_doctors, int number_nurses){
        this->town = town;
        this->arrival_rate = arrival_rate;
        this->number_doctors = number_doctors;
        this->number_nurses = number_nurses;
        Emergency_Room = new ServiceRoom(number_doctors, number_nurses);
    }

    

    void update(int clock){
        int possible_patient;
        if(Emergency_Room->get_doctors_size()!=0){
            Emergency_Room->update_doctor(clock);
        }
        if(Emergency_Room->get_nurses_size()!=0){
            Emergency_Room->update_nurse(clock);
        }
        if(my_num.random_dbl() < arrival_rate){
            possible_patient = (my_num.random_person());  
            if(search(town[possible_patient]->name, town[possible_patient]->age) == -1){
                Patient* new_pat = new Patient(clock, town[possible_patient]->name, town[possible_patient]->age);
                current_patients.push(new_pat);
                patient_records.push_back(new_pat);
            }else{
                int indx = search(town[possible_patient]->name, town[possible_patient]->age);
                Patient * new_pat = new Patient(clock, patient_records[indx]);
                current_patients.push(new_pat);
            }            
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

    int search(string name, int age){
        for(int i = 0; i < patient_records.size(); i++){
            if (patient_records[i]->name == name && patient_records[i]->age == age){
                return i;
            }
        }
        return -1;
    }
    bool check_insert(Patient* patient){
        for(int i = 0; i < patient_records.size(); i++){
            if (patient_records[i]->name == patient->name && patient_records[i]->age == patient->age){
                return false;
            }
        }
        return true;
    }

    

    void average_visit_time(){
        int average_visit_time = 0;
        int num_visits = 0;
        int num_treaments = 0;
        for(int i = 0; i < patient_records.size(); i++){
            average_visit_time += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->add_up_vists();
            num_visits += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->get_visit_count();
            num_treaments += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->get_treatment_count();
        }
        average_visit_time /= num_visits;
        cout << "The average visit time for each patient was: " << average_visit_time << " minutes.\n\n";
        /*cout << "Total number of visits before treatment: " << num_visits << endl; testing
        cout << "Total number visitors treated: "<< num_treaments << endl;*/ //testing
    }

    void rem_zero_treatments(){
        vector<Person *> holder;
        for(int i = 0; i < patient_records.size(); i++ ){
            if(dynamic_cast<Person *>(patient_records[i])->get_medical_record()->get_visit_count() != 0 ){
                holder.push_back(patient_records[i]);
            }
        }
        patient_records = person_sort.sort_vec(holder);
    }



    void display_menu(){
        string statement = "";
        string patient_name;
        int menu_input;
        rem_zero_treatments();
        patient_records = person_sort.sort_vec(patient_records);
        do{
            menu_input = read_int.Readint("Press 1 if you would like to see a list of all residents treated in the emergency room.\nPress 2 if you would like to retrieve the medical records of a resident by their name.\nPress 3 to exit the program.\n", 1, 3);
            if(menu_input == 1){
                for(int i = 0; i < patient_records.size(); i++ ){
                    statement = "Name: " + patient_records[i]->name + " Age: " + to_string(patient_records[i]->age) + " Number of visits: " + to_string(dynamic_cast<Person *>(patient_records[i])->get_medical_record()->get_visit_count()) + " Number of treatments: " + to_string(dynamic_cast<Person*>(patient_records[i])->get_medical_record()->get_treatment_count());
                    statement.resize(75);
                    cout << statement;
                    if( ((i+1) % 3) == 0 ){
                        cout << endl;
                    }
                }
                cout << endl;
            }else if(menu_input == 2){
                do{
                    cout << "Enter the name of the patient: \n";
                    cin >> patient_name;
                }while(person_sort.binarysearch(patient_records, patient_name) != -1);
                int indx = person_sort.binarysearch(patient_records, patient_name);
                dynamic_cast<Person *>(patient_records[indx])->get_medical_record()->print_medical_record();
            }
        }while(menu_input != 3);
    }
};

#endif // HOSPITAL_H