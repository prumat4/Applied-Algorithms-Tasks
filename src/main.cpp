#include "GraphImplementation.hpp"
#include <chrono>
#include <thread>

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

    // UndirectedGraph*  = new UndirectedGraph(10);
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

    // DirectedGraph graph(8);
    // graph.addEdge(0, 1);
    // graph.addEdge(2, 0);
    // graph.addEdge(1, 4);
    // graph.addEdge(3, 4);
    // graph.addEdge(3, 1);
    // graph.addEdge(0, 3);
    // graph.addEdge(2, 5);
    // graph.addEdge(5, 3);
    // graph.addEdge(6, 3);
    // graph.addEdge(6, 4);
    // graph.addEdge(7, 3);
    // graph.addEdge(7, 6);
    // graph.addEdge(5, 7);
    // graph.printAdjMatrix();

    // auto enumeration = graph.DFSEnumeration();

    // std::cout << "DFSEnumeration output: ";
    // for(auto element : enumeration)
    //     std::cout << element << " ";
    // std::cout << std::endl;
    
    // DirectedGraph graph2(8);
    // graph2.addEdge(0, 1);
    // graph2.addEdge(2, 0);
    // graph2.addEdge(1, 4);
    // graph2.addEdge(3, 4);
    // graph2.addEdge(3, 1);
    // graph2.addEdge(0, 3);
    // graph2.addEdge(2, 5);
    // graph2.addEdge(5, 3);
    // graph2.addEdge(6, 3);
    // graph2.addEdge(6, 4);
    // graph2.addEdge(7, 3);
    // graph2.addEdge(7, 6);
    // graph2.addEdge(5, 7);
    
    // if(graph2.isDag())
    //     graph2.printAdjMatrix();

    // auto enumeration2 = graph2.DemukronsAlgorithm();

    // std::cout << "Demukron's Algorithm output: ";
    // for(auto element : enumeration2)
    //     std::cout << element << " ";
    // std::cout << std::endl;

    // std::cout << std::endl;
    // ug.printAdjMatrix();
    // ug.printAdjMatrix();
    std::vector<int> vertices = {5, 10, 20, 50, 75, 100};
    


    for(const auto numberOfVertices : vertices) {
        DirectedGraph graph(numberOfVertices);
        double numberOfIterations = 5;
        double constant = 0.1;
        double DemukronTotalTime = 0.0;
        double DFSTotalTime = 0.0;
       
        while(constant <= 1.5) {
            numberOfIterations = 5;
            while(numberOfIterations) { 
            
                graph.ErdosRenyiModelGeneration(constant);
                while(!graph.isDag())
                    graph.ErdosRenyiModelGeneration(constant);

                auto graph1(graph);

                auto demukron = [&]() {
                    auto DemukronStartTime = std::chrono::high_resolution_clock::now();
                    graph.DemukronsAlgorithm();
                    auto DemukronEndTime = std::chrono::high_resolution_clock::now(); 
                
                    auto DemukronDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(DemukronEndTime - DemukronStartTime);
                    DemukronTotalTime += DemukronDuration.count();
                };
            
                auto dfs = [&](){
                    auto DFSStartTime = std::chrono::high_resolution_clock::now();
                    graph1.DFSEnumeration();
                    auto DFSEndTime = std::chrono::high_resolution_clock::now(); 
                
                    auto DFSDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(DFSEndTime - DFSStartTime);
                    DFSTotalTime += DFSDuration.count();
                };

                std::thread demukronThread (demukron);
                demukronThread.join();
                
                std::thread dfsThread (dfs);
                dfsThread.join();

                numberOfIterations--;
            }

            constant += 0.1;
        }

        std::cout << "DFS " << DFSTotalTime / 75 << std::endl;
        std::cout << "Demukron " << DemukronTotalTime / 75 << std::endl << std::endl;
    }
     
    return 0;
}


