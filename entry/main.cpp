#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "filereading.h"
#include "utilities.h"
#include "Graph.h"
#include "Util.h"

using namespace std;

int main () {
    

    filereading fr;

    fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
    fr.readairroute("/workspaces/cs225/Final-project/data/tem.txt");
    // fr.print_route();
    vector<vector<int> > g;
    g.resize(14111);
    



    //get latitude and longtitude of two airports
    // double lat1 = fr.getAirportVector()[0].get_latitude();
    // double long1 = fr.getAirportVector()[0].get_longtitude();
    // double lat2 = fr.getAirportVector()[1].get_latitude();
    // double long2 = fr.getAirportVector()[1].get_longtitude();

    // double tmp = fr.distance(lat1, long1, lat2, long2);

    // fr.print_airport();

    // std::cout << tmp << std::endl;
}
