#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

class Graph {
private:
    bool directed;
    unsigned int numVertices;
    std::vector<std::vector<int>> adjMatrix;

    void generateDirectedGraph();
    void generateUndirectedGraph();

public:
    int getNumVertices();
    bool isDirected();
    std::vector<std::vector<int>> getAdjMatrix();

    void printAdjMatrix();

    Graph(unsigned int _numVertices, bool _directed);
    Graph(const Graph& other);
};
