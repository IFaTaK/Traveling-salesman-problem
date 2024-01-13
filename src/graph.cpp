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

void Graph::print_to_file(const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

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

    // Write the matrix to the file with aligned columns
    for (const std::vector<int>& row : this->matrix) {
        for (int col : row) {
            file << std::setw(maxElementWidth) << col << " ";
        }
        file << "\n";
    }

    file.close();
}

int Graph::get_distance(int from, int to) {
    return this->matrix[from][to];
}

void Graph::set_visited(int vertex) {
    this->visited[vertex] = true;
}

void Graph::set_unvisited() {
    this->visited = std::vector<bool>(this->matrix.size(), false);
}

void print_path(std::vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i != path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}
