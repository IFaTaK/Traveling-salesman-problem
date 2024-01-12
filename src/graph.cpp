#include "graph.h"

Graph::Graph(std::vector<std::vector<int>> matrix) {
    this->matrix = matrix;
    this->visited = std::vector<bool>(matrix.size(), false);
}

void Graph::print() {
    for (std::vector<int> row : this->matrix) {
        for (int col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::get_distance(int from, int to) {
    return this->matrix[from][to];
}
