/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/17/19
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
using namespace std;

extern Random my_num;

class Hospital{
private:
    read_int read_int;
    vector<Person *> town;
    priority_queue<Patient *> current_patients;
    vector<Person*> patient_records;
    double arrival_rate;
    ServiceRoom * Emergency_Room;
    int number_doctors;
    int number_nurses;

public:
    Hospital(vector<Person *> town, double arrival_rate, int number_doctors, int number_nurses){
        this->town = sort_vec(town);
        this->arrival_rate = arrival_rate;
        this->number_doctors = number_doctors;
        this->number_nurses = number_nurses;
        Emergency_Room = new ServiceRoom(number_doctors, number_nurses, this->town);
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
            do{
                possible_patient = (my_num.random_person());
            }while(town[possible_patient]->can_admit == false);
            town[possible_patient]->can_admit = false;
            if(search(town[possible_patient]->name, town[possible_patient]->age) == -1){
                Patient* new_pat = new Patient(clock, town[possible_patient]);
                current_patients.push(new_pat);
                patient_records.push_back(new_pat);
                int indx = search(town[possible_patient]->name, town[possible_patient]->age);
                dynamic_cast<Person *>(patient_records[indx])->get_medical_record()->increment_visit_count();
                new_pat->set_can_admit();
            }else{
                int indx = search(town[possible_patient]->name, town[possible_patient]->age);
                Patient * new_pat = new Patient(clock, patient_records[indx]);
                current_patients.push(new_pat);
                new_pat->get_medical_record()->increment_visit_count();
                new_pat->set_can_admit();
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
        for(int i = 0; i < patient_records.size(); i++){
            average_visit_time += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->add_up_vists();
            num_visits += dynamic_cast<Person *>( patient_records[i])->get_medical_record()->get_visit_count();
        }
        average_visit_time /= num_visits;
        cout << "\nThe average visit time for each patient was: " << average_visit_time << " minutes.\n";
    }

    vector<Person *> binarySort(vector<Person*> vec, int size){
        int iPoint = 0;// holding insertion point value
        Person * emptAr[vec.size()];//empty array where sorted values stored
        emptAr[0] = vec[0];
        for(int i = 1; i < vec.size(); i++){//sorting of each value in array
            iPoint = binary_search(emptAr, 0, i-1, vec[i]);//i-1 help Scott Griffoth//finds insertion point
            insert(emptAr, iPoint, vec[i], size);//inserts value
        }
        vec.clear();
        for(int i = 0; i < size; i++){
            vec.push_back(emptAr[i]);
        }
        return vec;
    }

    int binary_search(Person ** items, int first, int last, Person * target) {
        int pivot = ( (last - first) / 2 ) + first;
        if(last < first){ //if pass each other
            return (first * -1) - 1;
        } else if((items[pivot]->name == target->name)){// if target found
            return pivot;
        }else if(items[pivot]->name > target->name){// if val is greater then target search left
            return binary_search(items, first, pivot-1, target);
        }else if(items[pivot]->name < target->name){// if val is less then target search right
            return binary_search(items, pivot+1, last, target);
        }
    }
    void insert(Person ** array, int position, Person * value, int arSize){
        if(position < 0){//checking if position is negative
            position = (position*-1)-1;//sets position to positive
        }
        shift(array, position, arSize);//shifts values to right
        array[position] = value;//sets ar[position] to value
    }
    void shift(Person ** array, int position, int arSize){//shifts in right direction
        //from inclass discussion of code
        for(int i = arSize-1; i > position; i--){//iterating through array
            array[i] = array[i-1];//value equal to value to the left by 1
        }
    }

    vector<Person* > sort_vec(vector<Person*> vec){
        return binarySort(vec, vec.size());
    }

    /**
*	Template function for performing the recursive binary search
*/
int binarysearch(const vector<Person *> &items, int first, int last, string target) {
	int pivot = ( (last - first) / 2 ) + first;
    if(last < first){ //if pass each other
        return -1;
    } else if((items[pivot]->name == target)){// if target found
        return pivot;
    }else if(items[pivot]->name > target){// if val is greater then target search left
        return binarysearch(items, first, pivot-1, target);
    }else if(items[pivot]->name < target){// if val is less then target search right
        return binarysearch(items, pivot+1, last, target);
    }
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/

int binarysearch(const vector<Person *> &items, string target) {
	return binarysearch(items, 0, items.size()-1, target);
}



    void display_menu(){
        string statement = "";
        string patient_name;
        int menu_input;
        patient_records = sort_vec(patient_records);
        do{
            menu_input = read_int.Readint("Press 1 if you would like to see a list of all the patients treated in the emergency room.\nPress 2 if you would like to retrieve the record of a resident by their name.\nPress 3 to exit the program.\n", 1, 3);
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
                cout << "Enter the name of the patient: \n";
                cin >> patient_name;
                int indx = binarysearch(patient_records, patient_name);
                dynamic_cast<Person *>(patient_records[indx])->get_medical_record()->print_medical_record();
            }
        }while(menu_input != 3);
    }
};

#endif // HOSPITAL_H