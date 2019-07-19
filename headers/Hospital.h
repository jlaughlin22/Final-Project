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

extern Random my_num;//Allows access to the global variable defined in Simulation.h 

class Hospital{
private:
    binary_sort_person person_sort;//used for sorting and searcing in vectors of Person
    read_int read_int;//read int used for gathering a value in a range
    vector<Person *> town;//holds each resident from 273ville
    priority_queue<Patient *> current_patients;//priority queue of current patients waiting to be treated
    vector<Person*> patient_records;//vector of person pointers can be used to get the persons medical records
    double arrival_rate;//holds arrival rate of patients (patients per minute)
    ServiceRoom * Emergency_Room;//pointer to the rooms where patients treated
    int number_doctors;//holds number of doctors in simulation
    int number_nurses;//holds number of nurses in simulation

public:

    /**
     * Constructor
     */
    Hospital(vector<Person *> &town, double arrival_rate, int number_doctors, int number_nurses){
        this->town = town;//sets town
        this->arrival_rate = arrival_rate;// sets arrival_rate
        this->number_doctors = number_doctors;//sets number_doctors (number of doctors in simulation)
        this->number_nurses = number_nurses;//sets number_nurses (number of nurses in simulation)
        Emergency_Room = new ServiceRoom(number_doctors, number_nurses);//creates a new service room to house patients in treatment
    }

    /**
     * Used to update the hospital
     * adds patients to priority queue and services patients from the queue
     */
    void update(int clock){
        int possible_patient;
        if(Emergency_Room->get_doctors_size()!=0){//if a doctor is treating somone check if the patients service time is up (ie update doctor maps)
            Emergency_Room->update_doctor(clock);
        }
        if(Emergency_Room->get_nurses_size()!=0){//if a nurse is treating somone check if the patients service time is up (ie update nurse maps)
            Emergency_Room->update_nurse(clock);
        }
        if(my_num.random_dbl() < arrival_rate){//if a patient can arrive
            possible_patient = (my_num.random_person()); //get a random resident 
            if(search(patient_records, town[possible_patient]->name, town[possible_patient]->age) == -1){//if patient is not in records
                Patient* new_pat = new Patient(clock, town[possible_patient]->name, town[possible_patient]->age);// create a new patient
                current_patients.push(new_pat);//add patient to queue
                patient_records.push_back(new_pat);//add patient to records
            }else{//if patient exists in records
                int indx = search(patient_records, town[possible_patient]->name, town[possible_patient]->age);//find index of patient
                Patient * new_pat = new Patient(clock, patient_records[indx]);//copy patient info
                current_patients.push(new_pat);//add patient at index to queue
            }            
        }
        if(!current_patients.empty()){
            if(current_patients.top()->get_visit()->get_illness_severity() < 11){//if top patient has a priority 10 illness or lower
                if(!Emergency_Room->nurse_is_full()){//if there is an open nurse to treat a patient
                    Emergency_Room->service_patient_nurse(current_patients.top(), clock);//send top patient to be serviced by nurse
                    current_patients.pop();//remove top patient from queue
                }else if(!Emergency_Room->doctor_is_full()){//if there is a doctor open to service a patient
                    Emergency_Room->service_patient_doctor(current_patients.top(), clock);//send top patient to be serviced by doctor
                    current_patients.pop();//remove top patient from queue
                }else{
                    if(Emergency_Room->get_doctors_size()!=0){//if a doctor is treating somone check if the patients service time is up (ie update doctor maps)
                        Emergency_Room->update_doctor(clock);
                    }
                    if(Emergency_Room->get_nurses_size()!=0){//if a nurse is treating somone check if the patients service time is up (ie update nurse maps)
                        Emergency_Room->update_nurse(clock);
                    }
                }
            }else if(current_patients.top()->get_visit()->get_illness_severity() < 21){//if top patient has a priority 20 illness or lower
                if(!Emergency_Room->doctor_is_full()){//if there is a doctor open to service a patient
                    Emergency_Room->service_patient_doctor(current_patients.top(), clock);//send top patient to be serviced by doctor
                    current_patients.pop();//remove top patient from queue
                }else{
                    if(Emergency_Room->get_doctors_size()!=0){//if a doctor is treating somone check if the patients service time is up (ie update doctor maps)
                        Emergency_Room->update_doctor(clock);
                    }
                }
            }
        }
    }

