#include "filereading.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

vector<string> filereading::GetSubstrs(const string& str, char delimiter) {
  size_t last = 0;
  vector<string> substrs;
  for (size_t i = 0; i != str.length(); ++i) {
    if (str.at(i) == delimiter) {
      string substr = str.substr(last, i - last);
      last = i + 1;
      substrs.push_back(substr);
    }
  }
  std::string substr = str.substr(last, str.length() - last);
  substrs.push_back(substr);

  return substrs;
}

void filereading::readairport(string file_airport) {
    ifstream ifs{file_airport};
    for(string line; getline(ifs, line); line = ""){
        vector<std::string> temp = filereading::GetSubstrs(line, ',');
        Airport tem_airport();
        for (size_t i = 0; i < temp.size(); i++) {
            temp[i] = remove_quote(temp[i]);
        }
        if (check_num(temp[0])) {
            tem_airport.airline_id_ = stoi(temp[0]);
        }
        tem_airport.name_ = temp[1];
        tem_airport.city_ = temp[2];
        tem_airport.county = temp[3];
        tem_airport.IATA_ = temp[4];
        tem_airport.ICAO_ = temp[5];
        if (check_num(temp[6])) {
            tem_airport.latitude_ = stoi(temp[6]);
        } 
        if (check_num(temp[7])) {
            tem_airport.longtitude = stoi(temp[7]);
        }
        if (check_num(temp[8])) {
            tem_airport.longtitude = stoi(temp[8]);
        }

        airports_vector.push_back(tem_airport);
    }
}
        
void filereading::readairrout(string file_rout) {
    ifstream ifs{file_rout};
    for(string line; getline(ifs, line); line = ""){
        vector<string> rout_temp = filereading::GetSubstrs(line, ',');
        route tem_route();
        tem_route.airline_ = rout_temp[0];
        if (check_num(rout_temp[1])) {
            tem_route.airline_id_ = rout_temp[1];
        }
        tem_route.source_airport_ = rout_temp[2];
        if (check_num(rout_temp[3])) {
            tem_route.source_airport_id_ = rout_temp[3];
        }
        tem_route.destination_airport_ = rout_temp[4];
        if (check_num(rout_temp[5])) {
            tem_route.destination_airport_id_ = rout_temp[5];
        }
        if (rout_temp[6] == "Y") {
            tem_route.codeshare_ = false;
        }
        tem_route.codeshare_ = true;
        tem_route.equipment_ = rout_temp[8];
        routes_vector.push_back(tem_route);
    }
}

bool filereading::check_num(string var) {
    try {
        double tem = stold(var);
    } catch (...) {
        return false;
    }
    return true;
}

string filereading::remove_quote(string substr) {
    if (substr[0] == '\"' && substr[substr.length() - 1] == '\"') {
        substr.erase(substr.begin());
        substr.erase(substr.end() - 1);
    }
    return substr;
}