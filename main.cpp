#include "GraphImplementation.hpp"

void clientCode(Graph* ptr) {
    ptr->printAdjMatrix();

    std::cout << std::endl;
    
    ptr->ErdosRenyiModelGeneration(2);
    ptr->printAdjMatrix();
    std::cout << std::endl;

    ptr->addEdge(1, 1);
    ptr->addEdge(1, 2);
    ptr->printAdjMatrix();
    std::cout << std::endl;

    ptr->removeEdge(1, 2);
    ptr->printAdjMatrix();
    std::cout << std::endl;

    ptr->addVertex();
    ptr->printAdjMatrix();
    std::cout << std::endl;

    ptr->removeVertex(3);
    ptr->printAdjMatrix();
    std::cout << std::endl;
}

int main() {

    // UndirectedGraph* ug = new UndirectedGraph(10);
    // std::cout << "undirected graph examples:\n";
    // clientCode(ug);

    // DirectedGraph* dg = new DirectedGraph(10);
    // std::cout << "directed graph examples:\n";
    // clientCode(dg);

    // UndirectedWeightedGraph* uwg = new UndirectedWeightedGraph(10);
    // std::cout << "undirected weighted graph examples:\n";
    // clientCode(uwg);

    // DirectedWeightedGraph* dwg = new DirectedWeightedGraph(10);
    // std::cout << "directed weighted graph examples:\n";
    // clientCode(dwg);

    DirectedGraph graph(8);
    graph.addEdge(0, 1);
    graph.addEdge(2, 0);
    graph.addEdge(1, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 1);
    graph.addEdge(0, 3);
    graph.addEdge(2, 5);
    graph.addEdge(5, 3);
    graph.addEdge(6, 3);
    graph.addEdge(6, 4);
    graph.addEdge(7, 3);
    graph.addEdge(7, 6);
    graph.addEdge(5, 7);
    graph.printAdjMatrix();

    auto enumeration = graph.DFSEnumeration();

    std::cout << "DFSEnumeration output: ";
    for(auto element : enumeration)
        std::cout << element << " ";
    std::cout << std::endl;
    
    return 0;
}
