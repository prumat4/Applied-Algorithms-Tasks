#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

#define MAX_WEIGHT float(100)
#define MIN_WEIGHT float(-100)

class Graph {
protected:
    unsigned int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(unsigned int _numVertices);
    ~Graph() = default;

    virtual bool isDirected() const = 0;
    int getNumVertices() const;
    std::vector<std::vector<int>> getAdjMatrix() const;

    virtual void addEdge(const int from, const int to) = 0;
    void removeEdge(const int from, const int to);
    bool containsEdge(const int from, const int to) const;

    void addVertex();
    void removeVertex(const int vertex);

    float calculateProbability(const float constant);
    virtual void ErdosRenyiModelGeneration(const float constant) = 0;

    void printAdjMatrix() const;
};

class UndirectedGraph : public Graph {
public:
    UndirectedGraph(unsigned int _numVertices);

    bool isDirected() const override;
    void addEdge(const int from, const int to) override;
    virtual void ErdosRenyiModelGeneration(const float constant) override;
};

class UndirectedWeightedGraph : public Graph {
    UndirectedWeightedGraph(unsigned int _numVertices);

    void addEdge(const int from, const int to, const int weight);
    void ErdosRenyiModelGeneration(const float constant) override;
};

class DirectedGraph : public Graph {
public: 
    DirectedGraph(unsigned int _numVertices);

    bool isDirected() const override;
    virtual void addEdge(const int from, const int to) override;
    virtual void ErdosRenyiModelGeneration(const float constant) override;
};