#ifndef GRID_H
#define GRID_H

#include <cstdlib> // For rand() and srand()
#include <ctime>   
#include <iostream>
#include <string>
#include <vector>
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
#include "Seed.h"
#include "Gopher.h"
#include "Num.h"

const int SEEDS_TO_REDUCE_TOXICITY = 5;

//Create Grid class and its functions
class Grid: public Num {
private:

    Cell cells[GRIDSIZE][GRIDSIZE]; 
    Gopher gopher;
public:
    void initializeGrid();
    void spreadSeeds();
    Gopher& getGopher();
    void simulateYear();
    void updateToxicityLevels();
    int getTotalSeedProducedInGrid() const;
 //   int getTotalSeedDiedInGrid() const;
    Cell& getCell(int row, int col);
    bool resetGrid();
    string getKill() const override;
  
   
};

#endif /* GRID_H */
