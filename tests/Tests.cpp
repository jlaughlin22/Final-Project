/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

/*
#include "Hospital.h"
#include "Person.h"
#include "binary_sort_person.h"
#include <vector>
#include <iostream>
using namespace std;


vector<Person *> names;
binary_sort_person testing_sort;
Hospital testing_hospital(names, .25, 2, 2);

void verify_sort_vec(vector<Person *> person_sort, vector<Person *> expected);//see below for comments
void verify_bin_search(vector<Person *> vec, string name, int expected);//see below for comments
void verify_search_hospital(vector<Person *> vec, string name, int age, int expected);//see below for comments


int main(){
    //Vectors holding vales that can be pasts into the test to check if the functions are working
    vector<Person *> person;
    vector<Person *> test;
    vector<Person *> expected;
    vector<Person *> search_test;
    vector<Person *> empty_vec;

    ////////Adding to vectors for TESTS//////////

    //random letters and symbos
    search_test.push_back(new Person(45, "apple" ));
    search_test.push_back(new Person(42, "####" ));
    search_test.push_back(new Person(4, "54" ));
    search_test.push_back(new Person(49, "Zoe" ));
    search_test.push_back(new Person(56, "ggd" ));
    search_test.push_back(new Person(13, "apple" ));

    //sorted vector of words
    names.push_back(new Person(45, "apple" ));
    names.push_back(new Person(45, "bake" ));
    names.push_back(new Person(45, "tuna" ));
    names.push_back(new Person(45, "zoe" ));

    //unsorted vector
    person.push_back(new Person(45, "c" ));
    person.push_back(new Person(1, "e" ));
    person.push_back(new Person(59, "d" ));
    person.push_back(new Person(15, "a" ));
    person.push_back(new Person(79, "b" ));

    //sorted vector
    test.push_back(new Person(45, "a" ));
    test.push_back(new Person(45, "b" ));
    test.push_back(new Person(45, "c" ));
    test.push_back(new Person(45, "d" ));
    test.push_back(new Person(45, "e" ));

    //////////////TESTS///////////////

    //Binary sort tests
    verify_sort_vec(test, test);//testing a sorted vector
    verify_sort_vec(person, test);//sorting a vector
    verify_sort_vec(names,names);//tesing a sorted vector of words
    verify_sort_vec(empty_vec, empty_vec); //testing empty vector

    //Binary Search tests
    verify_bin_search(test, "a", 0);//searching for existing name
    verify_bin_search(test, "e", 4);//searching for existing name
    verify_bin_search(test, "no", -1);//searching for something not in vector
    verify_bin_search(test, "blank", -1);//searching for something not in vector
    verify_bin_search(test, "1", -1);//searching for something not in vector
    verify_bin_search(test, "@@@@", -1);//searching for something not in vector
    verify_bin_search(test, "c", 2);//searching for something in vector

    //Hospital search tests
    verify_search_hospital(search_test, "####", 42, 1);//searching for something in vector
    verify_search_hospital(search_test, "gdsgsdkjsgkdg", 53534, -1);//searching for something not in vector
    verify_search_hospital(search_test, "54", 4, 2);//searching for something in vector
    verify_search_hospital(names, "zoe", 45, 3);//searching for something in vector


}

//Tests the search function in Hospital.h
//checks to make sure it is returning a indx value or a -1 if the person is not in the vector
void verify_search_hospital(vector<Person *> vec, string name, int age, int expected){
    int actual = testing_hospital.search(vec, name, age);
    cout << "search has ";
    if(actual == expected){
        cout << "Passed\n";
    }else{
        cout << "Failed\n";
    }
}

//Tests sort_vec in the binary_sort_person.h
//determines if the function is able to sort a vector of Person pointers by name
void verify_sort_vec(vector<Person *> actual, vector<Person *> expected){
    actual = testing_sort.sort_vec(actual);
    cout << "sort_vec() has ";
    for(int i = 0; i < actual.size(); i++){
        if(actual[i]->name != expected[i]->name){//one out of place is fail
            cout << "Failed\n";
            return;
        }
    }
    cout << "Passed\n";//no fails so passed
}

////Tests binarysearch in the binary_sort_person.h
//checks to see if the function is able to find a person in a vector that is sorted
void verify_bin_search(vector<Person *> vec, string name, int expected){
    int actual = testing_sort.binarysearch(vec, name);//searches for name in vec
    cout << "binarysearch has ";
    if(actual == expected){// if return vaule is equal to the one expected it passed
        cout << "Passed\n";
    }else{
        cout << "Failed\n";//not the same fail
    }
}

*/
