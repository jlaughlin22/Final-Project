/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/17/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef BINARY_SORT_H
#define BINARY_SORT_H
#include <vector>
#include <iostream>

using namespace std;

template <typename Type>
class binary_sort{
private:
    vector<Type> binarySort(vector<Type> vec, int size){
        int iPoint = 0;// holding insertion point value
        Type emptAr[vec.size()];//empty array where sorted values stored
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

    int binary_search(Type * items, int first, int last, Type target) {
        int pivot = ( (last - first) / 2 ) + first;
        if(last < first){ //if pass each other
            return (first * -1) - 1;
        } else if((items[pivot] == target)){// if target found
            return pivot;
        }else if(items[pivot] > target){// if val is greater then target search left
            return binary_search(items, first, pivot-1, target);
        }else if(items[pivot] < target){// if val is less then target search right
            return binary_search(items, pivot+1, last, target);
        }
    }
    void insert(Type * array, int position, Type value, int arSize){
        if(position < 0){//checking if position is negative
            position = (position*-1)-1;//sets position to positive
        }
        shift(array, position, arSize);//shifts values to right
        array[position] = value;//sets ar[position] to value
    }
    void shift(Type * array, int position, int arSize){//shifts in right direction
        //from inclass discussion of code
        for(int i = arSize-1; i > position; i--){//iterating through array
            array[i] = array[i-1];//value equal to value to the left by 1
        }
    }
public:
    binary_sort(){}

    vector<Type> sort_vec(vector<Type> vec){
        return binarySort(vec, vec.size());
    }

};

#endif // BINARY_SORT_H