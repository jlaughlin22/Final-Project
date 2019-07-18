/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef MEDICAL_RECORDS_H
#define MEDICAL_RECORDS_H
#include "Current_visit.h"
#include <vector>
using std::vector;

class Medical_Records{
private:
    int number_visits;
    vector<Current_Visit> visit_record;

public:
    Medical_Records(){
        number_visits = 0;
    }

    
    void add_visit(Current_Visit * visit){
        number_visits++;
        visit_record.push_back(*visit);
    }

    
    void print_medical_record(){
        cout << "Number of visits: " << number_visits << endl;
        cout << "List of each visit and information about it: \n";
        //for(int i = 0; i < visit_record.size(); i++){
        //    visit_record[i].print_visit();
        //}
    }
};

#endif // MEDICAL_RECORDS_H
