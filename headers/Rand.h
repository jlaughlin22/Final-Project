#ifndef RAND_H_
#define RAND_H_

#include <cstdlib>
#include <ctime>

/** Class to encapsulate the standard random number generator. */
class Rand {

  public:
  
  /** Initializes the random number generator using the time
      as the seed.
  */
  Rand() {
    srand((unsigned int)std::time(0));
  }

  /** Initializes the randon mumber generator using a 
      supplied seed.
  */
  Rand(int seed) {
    srand(seed);
  }

  /** Returns a random integer in the range 0 � n. */
  int next_int(int n) {
    return int(next_double() * n);
  }

  /** Return a random double in the range 0 � 1. */
  double next_double() {
    return double(rand()) / RAND_MAX;
  }

};

#endif