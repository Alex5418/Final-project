#pragma once
#include <string>
#include <vector>
using namespace std;

class filereading {
    public:
        void readairport(string file_airport);
        void readairrout(string file_rout);
        std::vector<std::string> GetSubstrs(const std::string& str, char delimiter)

    private:
       vector<airport> airports_vector;
       vector<rout> routs_vector;
};