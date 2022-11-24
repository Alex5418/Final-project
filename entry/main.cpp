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
    

    G.printGraph("full_test.txt");

    //G.printConnectedAirports(4608);

    //test BFS to find route
    // G.BFS(2965, 2990);

    

    return 0;
}
