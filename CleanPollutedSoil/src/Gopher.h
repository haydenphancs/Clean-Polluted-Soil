#ifndef GOPHER_H
#define GOPHER_H

#include <vector>
#include <utility>
#include <cstdlib> 
#include <ctime>  
#include <iostream>
#include <string>
#include <random>
#include <iomanip>


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setfill;
using std::setw;

#include "Cell.h"
#include "Num.h"



//Create Gopher class and its functions
class Gopher: public Num {
private:
//Declare variable
    int numGophers = 0;
    int seedsEaten = 0;
    vector<std::pair<int, int>> visitedCells;


public:
    Gopher();
    int getSeedsEaten() const;
    void setNumGophers(int minRange, int maxRange);
    int getNumGophers() const;
    void move(Cell (&cells)[5][5]);
    void eat(Cell& cell);
 //   void recordVisitedCell(int row, int col);
    int randomNum(int lower, int upper);
    vector<std::pair<int, int>> getVisitedCells() const;
    void resetGopher();
    string getKill() const override;

};

#endif /* GOPHER_H */
