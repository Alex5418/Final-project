#pragma once
#include <string>
#include <vector>
using namespace std;

class filereading {
    public:
        void readairport(string file_airport);
        void readairrout(string file_rout);
        vector<std::string> GetSubstrs(const string& str, char delimiter)
        string remove_quote(string substr);
        bool check_num(string var);
    private:
       vector<airport> airports_vector;
       vector<rout> routs_vector;
};