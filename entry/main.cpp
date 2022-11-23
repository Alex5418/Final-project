#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "filereading.h"
#include "utilities.h"

using namespace std;

int main () {
    

    filereading fr;

    fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
    fr.readairroute("/workspaces/cs225/Final-project/data/tem.txt");
    // fr.print_route();
    vector<vector<int> > g;
    g.resize(14111);
    
    for (int i = 0; i < fr.get_route_size(); i++) {
        int tem_destination_id = fr.getRouteVector()[i].get_destination_airport_id();
        int tem_source_id = fr.getRouteVector()[i].get_source_airport_id();
        if (fr.getRouteVector()[i].get_source_airport_id() == 0) {
            tem_source_id = fr.IATA_to_airpot_id(fr.getRouteVector().at(i).get_source_airport());
        }
        if (fr.getRouteVector()[i].get_destination_airport_id() == 0) {
            tem_destination_id = fr.IATA_to_airpot_id(fr.getRouteVector()[i].get_destination_airport());
        }
        g[tem_source_id].push_back(tem_destination_id);
    }
    //test distance calculation method

    // g.resize(4);
    graph gra;
    // construct a graph
    // g = {
    //     {3,1,2},
    //     {3},
    //     {1,0},
    //     {}
    // };
    gra.BFS(g, 5508, 5499);


    //get latitude and longtitude of two airports
    // double lat1 = fr.getAirportVector()[0].get_latitude();
    // double long1 = fr.getAirportVector()[0].get_longtitude();
    // double lat2 = fr.getAirportVector()[1].get_latitude();
    // double long2 = fr.getAirportVector()[1].get_longtitude();

    // double tmp = fr.distance(lat1, long1, lat2, long2);

    // fr.print_airport();

    // std::cout << tmp << std::endl;
}
