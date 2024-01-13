#ifndef GRAPH_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

class Graph {
    public:
    Graph(std::vector<std::vector<int>> matrix);
    void print();
    void print_to_file(const std::string& filename);
    int get_distance(int from, int to);
    int get_size() { return this->matrix.size(); }
    void set_visited(int vertex);
    void set_unvisited();
    bool is_visited(int vertex) { return this->visited[vertex]; }

    private:
    std::vector<std::vector<int>> matrix;
    std::vector<bool> visited;
};

void print_path(std::vector<int>& path);

#endif // GRAPH_H