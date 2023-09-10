#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

class Graph {
private:
    bool directed;
    int numVertices;
    std::vector<std::vector<int>> adjMatrix; 

public:
    int getNumVertices();
    bool isDirected();
    std::vector<std::vector<int>> getAdjMatrix();

    void printAdjMatrix();

    Graph(int _numVertices);
    // do we need default constructor?
    // probably should be copy constructor
};
