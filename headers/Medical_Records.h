/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef MEDICAL_RECORDS_H
#define MEDICAL_RECORDS_H
#include <vector>
#include "Current_visit.h"
using std::vector;

class Medical_Records{
private:
    int number_visits;
    int number_of_treatments;
    vector<Current_Visit> visit_record;

public:
    Medical_Records(){
        number_visits = 0;
        number_of_treatments = 0;
    }

    
    void add_visit(Current_Visit * visit){
        number_of_treatments++;
        visit_record.push_back(*visit);
    }

    int add_up_vists(){
        int total_time_spent = 0;
        for(int i = 0; i < visit_record.size(); i++){
            total_time_spent += visit_record[i].get_visit_time();
        }
        return total_time_spent;
    }

    int get_visit_count(){
        return number_visits;
    }

    int get_treatment_count(){
        return number_of_treatments;
    }

    void increment_visit_count(){
        number_visits++;
    }

    
    void print_medical_record(){
        cout << "Number of visits: " << number_visits << endl;
        cout << "List of each visit and information about it: \n";
        for(int i = 0; i < visit_record.size(); i++){
            visit_record[i].print_visit();
        }
    }
    
};

#endif // MEDICAL_RECORDS_H
