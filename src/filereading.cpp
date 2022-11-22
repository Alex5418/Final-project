
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

#include "filereading.h"
#include "Airport.h"
#include "route.h"

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
        airport tem_airport;
        for (size_t i = 0; i < temp.size(); i++) {
            temp[i] = remove_quote(temp[i]);
        }
        if (check_num(temp[0])) {
            tem_airport.set_airport_id(stoi(temp[0]));
        }
        tem_airport.set_name(temp[1]);
        tem_airport.set_city(temp[2]);
        tem_airport.set_country(temp[3]);
        tem_airport.set_IATA(temp[4]);
        tem_airport.set_ICAO(temp[5]);
        if (check_num(temp[6])) {
            tem_airport.set_latitude(stold(temp[6]));
        } 
        if (check_num(temp[7])) {
            tem_airport.set_longtitude(stold(temp[7]));
        }
        if (check_num(temp[8])) {
            tem_airport.set_altitude(stold(temp[8]));
        }
        airports_vector.push_back(tem_airport);
    }
}
        
void filereading::readairroute(string file_route) {
    ifstream ifs{file_route};
    for(string line; getline(ifs, line); line = ""){
        vector<string> route_temp = filereading::GetSubstrs(line, ',');
        route temp_route;
        temp_route.set_airline(route_temp[0]);

        if (check_num(route_temp[1])) {
            temp_route.set_airline_id(stoi(route_temp[1]));
        }
        temp_route.set_source_airport(route_temp[2]);
        if (check_num(route_temp[3])) {
            temp_route.set_source_airport_id(stoi(route_temp[3]));
        }
        temp_route.set_destination_airport(route_temp[4]);
        if (check_num(route_temp[5])) {
            temp_route.set_destination_airport_id(stoi(route_temp[5]));
        }
        if (route_temp[6] == "Y") {
            temp_route.set_codeshare(false);
        }
        temp_route.set_codeshare(true);
        temp_route.set_equipment(route_temp[8]);
        routes_vector.push_back(temp_route);

    }
}

bool filereading::check_num(string var) {
    try {
        long double tem = stold(var);
    } catch (...) {
        return false;
    }
    return true;
}

std::string filereading::remove_quote(string substr) {
    substr.erase(remove(substr.begin(),substr.end(),'\"'),substr.end());
    return substr;
}

void filereading::print_airport() {
    for (size_t i = 0; i < airports_vector.size(); i++) {
        cout << airports_vector[i].airport::get_name()<< endl;
    }
}

void filereading::print_route() {
    for (size_t i = 0; i < routes_vector.size(); i++) {
        cout << routes_vector[i].route::get_airline()<< endl;
    }
}

double Readfile::distance(double lat1, double long1, double lat2, double long2) {
    double d_lat = abs(lat1-lat2);
    double d_long = abs(long1-long2);
    double distance = sqr((pow(d_lat), 2)+ (pow(d_long), 2));
    return distance;
}
