/**
 * Author: Jonathan Laughlin
 * Date Created: 7/18/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef READ_INT_H
#define READ_INT_H
#include <iostream>
#include <limits>
#include <ios>
#include <climits>
#include <stdexcept>
using namespace std;

class read_int{
public:

    /**
     * Empty Constructor
     */
    read_int(){}

    /**
     * Cited from hw06 readint.cpp
     */
    int Readint(const string &prompt, int low, int high){
        if(low >= high){//If outside range
            throw invalid_argument("Invalid range has been entered.");//throw invalid argument
        }
        cin.exceptions(ios_base::failbit);
        int value = 0;//Holds value user enters
        while(true){//Loop until value within range is entered
            try{//Try this
                while(true){//Loops until a value between range is entered
                    cout << prompt;//Display prompt
                    cin >> value;//Gather value
                    if(value >= low && value <= high){//If value is within range
                        cout << endl;//New line
                        return value;//Return value entered
                    }
                }
            }
            catch(ios_base::failure){//cath any exceptions thrown
                cout << "Bad entry please retry.\n";//Bad entry
                cin.clear();//Clears cin stream
                cin.ignore(numeric_limits<int>::max(), '\n');//Removes any values from cin
            }
        }
    }
};

#endif // READ_INT_H