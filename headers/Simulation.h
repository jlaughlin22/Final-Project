/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef SIMULATION_H
#define SIMULATION_H
#include "Hospital.h"
#include "Person.h"
#include "Random.h"
#include <fstream>
#include <iostream>
#include "read_int.h"
using namespace std;

Random my_num; //Global variable

class Simulation{
private:
    read_int Readint;//readint for gather values from user, based of ranges
    int clock;//current time
    int total_time;//holds total time of simulation will be converted to minute upon entry
    int number_nurses;//holds number of nurses working for simulation
    int number_doctors;//holds number of doctors working for simulation
    int arrival_rate_per_hour;//holds number of patients in form patients per hour
    double arrival_rate;//holds arrival rate of patients in form patients per minute
    Hospital * hospital_simulation;//pointer to the hospital simulation
    vector<Person *> town;//list of residents from town
public:
    Simulation(){
        create_273ville();//intitializes a vector of the town with each person from the town
        get_data();// Gather the required data feilds from the user
        hospital_simulation = new Hospital(town, arrival_rate, number_doctors, number_nurses);// creates a new hospital simulation
    }

    
    /**
     *Uses Readint to gather data values
    */
    void get_data(){
        cout << "Welcome to the 273ville Emergency room simulation. There are just a few values that you need to enter before the simulation is able to start.\n";//welcome user to simulation
        total_time = Readint.Readint("Enter the total time in hours the simulation should simulate for (7*24*60 is 168): ", 0, INT_MAX);//gather amount of time simulation should simulate
        total_time *= 60.0;//convert hours to minutes
        arrival_rate_per_hour = Readint.Readint("Enter the arrival rate of patients per hour (no more then 60 per hour): ", 1, 60);//gather arrival rate of patients per hour
        arrival_rate = arrival_rate_per_hour / 60.0;//convert patients per hour to patients per minute
        number_doctors = Readint.Readint("Enter the number of doctors working during this simulation: ", 1, INT_MAX);//gather number of doctors
        number_nurses = Readint.Readint("Enter the number of nurses working during this simulation: ", 0, INT_MAX);//gather number of nurses
    }

    /**
     * Runs a simulation of the hospital for the amount of time entered
     */
    void run_simulation(){
        for(clock = 0; clock < total_time; ++clock){//loop arguements cited from hw07 simulator.h
            hospital_simulation->update(clock);//update hospital
        }
        hospital_simulation->average_visit_time();//display average visit time of all patients treated
        hospital_simulation->display_menu();//Display menu display all names or search for a medical record by resident name
    }

    /**
     * Iterates through file in data folder pushes each name onto town vector as a new person
     */
    void create_273ville(){
        string name;//name of resident
        fstream fin(".\\Data\\residents_of_273ville.txt", ios::in);//opens file in data to read in names of residents
        while(!fin.eof()){//repeat until end of file
            fin >> name;//get next string
            town.push_back(new Person(my_num.random_age(), name));//push a new person on the town vector
        }
        fin.close();//close file
    }
};

#endif // SIMULATION_H