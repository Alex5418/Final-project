

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "filereading.h"

int main () {
    

    filereading fr;

    fr.readairport("/workspaces/CS225/Final-project/data/airports.txt");
    fr.readairrout("Final-project/data/Routes.txt");

    fr.print_airport();




    // temp_file.readairport("airports.txt");
    // std::vector<route> routes;
    // std::string airportFile = "airports.dat";
    // std::string routeFile = "routes.dat";
}