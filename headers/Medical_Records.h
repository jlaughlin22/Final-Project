/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
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
    int number_visits;//holds number of times visited hospital (is when treated it counts as 1 visit)
    int number_of_treatments;//holds number of times treated (testing purposes)
    vector<Current_Visit> visit_record;//holds a vector of visits

public:

    /**
     * Constructor
     */
    Medical_Records(){
        number_visits = 0;//sets number of visits to 0
        number_of_treatments = 0;//sets number of treatments to 0
    }

    /**
     * Adds visit to their records(when done with a visit information about it is stored in the vector)
     */
    void add_visit(Current_Visit * visit){
        number_of_treatments++;//increment number of treatments
        visit_record.push_back(*visit);//store visit
    }

    /**
     * Adds up the total time patient spent at hospital
     * used for calculating average visit time
     */
    int add_up_vists(){
        int total_time_spent = 0;//holds total time spent waiting
        for(int i = 0; i < visit_record.size(); i++){//iterates through vector of visits
            total_time_spent += visit_record[i].get_visit_time();//adds the time spent during visit to total time spent 
        }
        return total_time_spent;//returns the total time spent at hospital
    }

    /**
     * Returns the number of times visited the hospital
     */
    int get_visit_count(){
        return number_visits;
    }


    /**
     * Returns the number of times this person was treated
     * Used for testing
     */
    int get_treatment_count(){
        return number_of_treatments;
    }

    /**
     * Increments the visit count
     * When done with visit this is incremented
     */
    void increment_visit_count(){
        number_visits++;
    }

    /**
     * Prints the medical records
     * Number of visits and list of each visit with its illness severity wait time for service treatment time and total time of visit
     */
    void print_medical_record(){
        cout << "\nNumber of visits: " << number_visits << endl;//Displays the number of visits
        cout << "List of each visit and information about it: \n";
        for(int i = 0; i < visit_record.size(); i++){//lists each visit and a little bit of information about it
            visit_record[i].print_visit();//Calls Current_visit print method
        }
    }

    /**
     * Overload of == operator
     */
    bool operator== (const Medical_Records& other) const{
        if(this->number_of_treatments == other.number_of_treatments && this->number_visits == other.number_visits && this->visit_record == other.visit_record){// if number of visits, number of treatments, visit record are the same between the two records then they are equal
            return true;
        }else{
            return false;
        }
    }
    
};

#endif // MEDICAL_RECORDS_H
