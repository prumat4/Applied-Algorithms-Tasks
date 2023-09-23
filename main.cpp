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

    UndirectedGraph* ug = new UndirectedGraph(10);
    std::cout << "undirected graph examples:\n";
    clientCode(ug);

    DirectedGraph* dg = new DirectedGraph(10);
    std::cout << "directed graph examples:\n";
    clientCode(dg);

    return 0;
}
