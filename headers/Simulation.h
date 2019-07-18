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
using namespace std;

Random my_num;

class Simulation{
private:
    string name;
    int clock;
    int total_time = 10080;
    int number_nurses = 6;
    int number_doctors = 8;
    int arrival_rate = 15;
    Hospital * hospital_simulation;
    vector<Person*> town;
public:
    Simulation(){
        //get_data();
        create_273ville();
        hospital_simulation = new Hospital(town, arrival_rate, number_doctors, number_nurses);
    }

    void get_data(){
        cout << "total run time in hours";
        cin >> total_time;
        total_time*60.0;
        cout << "Arrival rate";
        cin >> arrival_rate;
        cout << "Number of doctors";
        cin >> number_doctors;
        cout << "number of nurses";
        cin >> number_nurses;
        
    }

    void run_simulation(){
        for(clock = 0; clock < total_time; ++clock){//loop arguements cited from hw07 simulator.h
            //cout << clock;
            hospital_simulation->update(clock);
        }
    }

    void create_273ville(){
        fstream fin(".\\Data\\residents_of_273ville.txt", ios::in);
        while(!fin.eof()){
            fin >> name;
            town.push_back(new Person(my_num.random_age(), name));
        }
        fin.close();
    }

    void menu(){
        
    }
};

#endif // SIMULATION_H