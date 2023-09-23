#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Graph {
protected:
    unsigned int numVertices;
    bool directed;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(unsigned int _numVertices, bool _directed);
    ~Graph();

    virtual bool isDirected() const = 0;
    int getNumVertices() const;
    std::vector<std::vector<int>> getAdjMatrix() const;

    virtual void addEdge(const int from, const int to) = 0;
    virtual void removeEdge(const int from, const int to) = 0;
    virtual bool containsEdge(const int from, const int to) const = 0;

    virtual void addVertex() = 0;
    virtual void removeVertex(const int vertex) = 0;

    float calculateProbability(const float constant);
    virtual void ErdosRenyiModelGeneration(const float constant) = 0;

    void printAdjMatrix() const;
};

class UndirectedGraph : public Graph {
private:

public:
    UndirectedGraph(unsigned int _numVertices);

    bool isDirected() const override;

    void addEdge(const int from, const int to) override;
    void removeEdge(const int from, const int to) override;
    bool containsEdge(const int from, const int to) const override;

    void addVertex() override;
    void removeVertex(const int vertex) override;

    void ErdosRenyiModelGeneration(const float constant) override;
};