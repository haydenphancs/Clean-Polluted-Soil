

#include "Grid.h"
#include <random>

//Getter
Gopher& Grid::getGopher(){
    return gopher;
}
// Cell& Grid::getCell(){
//     return cells;
// }

//Initialize Grid when start simulation
//Set the range of gophers
//Set all variables to 0
void Grid::initializeGrid() {
    gopher.setNumGophers(5,7);
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(3,7);
//Run entire the cell to do
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            int randomNumber = dist(gen);
            cells[i][j].setTotalSeedProduced(0);
            cells[i][j].setTotalSeedsDied(0);
            cells[i][j].setToxicityLevel(randomNumber);
        }
    }
}
// Spread initial seeds randomly across the grid
void Grid::spreadSeeds() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<unsigned int> dist1(12,15);
    std::uniform_int_distribution<unsigned int> dist2(0,4);
    int numSeeds = dist1(gen);
//Create a random num from 12-15, then spread it to random cells
    for (int j = 0; j < numSeeds; ++j) {
        int randomRow = dist2(gen);
        int randomCol = dist2(gen);
        Seed* seed = new Seed();
        cells[randomRow][randomCol].addASeed(seed);
    }
}

// Gopher invades random populated cells and eats seeds
// Loop through each cell and simulate growth, reproduction, and death
void Grid::simulateYear() {
//For a seed grow 
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            Cell& currentCell = cells[i][j];
            if(!currentCell.getListSeeds().empty()){
                for (Seed* seed : currentCell.getListSeeds()) {
                    if(seed != nullptr){
                        seed->grow();
                    }
                }
            }
        }
    }
    gopher.move(cells); 
//For a seed produce
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
             Cell& currentCell = cells[i][j];
            if(!currentCell.getListSeeds().empty()){
                for (Seed* seed : currentCell.getListSeeds()) {
                    if(seed != nullptr){
                        if(seed->getAge() == 1 || seed->getAge() == 2){
                        seed->reproduce(cells);
                        }
                    }
                }
            }
        }
    }
//For a seed will die
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
                Cell& currentCell = cells[i][j];
            if(!currentCell.getListSeeds().empty()){
                for (Seed* seed : currentCell.getListSeeds()) {
                    if(seed != nullptr){
                        if(seed->getAge() == 3)
                        seed->die(cells[i][j]);
                    }
                }
            }
        }
    }

}

// Update toxicity levels of each cell based on seed groups in the cell
// The function will subtract 1 level of toxicity from the initial level
// for each group of plants (seeds) in the cell.
// Reduce toxicity based on the number of seeds in the cell
void Grid::updateToxicityLevels() {
  
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            int seedsInCell = cells[i][j].getTotalSeedsByList();
            int initialToxicity = cells[i][j].getToxicityLevel();
            if (seedsInCell > 0) {
                int toxicityReduction = seedsInCell / SEEDS_TO_REDUCE_TOXICITY;
                int toxic = initialToxicity - toxicityReduction;
//If toxic < 0, so set it up to 0
                    if(toxic > 0)
                        cells[i][j].setToxicityLevel(toxic);
                    else
                        cells[i][j].setToxicityLevel(0);    
            }
        }
    }
}
//The function return total seeds produced for the whole simulation
// Loop through all cells in the grid and sum up their total seed produced
int Grid::getTotalSeedProducedInGrid() const {
    int totalSeedProduced = 0;
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            totalSeedProduced += cells[i][j].getTotalSeedProduced();
        }
    }

    return totalSeedProduced;
}
//The function return total seeds died for the whole simulation
// Loop through all cells in the grid and sum up their total seed produced
// int Grid::getTotalSeedDiedInGrid() const{
//     int totalSeedDied = 0;
// //Run entire the cell to add total seed died
//     for (int i = 0; i < GRIDSIZE; ++i) {
//         for (int j = 0; j < GRIDSIZE; ++j) {
//             totalSeedDied += cells[i][j].getTotalSeedsDied();
//         }
//     }

//     return totalSeedDied;

// }

Cell& Grid::getCell(int row, int col) {
    return cells[row][col];
}

// Reset each cell in the grid
bool Grid::resetGrid() {
    bool allCellsReset = true;
//Run entire the cell to reset
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            cells[i][j].resetCell();
            gopher.resetGopher();
              if (cells[i][j].getToxicityLevel() != 0 || 
               cells[i][j].getTotalSeedProduced() != 0 || 
               cells[i][j].getTotalSeedsDied() != 0 ||
               cells[i][j].getTotalSeedsByList() != 0 || 
               !gopher.getVisitedCells().empty() ||
               gopher.getNumGophers() != 0 ||
               gopher.getSeedsEaten() != 0 ){
                allCellsReset = false;
            }
        }
    }
    if (allCellsReset) {
        cout << "Reset the entire grid successfully!" << endl;
        return true;
    } else {
        cout << "Error: Unable to reset some cells in the grid." << endl;
        return false;
    }

}
//Get total seed died
string Grid::getKill() const{
   string outStr;
    int totalSeedDied = 0;
//Run entire the cell to add total seed died
    for (int i = 0; i < GRIDSIZE; ++i) {
        for (int j = 0; j < GRIDSIZE; ++j) {
            totalSeedDied += cells[i][j].getTotalSeedsDied();
        }
    }
//Add into one string
    outStr = "Total seeds died:        " + std::to_string(totalSeedDied);

    return outStr;
}