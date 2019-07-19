/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef BINARY_SORT_PERSON_H
#define BINARY_SORT_PERSON_H
#include <vector>
#include <iostream>
#include <Person.h>
using namespace std;

class binary_sort_person{
private:

    /**
     * Takes each value of vector and sorts them by name into an array then reccoppies it back to a vector and returns the vector
     */
    vector<Person *> binarySort(vector<Person*> vec, int size){//cited from previous homewok assignments from cs172
        int iPoint = 0;// holding insertion point value
        Person * emptAr[vec.size()];//empty array where sorted values stored
        emptAr[0] = vec[0];//first value copy
        for(int i = 1; i < vec.size(); i++){//sorting of each value in array
            iPoint = binary_search(emptAr, 0, i-1, vec[i]);//calls binary search
            insert(emptAr, iPoint, vec[i], size);//inserts value
        }
        vec.clear();//delete contents of vector
        for(int i = 0; i < size; i++){//increment through sorted array
            vec.push_back(emptAr[i]);//add items in sorted order back to vector
        }
        return vec;
    }

    /**
     * returns where vale should go in an array
     */
    int binary_search(Person ** items, int first, int last, Person * target) {//cited from previous homewok assignments from cs172
        int pivot = ( (last - first) / 2 ) + first;//creats pivot point in middle of given range
        if(last < first){ //if pass each other
            return (first * -1) - 1;//return negative index
        } else if((items[pivot]->name == target->name)){// if target found
            return pivot;//return pivot
        }else if(items[pivot]->name > target->name){// if val is greater then target search left
            return binary_search(items, first, pivot-1, target);
        }else if(items[pivot]->name < target->name){// if val is less then target search right
            return binary_search(items, pivot+1, last, target);
        }
    }

    /**
     * Inserts values into an array
     */
    void insert(Person ** array, int position, Person * value, int arSize){//cited from previous homewok assignments from cs172
        if(position < 0){//checking if position is negative
            position = (position*-1)-1;//sets position to positive
        }
        shift(array, position, arSize);//shifts values to right
        array[position] = value;//sets ar[position] to value
    }

    /**
     * Shifts the values in an array to the right
     */
    void shift(Person ** array, int position, int arSize){//shifts in right direction  //cited from previous homewok assignments from cs172
        //from inclass discussion of code
        for(int i = arSize-1; i > position; i--){//iterating through array
            array[i] = array[i-1];//value equal to value to the left by 1
        }
    }

    /**
     * Searches for a value 
     * returns index if found
     * returns -1 if not found
     */
    int binarysearch(const vector<Person*> &items, int first, int last, string target) {
        int pivot = ( (last - first) / 2 ) + first;
        if(last < first){ //if pass each other
            return -1;//not found
        } else if((items[pivot]->name == target)){// if target found
            return pivot;//found
        }else if(items[pivot]->name > target){// if val is greater then target search left
            return binarysearch(items, first, pivot-1, target);
        }else if(items[pivot]->name < target){// if val is less then target search right
            return binarysearch(items, pivot+1, last, target);
        }
    }


public:
    /**
     * Empty Constructor
     */
    binary_sort_person(){}

    /**
     * Returns a sorted vector of person
     * Sorts by name
     */
    vector<Person* > sort_vec(vector<Person*> vec){
        if(vec.size() <=0){
            return vec;
        }
        return binarySort(vec, vec.size());//return the sorted vector
    }

    /**
     * Returns index of person if they are in vector
     * -1 indicates it is not in vector
     */
    int binarysearch(const vector<Person*> &items, string target) {
	    return binarysearch(items, 0, items.size()-1, target);//return the index
    }
};

#endif // BINARY_SORT_H