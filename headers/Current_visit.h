/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef CURRENT_VISIT_H
#define CURRENT_VISIT_H
#include "Random.h"
#include <iostream>
using namespace std;

extern Random my_num;

class Current_Visit{
private:
    int illness_severity;
    int visit_time;
    int arrival_time;
    int start_service_time;
    int discharge_time;

    void set_illness_severity(){
        my_num.random_probability();
        illness_severity = my_num.random_severity();
    }

public:
    Current_Visit(int arrival_time){
        set_illness_severity();
        this->arrival_time = arrival_time;
    }
    
    int get_illness_severity(){
        return illness_severity;
    }
    
    void set_discharge_time(int clock){
        discharge_time = clock;
        visit_time = discharge_time - arrival_time;
    }
    void set_start_service_time(int clock){
        start_service_time = clock;
    }

    int get_start_service_time(){
        return start_service_time;
    }

    int get_visit_time(){
        return visit_time;
    }

    void print_visit(){
        cout << "Illness Serverity (scale of 1-20, 1 high 20 low): " << illness_severity << endl;
        cout << "Wait time for treatemnt took " << start_service_time - arrival_time << " minutes.\n";
        cout << "Treatment took " << discharge_time - start_service_time << " minutes.\n";
        cout << "Total time of visit: " << visit_time << " minutes.\n";
    }

};

#endif // CURRENT_VISIT_H