    /**
     * Searches for a patient in the hospital records
     * searches by name and age
     */
    int search(vector<Person *> vec, string name, int age){
        for(int i = 0; i < vec.size(); i++){//iterates through vector of records
            if (vec[i]->name == name && vec[i]->age == age){//if has same age and name then same person
                return i;//return index of person
            }
        }
        return -1;//if does not exist the returna  negative index
    }
   

    /**
     * Calculates the average visit time of each person
     * called from Simulation.h
     */
    void average_visit_time(){
        int average_visit_time = 0;//holds the average time of each persons visit
        int num_visits = 0;//holds number of visits
        for(int i = 0; i < patient_records.size(); i++){//iterates through vector of patients records
            average_visit_time += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->add_up_vists();//adds together each persons total visits time
            num_visits += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->get_visit_count();//adds together each persons number of visits
        }
        //cout << average_visit_time << endl;
        average_visit_time /= num_visits;//calculates the average visit of each person
        cout << "The average visit time for each patient was: " << average_visit_time << " minutes.\n";//displays the average visit per person
        //cout << "Total number of visits before treatment: " << num_visits << endl;
        //cout << "Total number visitors treated: "<< num_treaments << endl;
    }

    /**
     * Removes any patients with zero visits from records this occurs if somone visits but is not treated messing up the average visit time
     */
    void rem_zero_treatments(){
        vector<Person *> holder;//holder vector
        for(int i = 0; i < patient_records.size(); i++ ){//iterates through patient_records
            if(dynamic_cast<Person *>(patient_records[i])->get_medical_record()->get_visit_count() != 0 ){//if visit count is not zero
                holder.push_back(patient_records[i]);//adds any person with at least 1 visit
            }
        }
        patient_records = person_sort.sort_vec(holder);//sets patient_records vector to this holder vector
    }

    /**
     * Displays menu 
     * can list all names of patients treated
     * can search fro a patients records by their name
     */
    void display_menu(){
        string statement = "";//holds name and age in listing all names
        string patient_name;//holds name of the patient
        int menu_input;//holds the menu input from the user
        rem_zero_treatments();//removes any person with zero visits see above for more details
        patient_records = person_sort.sort_vec(patient_records);//sorts the patients records by name
        do{//do until user exits via 3
            menu_input = read_int.Readint("\nPress 1 if you would like to see a list of all residents treated in the emergency room.\nPress 2 if you would like to retrieve the medical records of a resident by their name.\nPress 3 to exit the program.\n", 1, 3);//gathers input from user
            if(menu_input == 1){//if user selects 1
                for(int i = 0; i < patient_records.size(); i++ ){
                    statement = "Name: " + patient_records[i]->name;//creates name portion /*Tthe following is for testing  + " Number of visits: " + to_string(dynamic_cast<Person *>(patient_records[i])->get_medical_record()->get_visit_count()) + " Number of treatments: " + to_string(dynamic_cast<Person*>(patient_records[i])->get_medical_record()->get_treatment_count());*/
                    statement.resize(18);//alligns up name protion
                    cout << statement;//displays name portion
                    statement = "Age: " + to_string(patient_records[i]->age);//creates age protion
                    statement.resize(15);//alligns up age prtion
                    cout << statement;//dislays age portion
                    if( ((i+1) % 3) == 0 ){//displays 3 names per row
                        cout << endl;
                    }
                }
                cout << endl;
            }else if(menu_input == 2){//if user selects 2
                do{//continue to gather a name until a name that is entered is found in the records
                    cout << "Enter the name of the resident you would like to see the medical records of (this is case sensitive first letter must be capitalized): ";
                    cin >> patient_name;//gather name
                }while(person_sort.binarysearch(patient_records, patient_name) == -1);//if binarysearch retruns a -1 then the person is not on record
                int indx = person_sort.binarysearch(patient_records, patient_name);//get index of person
                dynamic_cast<Person *>(patient_records[indx])->get_medical_record()->print_medical_record();//display patients records at above index
            }
        }while(menu_input != 3);//if 3 exit
    }
};

#endif // HOSPITAL_H