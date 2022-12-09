#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "filereading.h"
#include "utilities.h"
#include "Graph.h"

using namespace std;

int main () {
    

    filereading fr;

    fr.readairport("/workspaces/CS225/Final-project/data/airports.txt");
    fr.readairroute("/workspaces/CS225/Final-project/data/Routes.txt");
    filereading fr1;
    fr1.readairroute("/workspaces/CS225/Final-project/data/tmp.txt");
    

    Graph G(fr.getAirportVector(), fr.getRouteVector());

    //test BFS to find route
    G.SetBfsGraph(fr.getAirportVector(), fr1.getRouteVector());
    G.BFS(2990, 4078);

    //test dijkstra to find route

    G.dijkstra(2990, 4078);

    //test pagerank
    vector<size_t> test_vec = G.SimplePageRank(10);
  
    for (auto i : test_vec) {
        std::cout << i << " " << fr.getAirportVector()[i].get_name() << " " << fr.getAirportVector()[i].get_country()<< std::endl;
    }
    

    // return 0;
}
