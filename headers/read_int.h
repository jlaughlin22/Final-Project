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
    read_int(){}

    int Readint(const string &prompt, int low, int high){//help writing this from hw06 readint.cpp
        if(low >= high){
            throw invalid_argument("Invalid range has been entered.");
        }
        cin.exceptions(ios_base::failbit);
        int value = 0;
        while(true){
            try{
                while(true){
                    cout << prompt;
                    cin >> value;
                    if(value >= low && value <= high){
                        cout << endl;
                        return value;
                    }
                }
            }
            catch(ios_base::failure){
                cout << "Bad entry please retry.\n";
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
        }
    }
};

#endif // READ_INT_H