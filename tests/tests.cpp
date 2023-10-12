#include "../src/GraphImplementation.hpp"
#include <chrono>
#include <thread>

int main() {
     std::vector<int> vertices = {5, 10, 20, 30, 50, 60, 70, 80, 90, 100, 200, 400, 600, 800, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 6000, 7000};
    
    for(const auto numberOfVertices : vertices) {
        DirectedGraph graph(numberOfVertices);
        double numberOfIterations = 100;
        double constant = 0.1;
        double DemukronTotalTime = 0.0;
        double DFSTotalTime = 0.0;
       
        while(constant <= 1.5) {
            numberOfIterations = 100;
            while(numberOfIterations) { 
            
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

                std::thread dfsThread (dfs);
                dfsThread.join();

                std::thread demukronThread (demukron);
                demukronThread.join();
                

                numberOfIterations--;
            }

            constant += 0.1;
        }
        std::cout << "number of vertices " << numberOfVertices << std::endl;
        std::cout << "DFS " << DFSTotalTime / 1500 << std::endl;
        std::cout << "Demukron " << DemukronTotalTime / 1500 << std::endl << std::endl;
    }

    return 0;
}