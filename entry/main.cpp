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
    
    /*readfile*/
    filereading fr;
    fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
    fr.readairroute("/workspaces/cs225/Final-project/data/tem.txt");
    
    /*BFS*/
    vector<vector<int> > g;
    graph gra;
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
    gra.BFS(g, 2990, 4078);

    /*Dijkstra*/
    vector<vector<double>> g1;
    g1.resize(14111);
    for (int tem_rows = 0; tem_rows < 14111; tem_rows++)
        g1[tem_rows].resize(14111);
    for (int i = 0; i < fr.get_route_size(); i++) { 
        int tem_destination_id = fr.getRouteVector()[i].get_destination_airport_id();
        int tem_source_id = fr.getRouteVector()[i].get_source_airport_id();
        if (fr.getRouteVector()[i].get_source_airport_id() == 0) {
            tem_source_id = fr.IATA_to_airpot_id(fr.getRouteVector().at(i).get_source_airport());
        }
        if (fr.getRouteVector()[i].get_destination_airport_id() == 0) {
            tem_destination_id = fr.IATA_to_airpot_id(fr.getRouteVector()[i].get_destination_airport());
        }
        g1[tem_source_id][tem_destination_id] = fr.distance(tem_source_id, tem_destination_id);
    }
    gra.dijkstra(g1, 2990, 4078);
}
