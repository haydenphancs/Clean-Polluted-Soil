/*******************************************************
Summary   : The program will implement an application to handle the basic
            operations for a multi-year investigation of a square grid of polluted land.

Name      :  Hai Phan
Created.  :  Dec 1, 2023
Class     :  CSC 2312 Section 002
Project   :  #1
Due Date  :  Dec 7, 2023 at 11:59 pm
*******************************************************/
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <random>
#include <iomanip>


using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setfill;
using std::setw;


#include "Grid.h"
#include "Gopher.h"
#include "Num.h"

//Start the simulation
void simulationStart(Grid& grid){
//Initialized the whole grid and spread random seeds into it
    grid.initializeGrid();
    grid.spreadSeeds();

    const int SIMULATION_YEARS = 7;
// Run the simulation in 7 years
    for (int year = 1; year <= SIMULATION_YEARS; ++year) {
        cout << "Year " << year << ":\n";
        grid.simulateYear();
        cout<<endl;
        if(year == 7){
            cout<<"Update toxic level!"<<endl;
            grid.updateToxicityLevels();
            cout<<endl;
        }
    }
     cout<<"Simulation successful!"<<endl;

}
//Show main menu
//Enter 99 to quit the entire program
void showMainMenu(){
    cout<<setfill('-')<<setw(40)<<""<<endl;
    cout<<setfill(' ')<<setw(11)<<""<<"Main Menu"<<setfill(' ')<<setw(11)<<endl;
    cout<<setfill('-')<<setw(40)<<""<<endl;
    cout<<"1) View number of seeds produced, eaten, and died"<<endl;
    cout<<"2) View cells visited by gophers"<<endl;
    cout<<"3) View final toxicity level of each cell"<<endl;
    cout<<"4) Re-run simulation"<<endl;
    cout<<setfill(' ')<<setw(22)<<""<<"99) QUIT"<<endl;
    cout<<setfill('-')<<setw(30)<<""<<endl;
    return;
}

//View all information for option 1
void viewInformation(Grid& grid){
    //Gopher gopher;
    vector<Num*> nums;
    Num* gopherPtr = &grid.getGopher();
    nums.push_back(gopherPtr);
    nums.push_back(&grid);
    cout << "Information Overview:"<<endl;
    cout << "Total seeds produced: "<<setfill(' ') << setw(5)<< grid.getTotalSeedProducedInGrid()<<endl;
    for(auto& k : nums){
       cout<<k->getKill()<<endl;
    }

}

//Show gophers visited for option 2
void gophersVisit(Grid& grid){
//Declare variable
    int numGophers = 0;
    int count = 0;
    numGophers = grid.getGopher().getNumGophers();
    cout<<"There are "<<numGophers<<" gophers!"<<endl;
//Many gophers created so there are many visited each year
    cout<<"Gophers visited:"<<endl;
    for (const auto& cell : grid.getGopher().getVisitedCells()) {
        cout << "(" << cell.first << "," << cell.second << ") ";
        ++count;
        if(count % numGophers == 0){
            cout<<endl;
        }
    }
     cout<<endl;
}

//View the final toxicity level of each cells
void viewFinalToxicityLevel(Grid& grid){
    cout << "Final toxicity levels of each cell:"<<endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout<< grid.getCell(i, j).getToxicityLevel() << "\t";
        }
        cout<<endl;
    }
    cout<<endl;
}
//Re-run simulation
//Reset entire the grid, then check it weather reset or not
//Confirm that it's already reset
void reRunSimulation(Grid& grid){
    if(grid.resetGrid()){
    cout<<"Re-run simulation!"<<endl;
    simulationStart(grid);
    }else{
        cout<<"Unable to re-run simulation!"<<endl;
    }

}

//main function
int main() {
   
//Declaration of variables
    int choice = 0;
    char yesNo = 'N';
    Grid grid;
   // Gopher gopher;
//Present a greeting that briefly explains the simulation
    cout<<setfill('-')<<setw(40)<<""<<endl;
    cout<<"WELCOME"<<endl;
    cout<<"In our simulation, we are starting a multi-year investigation of a square grid of polluted land."<<endl;
    cout<<"We want to determine whether using plants to clean up this toxic waste spill area makes sense."<<endl;
    cout<<setfill('-')<<setw(40)<<""<<endl;
//Show menu and ask the user enters the choice
    cout<<"Confirm 'y' to start the simulation : ";
    cin>>yesNo;
    if(yesNo == 'Y' || yesNo == 'y'){
        simulationStart(grid);
    }else{
        cout<<"Good bye!"<<endl;
        return 0;
    }
//Using while to run menu and option that enter from users
    while(true){
    showMainMenu();
    cout<<"Enter your choice: ";
    cin>>choice;
    if (cin.fail()) {
        cout << "Invalid input! Please enter a integer." << endl;
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }else{
//Using switch case to handle all the choices made by the user
        switch(choice){

            case 1:
            {
//View number of seeds produced, eaten, and died
                cout<<endl;
                viewInformation(grid);
                break;
            }
            case 2:
            {
//View cells visited by gophers
                cout<<endl;
                gophersVisit(grid);
                break;
            }
//View final toxicity level of each cell
            case 3:
            {   cout<<endl;
                viewFinalToxicityLevel(grid);
                break;
            }

            case 4:
            {
// Re-run simulation
                cout<<endl;
                reRunSimulation(grid);
                break;
            }
            case 5:
            {
                cout<<endl;
//Just to prepare for new function in the future
                cout<<"Do nothing!"<<endl;
                break;
            }

            case 99:
//confirm to exit
            {
                cout<<"Confirm to exit? Y/N:";
                cin>>yesNo;
                if(yesNo == 'Y' || yesNo == 'y'){
                    return 1;
                }else if(yesNo == 'N' || yesNo == 'n'){
                    break;
                }
                break;
            }
            default:
//If the user enters invalid choice, so print "Invalid choice. Please try again".
            cout<<"Invalid choice. Please enter again!"<<endl;
            break;
           }
        }

    }
//All done, return 0 to exit program
    return 0;


}
