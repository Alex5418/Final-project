

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "filereading.h"

int main () {
    

    filereading fr;

    fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
    fr.readairrout("/workspaces/cs225/Final-project/data/Routes.txt");
    // fr.print_route();
    fr.print_airport();
}