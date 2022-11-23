

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "filereading.h"
#include "Utils.h"

int main () {
    

    filereading fr;

    fr.readairport("/workspaces/CS225/Final-project/data/airports.txt");
    fr.readairroute("/workspaces/CS225/Final-project/data/Routes.txt");
    // fr.print_route();

    //test distance calculation method

    //get latitude and longtitude of two airports
    double lat1 = fr.getAirportVector()[0].get_latitude();
    double long1 = fr.getAirportVector()[0].get_longtitude();
    double lat2 = fr.getAirportVector()[1].get_latitude();
    double long2 = fr.getAirportVector()[1].get_longtitude();

    double tmp = fr.distance(lat1, long1, lat2, long2);

    //fr.print_airport();

    //std::cout << tmp << std::endl;

    //test graph
    //populate graph with airport id
    vector<vector<int> > g;
    for (size_t i = 0; i < fr.getAirportVector().size(); i++) {
        vector<int> temp;
        temp.push_back(fr.getAirportVector()[i].get_airport_id());
        g.push_back(temp);
    }



    //test graph
    for (size_t i = 0; i < g.size(); i++) {
        for (size_t j = 0; j < g[i].size(); j++) {
            std::cout << g[i][j] << " ";
        }
        std::cout << std::endl;
    }




    return 0;
}