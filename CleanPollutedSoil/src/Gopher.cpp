
#include <random>
#include "Gopher.h"


//Constructor
Gopher::Gopher(): numGophers(0), seedsEaten(0) {}

//Getter
int Gopher::getSeedsEaten() const{
    return seedsEaten;
}
int Gopher::getNumGophers() const{
    return numGophers;
}
//Create random number function
int Gopher::randomNum(int lower, int upper) {
    static std::random_device rd; 
    static std::mt19937 gen(rd()); 
    std::uniform_int_distribution< int> distribution(lower, upper);
    return distribution(gen);
}

//Set the range of gophers
void Gopher::setNumGophers(int minRange, int maxRange) {
    int randomRange = randomNum(minRange,maxRange);
    numGophers = randomRange;
}

//Gophers will invade randomly into cells and eat seeds
//Gophers only move to populated cells
//Many number of gophers created, many seeds gophers will eat
void Gopher::move(Cell (&cells)[5][5]) {
    int count1 = 0;
    int count2 = 0;
    while(count1 != numGophers){
        int randomRow =  randomNum(0,4);
        int randomCol =  randomNum(0,4);
//Using if else to handle the if random doesn't work
        if (randomRow >= 0 && randomRow < 5 && randomCol >= 0 && randomCol < 5) {
            int totalSeeds = cells[randomRow][randomCol].getTotalSeedsByList();
            if (totalSeeds > 0) {
                visitedCells.emplace_back(randomRow, randomCol); 
                cells[randomRow][randomCol].removeSeedEat();
                ++seedsEaten;
                ++count1;
            }
        } else {
            cout<<"Invalid random numbers!"<<endl;
            break;
        }
        ++count2;
// By randomly, the whole grid may be ran out of seeds at one point.
// So this will stop the loop run forever
// 25 cells in total, so 1000 time randomly run, it can't be missed some cells
// A poor way to do, but it works
        if(count2 == 1000){
            cout<<"Run out of seed!"<<endl;
            break;
        }
    }
}

//Get cells gophers visited 
vector<std::pair<int, int>> Gopher::getVisitedCells() const{
    return visitedCells;
}
//Reset entire gopher
void  Gopher::resetGopher(){
    visitedCells.clear();
    seedsEaten = 0;
    numGophers = 0;
}

//Print total seeds eaten by gopher
string Gopher::getKill() const {
    string outStr;
    outStr = "Total seeds eaten:       " + std::to_string(getSeedsEaten());
    return  outStr;
  
}