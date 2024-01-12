#include <iostream>
#include <vector>

class Graph {
    public:
    Graph(std::vector<std::vector<int>> matrix);
    void print();
    int get_distance(int from, int to);

    private:
    std::vector<std::vector<int>> matrix;
    std::vector<bool> visited;
};