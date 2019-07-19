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
    vector<Person *> binarySort(vector<Person*> vec, int size){
        int iPoint = 0;// holding insertion point value
        Person * emptAr[vec.size()];//empty array where sorted values stored
        emptAr[0] = vec[0];
        for(int i = 1; i < vec.size(); i++){//sorting of each value in array
            iPoint = binary_search(emptAr, 0, i-1, vec[i]);//i-1 help Scott Griffoth//finds insertion point
            insert(emptAr, iPoint, vec[i], size);//inserts value
        }
        vec.clear();
        for(int i = 0; i < size; i++){
            vec.push_back(emptAr[i]);
        }
        return vec;
    }

    int binary_search(Person ** items, int first, int last, Person * target) {
        int pivot = ( (last - first) / 2 ) + first;
        if(last < first){ //if pass each other
            return (first * -1) - 1;
        } else if((items[pivot]->name == target->name)){// if target found
            return pivot;
        }else if(items[pivot]->name > target->name){// if val is greater then target search left
            return binary_search(items, first, pivot-1, target);
        }else if(items[pivot]->name < target->name){// if val is less then target search right
            return binary_search(items, pivot+1, last, target);
        }
    }
    void insert(Person ** array, int position, Person * value, int arSize){
        if(position < 0){//checking if position is negative
            position = (position*-1)-1;//sets position to positive
        }
        shift(array, position, arSize);//shifts values to right
        array[position] = value;//sets ar[position] to value
    }
    void shift(Person ** array, int position, int arSize){//shifts in right direction
        //from inclass discussion of code
        for(int i = arSize-1; i > position; i--){//iterating through array
            array[i] = array[i-1];//value equal to value to the left by 1
        }
    }

int binarysearch(const vector<Person*> &items, int first, int last, string target) {
	int pivot = ( (last - first) / 2 ) + first;
    if(last < first){ //if pass each other
        return -1;
    } else if((items[pivot]->name == target)){// if target found
        return pivot;
    }else if(items[pivot]->name > target){// if val is greater then target search left
        return binarysearch(items, first, pivot-1, target);
    }else if(items[pivot]->name < target){// if val is less then target search right
        return binarysearch(items, pivot+1, last, target);
    }
}


public:
    binary_sort_person(){}

    vector<Person* > sort_vec(vector<Person*> vec){
        return binarySort(vec, vec.size());
    }

    int binarysearch(const vector<Person*> &items, string target) {
	    return binarysearch(items, 0, items.size()-1, target);
    }
};

#endif // BINARY_SORT_H