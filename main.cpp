#include "graph.h"

int main() {
    // Creation of an adjacency matrix for a graph with 5 vertices
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1000, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    // Creation of a Graph object
    Graph g(matrix);

    // Displaying the graph
    g.print();

    // Obtaining and displaying the distance between two vertices
    int distance = g.get_distance(0, 2);
    std::cout << "Distance: " << distance << std::endl;

    return 0;
}