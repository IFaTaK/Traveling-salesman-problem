#include "solver.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <numeric>
#include <random>


int path_cost(Graph& graph, std::vector<int>& path) {
    int cost = 0;

    for (int i = 0; i < path.size() - 1; i++) {
        cost += graph.get_distance(path[i], path[i + 1]);
    }

    return cost;
}

std::vector<int> brute_force::shortest_path(Graph& graph, int start) {
    std::vector<int> path;
    std::vector<int> shortest_path;
    int shortest_distance = INT_MAX;

    // Generate all possible permutations of cities
    std::vector<int> cities;
    for (int i = 0; i < graph.get_size(); i++) {
        if (i != start) {
            cities.push_back(i);
        }
    }

    do {
        path.clear();
        path.push_back(start);
        for (int i = 0; i < cities.size(); i++) {
            path.push_back(cities[i]);
        }
        path.push_back(start);

        // Calculate the total distance of the current path
        int distance = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            distance += graph.get_distance(path[i], path[i + 1]);
        }

        // Update the shortest path if necessary
        if (distance < shortest_distance) {
            shortest_distance = distance;
            shortest_path = path;
        }
    } while (std::next_permutation(cities.begin(), cities.end()));

    return shortest_path;
}

std::vector<int> nearest::shortest_path(Graph& graph, int start) {
    std::vector<int> path;
    graph.set_unvisited();
    
    path.push_back(start);
    graph.set_visited(start);
    int current = start;

    while (path.size() < graph.get_size()) {
        int min_distance = INT_MAX;
        int nearest = -1;

        for (int i = 0; i < graph.get_size(); i++) {
            if (graph.get_distance(current, i) < min_distance && !graph.is_visited(i)) {
                min_distance = graph.get_distance(current, i);
                nearest = i;
            }
        }

        path.push_back(nearest);
        graph.set_visited(nearest);
        current = nearest;
    }

    path.push_back(start);
    return path;
}

std::vector<int> antcolony::AntColony::construct_path() {
    std::default_random_engine generator;

    std::vector<int> path;
    graph.set_unvisited();
    int current = start;

    path.push_back(current);
    graph.set_visited(current);

    for (int i = 1; i < graph.get_size(); ++i) {
        std::vector<double> probabilities;
        for (int j = 0; j < graph.get_size(); ++j) {
            if (graph.is_visited(j)) {
                probabilities.push_back(0);
            } else {
                double pheromone = pow(pheromones[current][j], alpha);
                double visibility = pow(1.0 / graph.get_distance(current, j), beta);
                probabilities.push_back(pheromone * visibility);
            }
        }

        double sum = std::accumulate(probabilities.begin(), probabilities.end(), 0.0);
        for (double& probability : probabilities) {
            probability /= sum;
        }

        std::discrete_distribution<int> distribution(probabilities.begin(), probabilities.end());
        current = distribution(generator);
        path.push_back(current);
        graph.set_visited(current);
    }
    path.push_back(start);
    return path;
}

void antcolony::AntColony::update_pheromones(std::vector<int>& path) {
    int path_length = path_cost(graph, path);
    double pheromone = 10.0 / path_length;

    for (int i = 0; i < path.size() - 1; ++i) {
        pheromones[path[i]][path[i + 1]] += pheromone;
        pheromones[path[i + 1]][path[i]] += pheromone;
    }
}

void antcolony::AntColony::evaporate_pheromones() {
    for (int i = 0; i < pheromones.size(); ++i) {
        for (int j = 0; j < pheromones.size(); ++j) {
            pheromones[i][j] *= (1 - evaporation_rate);
        }
    }
}

std::vector<int> antcolony::AntColony::solve() {
    srand(time(0));
    std::vector<int> best_path;
    int best_path_length = INT_MAX;

    for (int iteration = 0; iteration < num_iterations; ++iteration) {
        for (int ant = 0; ant < num_ants; ++ant) {
            std::vector<int> path = construct_path();
            int path_length = path_cost(graph, path);

            if (path_length < best_path_length) {
                best_path_length = path_length;
                best_path = path;
            }

            update_pheromones(path);
        }

        evaporate_pheromones();
    }

    return best_path;
}

std::vector<int> antcolony::shortest_path(Graph& graph, int start) {
    AntColony ant_colony(graph, start, 10, 100, 0.5, 5, 0.5);
    return ant_colony.solve();
}