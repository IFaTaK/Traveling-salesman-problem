# Traveling salesman problem

## Description
This project aims to provide heuristic solutions to the Traveling Salesman Problem using C++.

![Banner](assets/banner.png)
*Image above: AI-generated banner representing the traveling salesman problem*

## Problem Description

The Traveling Salesman Problem (TSP) is a classic optimization problem in computer science. It involves finding the shortest possible route that a salesman can take to visit a set of cities and return to the starting city, visiting each city exactly once. The problem is NP-hard, meaning that finding an optimal solution for large datasets is computationally expensive.

## Prerequisites
- C++ Compiler
- CMake

## Implemented Methods

1. **Brute Force**: This method exhaustively checks all possible permutations of cities to find the shortest route. However, it is impractical for large datasets due to its exponential time complexity.

2. **Nearest Neighbor**: This method starts from a city and repeatedly selects the nearest unvisited city until all cities are visited. Although it is a simple implementation, it often provides good results.

3. **Ant Colony Optimization**: This method is inspired by the behavior of ant colonies. It uses a combination of pheromone trails and heuristic information to guide the search for the shortest route. This approach can provide intelligent and efficient solutions.

## Building the Project

### For macOS/Linux:
1. Open a terminal.
2. Clone the repository: 
   ```
   git clone https://github.com/IFaTaK/Traveling-salesman-problem.git
   ```
3. Navigate to the project directory.
   ```bash
   cd traveling-salesman-problem
   ```
4. Create and navigate to the build directory:
   ```
   mkdir build && cd build
   ```
5. Run CMake and build the project:
   ```
   cmake .. && make
   ```

### For Windows:
1. Open Command Prompt or PowerShell.
2. Clone the repository: 
   ```
   git clone https://github.com/IFaTaK/Traveling-salesman-problem.git
   ```
3. Navigate to the project directory.
   ```bash
   cd traveling-salesman-problem
   ```
4. Create and navigate to the build directory:
   ```
   mkdir build
   cd build
   ```
5. Run CMake and build the project:
   ```
   cmake ..
   cmake --build
   ```

## Running the Program

### On Unix-based Systems (Linux, macOS)
- After building, run the executable found in the `exec` directory.

```bash
cd ../exec
./[executableName]
```

### On Windows
- After building, run the executable found in the `exec` directory.

```bash
cd ../exec
[executableName].exe
```

There are three executables available:

- `optimize`: This executable attempts to find the best parameters for the ant colony optimization on a randomly generated graph.
- `comparison` : This executable compares the three methods over 10000 random graphs. You can save result in `save/comparison.csv` using :
```bash
./comparison > ../save/comparison.csv # On Unix-based Systems (Linux, macOS)
comparison.exe > ../save/comparison.csv # On windows
```
- `tsp`: This executable solves the traveling salesman problem using the three methods. The generated graph is written into the `save/graph.txt` file.

## Results
- The results of the heuristic methods can vary depending on the dataset and the specific implementation. It is recommended to experiment with different methods and parameters to find the best solution for a given problem instance.

Here is an example I obtained:
```txt
Graph (size 10) : ant_colony parameters (10,100,1,5,0.5)

     0 79 48 72 46 56 49 53 85 93 
    79  0 22 68 37 28 15 38 35 88 
    48 22  0 53 52 68 61 55 60 76 
    72 68 53  0 86 92 38  1 11 93 
    46 37 52 86  0 58 82 63 65 36 
    56 28 68 92 58  0 57 48 57  8 
    49 15 61 38 82 57  0 22 67 50 
    53 38 55  1 63 48 22  0 21 18 
    85 35 60 11 65 57 67 21  0 73 
    93 88 76 93 36  8 50 18 73  0 

nearest :     0 -> 4 -> 9 -> 5 -> 1 -> 6 -> 7 -> 3 -> 8 -> 2 -> 0
ant colony :  0 -> 2 -> 1 -> 6 -> 7 -> 3 -> 8 -> 5 -> 9 -> 4 -> 0
brute force : 0 -> 2 -> 1 -> 6 -> 7 -> 3 -> 8 -> 5 -> 9 -> 4 -> 0

Cost (nearest)    : 275    time: 104 microseconds
Cost (ant colony) : 266    time: 52787 microseconds
Cost (brute force): 266    time: 142010 microseconds
```

## License
This project is licensed under GNU General Public License.


## Project Structure

```
Traveling salesman problem
├─ src
│  ├─ graph.cpp
│  ├─ graph.h
│  ├─ solver.cpp
│  └─ solver.h
├─ data
│  ├─ comparison.csv
│  ├─ experimentation.txt
│  ├─ graph.txt
│  └─ optimize.txt
├─ exec
│  ├─ comparison
│  ├─ optimize
│  └─ tsp
├─ assets
│  └─ banner.png
├─ CMakeLists.txt
├─ LICENSE
├─ README.md
├─ experimentation.xlsx
├─ main.cpp
├─ optimize.cpp
└─ comparison.cpp

```