/**
 * Author: Jonathan Laughlin
 * Date Created: 7/16/19
 * Date Last Modified: 7/16/19
 * Final Project CS273
 * Emergency Room Simulator
 */

#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>

class Random{
private:
    int probability;
public:
    Random(){
        srand(time(NULL));
    }

    void random_probability(){
        probability = ( rand() % 10 ) + 1;
    }

    int random_severity(){
        if(probability <= 7 && probability >= 1){
            return ( rand() % 10 ) + 1;
        }else if(probability == 8 || probability == 9){
            return ( rand() % 5 ) + 11;
        }else if(probability == 10){
            return ( rand() % 5 ) + 16;
        }
    }

    int random_time(int max){
        return (rand()%max) +1;
    }
    
    int random_doc_service(){
        return (rand() % 20 ) + 1;
    }

    int random_nurse_service(){
        return (rand() % 10 ) + 1;
    }
};

#endif // RANDOM_H