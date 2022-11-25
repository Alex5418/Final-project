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
    // fr.print_route();
    vector<vector<int> > g;
    //test distance calculation method

    // g.resize(4);
    // graph gra;
    // construct a graph
    // g = {
    //     {3,1,2},
    //     {3},
    //     {1,0},
    //     {}
    // };
    // gra.BFS(g, 5508, 5499);


    //get latitude and longtitude of two airports
    // double lat1 = fr.getAirportVector()[0].get_latitude();
    // double long1 = fr.getAirportVector()[0].get_longtitude();
    // double lat2 = fr.getAirportVector()[1].get_latitude();
    // double long2 = fr.getAirportVector()[1].get_longtitude();

    // double tmp = fr.distance(lat1, long1, lat2, long2);

    // fr.print_airport();

    // std::cout << tmp << std::endl;




    Graph G(fr.getAirportVector(), fr.getRouteVector());
    

    //G.printGraph("full_test.txt");

    //G.printConnectedAirports(2966);

    //test BFS to find route
    //G.BFS(2990, 4078);

    //test dijkstra to find route
    // vector<int> tmp_vec = G.dijkstraHelper(3406, 4078);
    // for (auto i : tmp_vec) {
    //     std::cout << i << std::endl;
    // }
    //G.dijkstra(2990, 4078);

    //test betweenness centrality
    //G.betweennessCentrality();

    //test pagerank
    vector<size_t> test_vec = G.SimplePageRank(10);
    // for (auto i : test_vec) {
    //     std::cout << i << std::endl;
    // }
    for (auto i : test_vec) {
        std::cout << i << " " << fr.getAirportVector()[i].get_name() << " " << fr.getAirportVector()[i].get_country()<< std::endl;
    }
    

    return 0;
}
