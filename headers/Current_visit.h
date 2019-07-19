/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef CURRENT_VISIT_H
#define CURRENT_VISIT_H
#include "Random.h"
#include <iostream>
using namespace std;

extern Random my_num;//Allows access to the global variable defined in Simulation.h 

class Current_Visit{
private:
    int illness_severity;//Holds the illness severity of the current visit
    int visit_time;//holds the total visit time of the current visit
    int arrival_time;//holds the arrival time (When patient was place in priority queue)
    int start_service_time;//holds time when patient started treatment
    int discharge_time;//holds time patient was discharged from hospital

    /**
     * Generates a random number between 1 and 20
     * Generates a random severity of illness
     * 1-10 70% chance
     * 11-15 20% chance
     * 16-20 10% Chance
     */
    void set_illness_severity(){
        my_num.random_probability();//random probability
        illness_severity = my_num.random_severity();//random illness priority
    }

public:
    /**
     * Constructor
     */
    Current_Visit(int arrival_time){
        set_illness_severity();//sets severity of illness when a visit instance is created
        this->arrival_time = arrival_time;//sets the value of this visits arrival time
    }
    
    /**
     * Returns the severity of illness
     * on a 1-20 scale
     */
    int get_illness_severity(){
        return illness_severity;
    }

    /**
     * Used to set the discharge time of the visit and calculate the total time of the vist
     */
    void set_discharge_time(int clock){
        discharge_time = clock;//Sets discharge time to current time
        visit_time = discharge_time - arrival_time;//calculates total time of visit
    }

    /**
     * Used to set the time the service started 
     * Set to current time
     */
    void set_start_service_time(int clock){
        start_service_time = clock;
    }

    /**
     * Returns the time the service started
     */
    int get_start_service_time(){
        return start_service_time;
    }

    /**
     * Returns the total time of the visit
     */
    int get_visit_time(){
        return visit_time;
    }

    /**
     * Prints the information about the visit
     * Illness severity, wait time for treatment, time the treatment took, total time of visit
     */
    void print_visit(){
        cout << "Illness Serverity (scale of 1-20, 1 high 20 low): " << illness_severity << endl;
        cout << "Wait time for treatemnt took " << start_service_time - arrival_time << " minutes.\n";
        cout << "Treatment took " << discharge_time - start_service_time << " minutes.\n";
        cout << "Total time of visit: " << visit_time << " minutes.\n";
    }

    /**
     * Overload of == operator
     * if the arrival_time, discharge_time, illness_severity, start_service_time and visit_time are the same between the two visits are equal (true)
     */
    bool operator== (const Current_Visit& other) const{
        if(this->arrival_time == other.arrival_time && this->discharge_time == other.discharge_time && this->illness_severity == other.illness_severity && this->start_service_time == other.start_service_time && this->visit_time == other.visit_time){
            return true;
        }else{
            return false;
        }
    }

};

#endif // CURRENT_VISIT_H
