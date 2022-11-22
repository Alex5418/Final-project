#pragma once
#include <string>
#include <vector>

#include "Airport.h"
#include "route.h"


using namespace std;

class filereading {
    public:
        void readairport(string file_airport);
        void readairroute(string file_route);
        vector<string> GetSubstrs(const string& str, char delimiter);
        string remove_quote(string substr);
        bool check_num(string var);


        // output content inside container
        void print_airport();
        void print_route();
    private:
       vector<airport> airports_vector;
       vector<route> routes_vector;
};