/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/19/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>

class Random{
private:
    int probability;// holds probability of illness severity
public:
    Random(){
        srand(time(NULL));//seed, uses time
    }

    /**
     * Creates a random probability 
     * Used in creating a random illness priority
     */
    void random_probability(){
        probability = ( rand() % 10 ) + 1;//random number between 1 and 10
    }

    /**
     * Using the random probability generated creates a random severity of illness
     */
    int random_severity(){
        if(probability <= 7 && probability >= 1){//70% chance of a 1 to 10 priority
            return ( rand() % 10 ) + 1;//random priority between 1 and 10
        }else if(probability == 8 || probability == 9){//20% chance of a 11 to 15 priority
            return ( rand() % 5 ) + 11;//random priority between 11 and 15
        }else if(probability == 10){//10% chance of a 16 to 20 priority
            return ( rand() % 5 ) + 16;//random priority between 16 and 20
        }
    }

    /**
     * used in creating a random service time
     * input max service time (ie doctor max is 20)
     */
    int random_time(int max){
        return (rand()%max) + 1;//random value between 1 and max
    }

    /**
     * Creates a random value between 0 and 1
     * Used for determining when a patient arrives 
     */
    double random_dbl(){
        return double(rand()) / RAND_MAX;//returns a random value between 0 and 1
    }

    /**
     * Random age between 1 and 122 (122 is oldest record person)
     */
    int random_age(){
        return (rand()%122) + 1;
    }

    /**
     * Random value between 0 and 1999
     * Used to get random resident
     */
    int random_person(){
        return int(rand()%2000);
    }
};

#endif // RANDOM_H