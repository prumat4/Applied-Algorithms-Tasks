#include "GraphImplementation.hpp"

int Graph::getNumVertices() {
    return numVertices;
}

bool Graph::isDirected() {
    return directed;
}

std::vector<std::vector<int>> Graph::getAdjMatrix() {
    return adjMatrix;
}
// work on it
void Graph::printAdjMatrix() {
    for(auto vector : adjMatrix) {
        for(auto element : vector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

Graph::Graph(int _numVertices) {
    if(directed){
        
    }
}
