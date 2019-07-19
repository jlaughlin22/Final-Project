/**
 * Author: Jonathan Laughlin
 * Date Created: 7/17/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#include "read_int.h"
#include "gtest/gtest.h"
#include <vector>
#include <iostream>
using namespace std;
read_int test;
/*
//Testing if a lower value is entered that is greater than the high value 
TEST(Readint_TEST, low_greater_than_high){
    auto func = []() { 
        test.Readint("prompt", 24, 9);
    };
    ASSERT_THROW(func(), std::invalid_argument);
}
//testing a regular readint call to make sure it passes
TEST(Readint_TEST, regular){
    auto func = []() { 
        test.Readint("prompt", 5, 3);
    };
    ASSERT_THROW(func(), std::invalid_argument);
}

//checking if low and high are same value
TEST(Readint_TEST, zeros){
    auto func = []() { 
        test.Readint("prompt", 0, 0);
    };
    ASSERT_THROW(func(), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
