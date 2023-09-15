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

void Graph::printAdjMatrix() {
    for(auto vector : adjMatrix) {
        for(auto element : vector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::generateDirectedGraph(){
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++){
            if(i == j)
                adjMatrix.at(i).at(j) = 0;
            else 
                adjMatrix.at(i).at(j) = rand() % 2;
        }
    }
}

void Graph::generateUndirectedGraph() {
    for(int i = 0; i < numVertices; i++) {
        for(int j = i + 1; j < numVertices; j++){
            adjMatrix.at(i).at(j) = adjMatrix.at(j).at(i) = rand() % 2;
        }
    }
}

Graph::Graph(unsigned int _numVertices, bool _directed) {
    numVertices = _numVertices;
    directed = _directed;
    adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

    directed ? generateDirectedGraph() : generateUndirectedGraph();
}

Graph::Graph(const Graph &other) {
    numVertices = other.numVertices;
    directed = other.directed;
    adjMatrix = other.adjMatrix;
}