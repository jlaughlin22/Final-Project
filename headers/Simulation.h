/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/17/19
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

Random my_num;

class Simulation{
private:
    read_int Readint;
    string name;
    int clock;
    int total_time = 10080;
    int number_nurses = 1;
    int number_doctors = 2;
    int arrival_rate_per_hour;
    double arrival_rate = 60/60.0;
    Hospital * hospital_simulation;
    vector<Person*> town;
public:
    Simulation(){
        create_273ville();
        //get_data();
        hospital_simulation = new Hospital(town, arrival_rate, number_doctors, number_nurses);
    }

    

    void get_data(){
        cout << "Welcome to the 273ville Emergency room simulation. There are just a few vaules that you need to enter before the simulation is able to start.\n";
        total_time = Readint.Readint("Enter the total time in hours the simulation should simulate for (7*24*60 is 168): ", 0, INT_MAX);
        total_time *= 60.0;
        arrival_rate_per_hour = Readint.Readint("Enter the arrival rate of patients per hour (no more then 60 per hour): ", 1, 60);
        arrival_rate = arrival_rate_per_hour / 60.0;
        number_doctors = Readint.Readint("Enter the number of doctors working during this simulation: ", 0, INT_MAX);
        number_nurses = Readint.Readint("Enter the number of nurses working during this simulation: ", 0, INT_MAX);
    }

    void run_simulation(){
        for(clock = 0; clock < total_time; ++clock){//loop arguements cited from hw07 simulator.h
            hospital_simulation->update(clock);
        }
        hospital_simulation->average_visit_time();
        hospital_simulation->display_menu();
    }

    void create_273ville(){
        fstream fin(".\\Data\\residents_of_273ville.txt", ios::in);
        while(!fin.eof()){
            fin >> name;
            town.push_back(new Person(my_num.random_age(), name));
        }
        fin.close();
    }
};

#endif // SIMULATION_H