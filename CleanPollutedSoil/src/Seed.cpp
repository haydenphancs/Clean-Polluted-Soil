

#include "Seed.h"
#include "Cell.h"

//Constructor
Seed::Seed(): age(0){

}
//Get age
int Seed::getAge() const{
    return age;
 }
//Add one age when a seed grow
void Seed::grow() {
    ++age;
}

//This function will produce a random number of seeds that are spread in random cells.
// New seeds are added to the total seed.
void Seed::reproduce(Cell (&cells)[5][5]) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<unsigned int> dist1(1,2);
        std::uniform_int_distribution<unsigned int> dist2(0,4);
        int numNewSeeds = dist1(gen);
//Create a random 1 or 2, so add to each random cell
        for (int i = 0; i < numNewSeeds; ++i) {
            int randomRow = dist2(gen);
            int randomCol = dist2(gen);
            Seed* seed = new Seed();
            cells[randomRow][randomCol].addASeed(seed);
        }
}

// Decrease the number of seeds in the cell
void Seed::die(Cell& cells) {
        cells.removeSeedDied();
 }


