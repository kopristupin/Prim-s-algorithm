#include<vector>
#include <iostream>


class edgenode {
public:
    int y;
    int weight;

};

class graph {
public:
    std::vector<std::vector<edgenode*>> edges;
   
    void initGraph();

  void insert(int numberRoot, int numberNextEdge, int nextweight);
  void PrimsAlg(int startVert);
};

int main()
{
    graph g;
    g.initGraph();
       //  root/ next/ weight
    g.insert(1, 2, 6);
    g.insert(1, 5, 4);
    g.insert(1, 7, 10);
    g.insert(2, 1, 6);
    g.insert(2, 4, 10);
    g.insert(3, 4, 1);
    g.insert(4, 2, 10);
    g.insert(4, 3, 1);
    g.insert(4, 5, 5);
    g.insert(4, 6, 7);
    g.insert(5, 1, 4);
    g.insert(5, 4, 5);
    g.insert(5, 6, 3);
    g.insert(6, 4, 7);
    g.insert(6, 5, 3);
    g.insert(6, 7, 14);
    g.insert(7, 1, 10);
    g.insert(7, 6, 14);

    int c = 0;

    for (auto it : g.edges) {
        std::cout << "Vertice " << c << ": ";
        for (auto it2 : it) {
           std::cout << it2->weight<<" "<< it2->y << ", ";
        }
        std::cout << "\n";
        c++;
        }

    std::cout << "Minimum spanning tree: ";
    g.PrimsAlg(1);

}

void graph::insert(int numberRoot,int numberNextEdge, int nextweight){
    edgenode* edge = new edgenode;
    edge->y = numberNextEdge;
    edge->weight = nextweight;
    edges[numberRoot].push_back(edge);  
};

void graph::initGraph() {
    for (int i = 1; i <= 8; i++) {
        std::vector<edgenode*> vert;
        edges.push_back(vert);
    }
}

void graph::PrimsAlg(int startVert) {
   
    int numberCheapestVert;
    std::vector<int> discovered;
    bool intree[8] = { false,false,false,false,false,false,false,false };
    intree[startVert] = true;
    discovered.push_back(startVert);
   
    for (int i = 1; i <= 8; i++) {
 int cheapestDist=1000;
        for (auto it : discovered) {
            std::cout <<"\n discovered: "<< it << " \n";
            for (auto it2 : edges[it]) {
                std::cout << it2->y <<" "<< it2->weight << ", ";
                if (cheapestDist > it2->weight && std::find(discovered.begin(), discovered.end(), it2->y)== discovered.end()) {
                        cheapestDist = it2->weight;
                        numberCheapestVert = it2->y;
                        std::cout << " found \n";
                }
            }
        }
        std::cout << "\n cheapest vert: "<< numberCheapestVert<<" with weight: "<< cheapestDist << "\n";
       
     if(find(discovered.begin(), discovered.end(), numberCheapestVert) == discovered.end())
        discovered.push_back(numberCheapestVert);
        
       // std::cout << numberCheapestVert;
        intree[numberCheapestVert] = true;
std::cout << "\n\n";
    }
    std::cout << "\n";
    for (auto it : discovered) {
        std::cout << it << " ";
    }

}