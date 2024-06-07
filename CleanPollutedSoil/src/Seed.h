#ifndef SEED_H
#define SEED_H

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>
#include <string>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::endl;

#include "Cell.h"

const int SEED_REPRODUCTION_MIN = 1;
const int SEED_REPRODUCTION_MAX = 2;
const int GRIDSIZE = 5;

class Cell;
//Create Seed class and some functions
class Seed {
private:
//declare variable
    int age = 0;
  

public:
    Seed();
    int getAge() const;
    void grow();
    void reproduce(Cell (&cells)[5][5]);
    void die(Cell& cells);
};

#endif /* SEED_H */
