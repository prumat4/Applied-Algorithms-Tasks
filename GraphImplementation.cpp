#include "GraphImplementation.hpp"

Graph::Graph(unsigned int _numVertices) : numVertices(_numVertices) {
    adjMatrix.reserve(numVertices + int(numVertices * 0.2));
    adjMatrix = std::vector<std::vector<int>>(numVertices, std::vector<int>(numVertices, 0));

    for(auto& row : adjMatrix)
        row.reserve(numVertices + int(numVertices * 0.2));
}

int Graph::getNumVertices() const {
    return numVertices;
}

std::vector<std::vector<int>> Graph::getAdjMatrix() const {
    return adjMatrix;
}

void Graph::removeEdge(int from, int to) {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjMatrix.at(from).at(to) = adjMatrix.at(to).at(from) = 0;
    }
}

bool Graph::containsEdge(int from, int to) const {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        return adjMatrix.at(from).at(to) != 0;
    }
    return false;
}

void Graph::removeVertex(int vertex) {
    if(vertex >= 0 && vertex <= numVertices) {
        adjMatrix.erase(adjMatrix.begin() + vertex);
        for(auto& row : adjMatrix)
            row.erase(row.begin() + vertex);
    }

    numVertices--;
} 

void Graph::addVertex() {
    adjMatrix.push_back(std::vector<int>(numVertices, 0));
    numVertices++;

    for(auto& row : adjMatrix) {
        row.push_back(0);
    }
}

void Graph::printAdjMatrix() const {
    for (const auto& row : adjMatrix) {
        for (const auto& edge : row) {
            std::cout << edge << ' ';
        }
        std::cout << std::endl;
    }
}

float Graph::calculateProbability(const float constant) {
    return (std::log(numVertices)  * constant) / numVertices;
}

UndirectedGraph::UndirectedGraph(unsigned int _numVertices) : Graph(_numVertices) {}

bool UndirectedGraph::isDirected() const {
    return false;
}

void Graph::addEdge(const int from, const int to) {
    if (from == to)
        return;

    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjMatrix.at(from).at(to) = adjMatrix.at(to).at(from) = 1;
    }
}

void UndirectedGraph::ErdosRenyiModelGeneration(const float constant) {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    float probability = calculateProbability(constant);

    for(int i = 0; i < numVertices; i++) {
        for(int j = i + 1; j < numVertices; j++){
            float randomValue = distribution(gen); 
            if(randomValue <= probability)  
                adjMatrix.at(i).at(j) = adjMatrix.at(j).at(i) = 1;
            else 
                adjMatrix.at(i).at(j) = adjMatrix.at(j).at(i) = 0;
        }
    }
}

DirectedGraph::DirectedGraph(unsigned int _numVertices) : Graph::Graph(_numVertices) {}

bool DirectedGraph::isDirected() const {
    return true;
}

void Graph::addEdge(const int from, const int to) {
    if (from == to)
        return;

    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjMatrix.at(from).at(to) = 1;
    }
}

void DirectedGraph::ErdosRenyiModelGeneration(const float constant) {
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    float probability = calculateProbability(constant);

    for(auto& row : adjMatrix) {
        for(auto& edge : row) {
           float randomValue = distribution(gen); 
           randomValue <= probability ? edge = 1 : edge = 0; 
        }
    }
}
