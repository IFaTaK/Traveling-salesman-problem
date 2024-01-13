#ifndef SOLVER_H

#include "graph.h"

int path_cost(Graph& graph, std::vector<int>& path);

namespace brute_force
{
    std::vector<int> shortest_path(Graph& graph, int start);

}  // namespace BruteForce

namespace nearest
{
    std::vector<int> shortest_path(Graph& graph, int start);
}  // namespace Nearest


namespace antcolony
{   
    // AntColony class represents the Ant Colony Optimization algorithm
    class AntColony {
    public:
        // Constructor initializes the graph, number of ants, number of iterations, alpha, beta, and evaporation rate
        // It also initializes the pheromones on each edge to 1
        AntColony(Graph& graph,int start, int num_ants, int num_iterations, double alpha, double beta, double evaporation_rate)
            : graph(graph), start(start), num_ants(num_ants), num_iterations(num_iterations), alpha(alpha), beta(beta), evaporation_rate(evaporation_rate) {
            srand(time(0));
            pheromones = std::vector<std::vector<double>>(graph.get_size(), std::vector<double>(graph.get_size(), 1));
        }

        // The solve function is the main function that runs the ACO algorithm
        std::vector<int> solve();
    private:
        Graph& graph;
        int start;
        int num_ants; // Number of ants in the colony
        int num_iterations; // Number of iterations to perform
        double alpha; // Parameter to control the influence of the pheromone trail
        double beta; // Parameter to control the influence of the heuristic information
        double evaporation_rate; // The rate at which pheromones evaporate
        std::vector<std::vector<double>> pheromones; // Pheromone levels on each edge

        std::vector<int> construct_path();
        void update_pheromones(std::vector<int>& path);
        void evaporate_pheromones();
    };

    std::vector<int> shortest_path(Graph& graph, int start);

}  // namespace antcolony

#endif // SOLVER_H