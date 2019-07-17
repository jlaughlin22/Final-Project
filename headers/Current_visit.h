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

Random ran_Num;

class Current_Visit{
private:
    int illness_severity;
    int visit_time;
    int arrival_time;
    int start_service_time;
    int service_time;
    int discharge_time;

    void set_illness_severity(){
        ran_Num.random_probability();
        illness_severity = ran_Num.random_severity();
    }

public:
    Current_Visit(int arrival_time){
        set_illness_severity();
        this->arrival_time = arrival_time;
    }

    void set_doc_service_time(){
        service_time = ran_Num.random_doc_service();
    }

    void set_nurse_service_time(){
        service_time = ran_Num.random_nurse_service();
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

    void update(int clock){}
};

#endif // CURRENT_VISIT_H
