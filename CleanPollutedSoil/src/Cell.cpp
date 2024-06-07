#include "Cell.h"
#include "Seed.h"

//Constructor
Cell::Cell() : totalSeedsProduced(0), totalSeedsDied(0), toxicityLevel(0) {}

//Destruction
Cell::~Cell(){
    for(auto& seed : listSeeds){
       delete seed;
    }

}
//Setter and getter
void Cell::setTotalSeedProduced(int num){
    totalSeedsProduced = num;
}
int Cell::getTotalSeedProduced() const{
    return totalSeedsProduced;
}
void Cell::setTotalSeedsDied(int num){
    totalSeedsDied = num;
}
int Cell::getTotalSeedsDied() const{
    return totalSeedsDied;
}
//Get total seeds in the cell
int Cell::getTotalSeedsByList() const {
    if(!listSeeds.empty()){
        return listSeeds.size();
    }else{
        return 0;
    }
}

void Cell::setToxicityLevel(int level) {
    toxicityLevel = level;
}

int Cell::getToxicityLevel() const {
    return toxicityLevel;
}
//Add one seed to the cell
void Cell::addASeed(Seed* seed){
    if (seed != nullptr){
        listSeeds.push_back(seed);
        ++totalSeedsProduced;
    }
}
//Get vector pointer listSeeds
vector<Seed*> Cell::getListSeeds() const {
    return listSeeds;
}

//Remove seed when it's at age 3
//Then add one to total seeds died
void Cell::removeSeedDied() {
    for (auto it = listSeeds.begin(); it != listSeeds.end(); ++it) {
//If getAge = 3, so delete it
        if ((*it)->getAge() == 3) {
            delete *it; 
            it = listSeeds.erase(it); 
            ++totalSeedsDied;
            break;
        }
    }
}

// Remove the seed from the vector
void Cell::removeSeedEat(){
    if (!listSeeds.empty()) {
        listSeeds.pop_back();
    }
}
// Reset entire the cell
// Clear the list of seeds in the cell
void Cell::resetCell() {
        listSeeds.clear(); 
        totalSeedsProduced = 0;
        totalSeedsDied = 0;
        toxicityLevel = 0;
}
