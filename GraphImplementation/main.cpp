#include "GraphImplementation.hpp"

int main() {
    srand(time(NULL));
    
    Graph gr(10, false);
    gr.printAdjMatrix();

    return 0;
}
