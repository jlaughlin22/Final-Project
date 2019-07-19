///////////////////////////////////////////////////////
// Exam 1
//CS273
//Author: Jonathan Laughlin
//Date created: 6/6/19
//Date Last Modified: 6/7/19
//Professor: Pete Tucker
// This code contains my code for Exam 1 for CS273
///////////////////////////////////////////////////////

 //uncomment tests to build them

#include "read_int.h"
#include "Hospital.h"
#include "Person.h"
#include "binary_sort_person.h"
#include <vector>
//#include "gtest/gtest.h"
#include <iostream>
#include <fstream>
using namespace std;


vector<Person *> names;
binary_sort_person testing;
Hospital testing_hospital(names, .25, 2, 2);
read_int tead_int_test;

void verify_sort_vec(vector<Person *> person_sort, vector<Person *> expected);
void verify_search(vector<Person *> vec, string name, int expected);
void verify_search_hospital(vector<Person *> vec, string name, int age, int expected);
void verify_read_int(const string &prompt, int low, int high, int expected);


int main(){
    
    vector<Person *> person;
    vector<Person *> test;
    vector<Person *> expected;
    vector<Person *> search_test;

    search_test.push_back(new Person(45, "apple" ));
    search_test.push_back(new Person(42, "####" ));
    search_test.push_back(new Person(4, "54" ));
    search_test.push_back(new Person(49, "Zoe" ));
    search_test.push_back(new Person(56, "ggd" ));
    search_test.push_back(new Person(13, "apple" ));

    
    names.push_back(new Person(45, "apple" ));
    names.push_back(new Person(45, "bake" ));
    names.push_back(new Person(45, "tuna" ));
    names.push_back(new Person(45, "zoe" ));

    person.push_back(new Person(45, "c" ));
    person.push_back(new Person(1, "e" ));
    person.push_back(new Person(59, "d" ));
    person.push_back(new Person(15, "a" ));
    person.push_back(new Person(79, "b" ));

    test.push_back(new Person(45, "a" ));
    test.push_back(new Person(45, "b" ));
    test.push_back(new Person(45, "c" ));
    test.push_back(new Person(45, "d" ));
    test.push_back(new Person(45, "e" ));

    verify_sort_vec(test, test);
    verify_sort_vec(person, test);
    verify_sort_vec(names,names);

    verify_search(test, "a", 0);
    verify_search(test, "e", 4);
    verify_search(test, "no", -1);
    verify_search(test, "blank", -1);
    verify_search(test, "1", -1);
    verify_search(test, "@@@@", -1);
    verify_search(test, "c", 2);

    verify_search_hospital(search_test, "####", 42, 1);
    verify_search_hospital(search_test, "gdsgsdkjsgkdg", 53534, -1);
    verify_search_hospital(search_test, "54", 4, 2);
    verify_search_hospital(names, "zoe", 45, 3);


}

void verify_read_int(const string &prompt, int low, int high, int expected){
    
}

void verify_search_hospital(vector<Person *> vec, string name, int age, int expected){
    int actual = testing_hospital.search(vec, name, age);
    cout << "search has ";
    if(actual == expected){
        cout << "Passed\n";
    }else{
        cout << "Failed\n";
    }
}

void verify_sort_vec(vector<Person *> actual, vector<Person *> expected){
    actual = testing.sort_vec(actual);
    cout << "sort_vec() has ";
    for(int i = 0; i < actual.size(); i++){
        if(actual[i]->name != expected[i]->name){
            cout << "Failed\n";
            break;
        }
    }
    cout << "Passed\n";
}

void verify_search(vector<Person *> vec, string name, int expected){
    int actual = testing.binarysearch(vec, name);
    cout << "binarysearch has ";
    if(actual == expected){
        cout << "Passed\n";
    }else{
        cout << "Failed\n";
    }
}
