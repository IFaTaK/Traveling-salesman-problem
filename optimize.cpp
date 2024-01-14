#include "solver.h"
#include <cstdlib> // for std::rand
#include <ctime> // for std::time

int main(){
    std::srand(std::time(0)); // use current time as seed for random generator

    const int size = 20;
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
                int rand_val = 1 + std::rand() % 100; // generate a random number between 0 and 5
                matrix[i][j] = rand_val;
                matrix[j][i] = rand_val; // ensure symmetry
            }
        }
    }

    // Creation of a Graph object
    Graph g(matrix);

    // Define ranges for parameters
    std::vector<int> num_ants_values = {5, 10, 15, 20, 25};
    std::vector<int> num_iterations_values = {50, 100, 200, 500, 1000};
    std::vector<double> alpha_values = {0.5,0.75, 1, 1.25, 1.5};
    std::vector<double> beta_values = {1, 2, 3, 4, 5};
    std::vector<double> evaporation_rate_values = {0.3 ,0.4, 0.5, 0.6, 0.7};

    int best_num_ants;
    int best_num_iterations;
    double best_alpha;
    double best_beta;
    double best_evaporation_rate;
    int best_past_length = INT_MAX;

    // For each combination of parameters
    for (int num_ants : num_ants_values) {
        for (int num_iterations : num_iterations_values) {
            for (double alpha : alpha_values) {
                for (double beta : beta_values) {
                    for (double evaporation_rate : evaporation_rate_values) {
                        // Run the algorithm with these parameters
                        antcolony::AntColony ant_colony(g, 0, num_ants, num_iterations, alpha, beta, evaporation_rate);
                        std::vector<int> path = ant_colony.solve();

                        // Evaluate the result
                        int path_length = path_cost(g, path);
                        // std::cout << "Parameters: " << num_ants << ", " << num_iterations << ", " << alpha << ", " << beta << ", " << evaporation_rate << " - Path length: " << path_length << "\n";

                        if (path_length < best_past_length) {
                            best_num_ants = num_ants;
                            best_num_iterations = num_iterations;
                            best_alpha = alpha;
                            best_beta = beta;
                            best_evaporation_rate = evaporation_rate;
                            best_past_length = path_length;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Best parameters: " << best_num_ants << ", " << best_num_iterations << ", " << best_alpha << ", " << best_beta << ", " << best_evaporation_rate << " - Path length: " << best_past_length << "\n";
    return 0;
}