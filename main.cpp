#include "solver.h"
#include <cstdlib> // for std::rand
#include <ctime> // for std::time
#include <chrono>


int main() {
    std::srand(std::time(0)); // use current time as seed for random generator

    const int size = 10;
    // Creation of an adjacency matrix for a graph with 100 vertices
    // std::vector<std::vector<int>> matrix = {
    //     { 0, 79, 48, 72, 46, 56, 49, 53, 85, 93},
    //     {79,  0, 22, 68, 37, 28, 15, 38, 35, 88},
    //     {48, 22,  0, 53, 52, 68, 61, 55, 60, 76},
    //     {72, 68, 53,  0, 86, 92, 38,  1, 11, 93},
    //     {46, 37, 52, 86,  0, 58, 82, 63, 65, 36},
    //     {56, 28, 68, 92, 58,  0, 57, 48, 57,  8},
    //     {49, 15, 61, 38, 82, 57,  0, 22, 67, 50},
    //     {53, 38, 55,  1, 63, 48, 22,  0, 21, 18},
    //     {85, 35, 60, 11, 65, 57, 67, 21,  0, 73},
    //     {93, 88, 76, 93, 36,  8, 50, 18, 73,  0}
    // };
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if (i == j) {
                matrix[i][j] = 0; // distance from a point to itself is 0
            } else {
                int rand_val = 1 + std::rand() % 100; // generate a random number between 0 and 100
                matrix[i][j] = rand_val;
                matrix[j][i] = rand_val; // ensure symmetry
            }
        }
    }

    // Creation of a Graph object
    Graph g(matrix);

    // Displaying the graph
    g.print_to_file("../save/graph.txt");

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> path = nearest::shortest_path(g, 0);
    print_path(path);
    auto time_nearest = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::vector<int> path_ant_colony = antcolony::shortest_path(g, 0);
    print_path(path_ant_colony);
    auto time_ant_colony = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();

    start = std::chrono::high_resolution_clock::now();
    std::vector<int> path_brute_force = brute_force::shortest_path(g, 0);
    print_path(path_brute_force);
    auto time_brute_force = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();

    std::cout << "Cost (nearest)   : " << path_cost(g, path) << "    time: " << time_nearest << std::endl;
    std::cout << "Cost (ant colony): " << path_cost(g, path_ant_colony) << "    time: " << time_ant_colony << std::endl;
    std::cout << "Cost (brute)     : " << path_cost(g, path_brute_force) << "    time: " << time_brute_force << std::endl;
    return 0;
}