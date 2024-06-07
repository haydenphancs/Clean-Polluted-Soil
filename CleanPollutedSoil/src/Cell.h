#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string>
#include <vector>

#include "Seed.h"


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;


class Seed;
//Create Cell class and its functions
class Cell {
private:
//Declare variable
    int totalSeedsProduced = 0;
    int totalSeedsDied = 0;
    int toxicityLevel = 0;
    vector<Seed*> listSeeds;

public:
    Cell();
    ~Cell();
    void setTotalSeedProduced(int num);
    int getTotalSeedProduced() const;
    void setTotalSeedsDied(int num);
    int getTotalSeedsDied() const;
    int getTotalSeedsByList() const;

    void addASeed(Seed* seed);
    void removeSeedDied();
    void removeSeedEat();

    vector<Seed*> getListSeeds() const;
    void setToxicityLevel(int level);
    int getToxicityLevel() const;
    void resetCell();
};

#endif /* CELL_H */