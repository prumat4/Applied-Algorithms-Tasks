#include "GraphImplementation.hpp"

int main() {
    
    UndirectedGraph ug(10);
    ug.printAdjMatrix();

    std::cout << std::endl;
    
    ug.ErdosRenyiModelGeneration(2);
    ug.printAdjMatrix();
    std::cout << std::endl;

    ug.addEdge(1, 1);
    ug.addEdge(1, 2);
    ug.printAdjMatrix();
    std::cout << std::endl;

    ug.removeEdge(1, 2);
    ug.printAdjMatrix();
    std::cout << std::endl;

    ug.addVertex();
    ug.printAdjMatrix();
    std::cout << std::endl;

    ug.removeVertex(3);
    ug.printAdjMatrix();
    std::cout << std::endl;

    return 0;
}
