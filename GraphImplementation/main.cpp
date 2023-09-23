#include "GraphImplementation.hpp"

int main() {
    
    UndirectedGraph ug(10);
    ug.printAdjMatrix();

    std::cout << std::endl;
    
    ug.ErdosRenyiModelGeneration(1);
    ug.printAdjMatrix();

    return 0;
}
