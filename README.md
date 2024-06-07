## Description

- In this simulation, the program starts a multi-year investigation of a square grid of polluted land.
- We wanted to determine whether using plants to clean up this toxic waste spill site was advisable.
- Assume that plants can reproduce, grow, and die after each year. Also, Gopher as animals destroy crops. 

## Table of Contents

1. [Installation]
2. [Usage for GCC compiler]
3. [Features]
4. [License]
5. [Contact Information]

## Installation

To get started with the project, follow these steps:

1. **Clone the repository**:
    ```sh
    git clone https://github.com/haydenphancs/clean-polluted-soil.git
    cd clean-polluted-soil
    ```

2. **Install Environment**:
- You can run this program on any working environment with C++ language.
- Visual Studio, Xcode, GCC (GNU Compiler Collection),...
- Suggest run with GCC:
  + Check if you have GCC installed:
    ```sh
    gcc --version
    ```
  + If you have not installed yet (using Homebrew):
     ```sh
    brew install gcc
    ```
     
## Usage for GCC compiler:
Here are the basic steps to use run this program:

1. Run the program using GCC:
    ```sh
    g++ *.cpp -o my_program
    ```
2. Then:
    ```sh
    ./my_program.out
    ```

## Features
- The user enter "Y/N" to run simulation, then show:
                Main Menu
----------------------------------------
1) View number of seeds produced, eaten, and died
2) View cells visited by gophers
3) View final toxicity level of each cell
4) Re-run simulation
99/ Exit

## License

N/A

## Contact Information

For any questions or feedback, please contact Hayden Phan : haydenphancs@gmail.com
