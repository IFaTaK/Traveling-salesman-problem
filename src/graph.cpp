#include "graph.h"

Graph::Graph(std::vector<std::vector<int>> matrix) {
    this->matrix = matrix;
    this->visited = std::vector<bool>(matrix.size(), false);
}

void Graph::print() {
    int maxElementWidth = 0;

    // Find the maximum width of an element in the matrix
    for (const std::vector<int>& row : this->matrix) {
        for (int col : row) {
            int elementWidth = std::to_string(col).length();
            if (elementWidth > maxElementWidth) {
                maxElementWidth = elementWidth;
            }
        }
    }

    // Display the matrix with aligned columns
    for (const std::vector<int>& row : this->matrix) {
        for (int col : row) {
            std::cout << std::setw(maxElementWidth) << col << " ";
        }
        std::cout << std::endl;
    }
}

int Graph::get_distance(int from, int to) {
    return this->matrix[from][to];
}
