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


        double distance(double lat1, double long1, double lat2, double long2);
        double distance(int ID1, int ID2);

        // output content inside container
        void print_airport();
        void print_route();

        vector<airport> getAirportVector();
        vector<route> getRouteVector();
        
        int get_route_size();
        int IATA_to_airpot_id(string IATA);

    private:
       vector<airport> airports_vector;
       vector<route> routes_vector;
};
