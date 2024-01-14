#include "solver.h"
#include <random>
#include <chrono>

int main() {
    std::cout << "size,brute force,nearest neighbor,ant colony,time brute force,time nearest neighbor,time ant colony" << std::endl;
    std::random_device rd;

    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> size_distribution(3, 11);
    std::uniform_int_distribution<int> dist_distribution(1, 100);


    for (int idx=0; idx<10000; idx++) {
        int size = size_distribution(engine);
        std::vector<std::vector<int>> matrix(size, std::vector<int>(size));

        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                if (i == j) {
                    matrix[i][j] = 0; // distance from a point to itself is 0
                } else {
                    int rand_val = dist_distribution(engine); // generate a random number between 0 and 5
                    matrix[i][j] = rand_val;
                    matrix[j][i] = rand_val; // ensure symmetry
                }
            }
        }

        // Creation of a Graph object
        Graph g(matrix);

        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> path_nearest = nearest::shortest_path(g, 0);
        auto time_nearest = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

        start = std::chrono::high_resolution_clock::now();
        std::vector<int> path_ant_colony = antcolony::shortest_path(g, 0);
        auto time_ant_colony = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

        start = std::chrono::high_resolution_clock::now();
        std::vector<int> path_brute_force = brute_force::shortest_path(g, 0);
        auto time_brute_force = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start).count();

        std::cout << size << "," << path_cost(g, path_brute_force) << "," << path_cost(g, path_nearest) << "," << path_cost(g, path_ant_colony) << "," << time_brute_force << "," << time_nearest << "," << time_ant_colony << std::endl;
    }
    return 0;
}