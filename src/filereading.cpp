
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <math.h>
using namespace std;

#include "filereading.h"
#include "Airport.h"
#include "route.h"

#define PI 3.14159265358979323846
#define RADIO_TERRESTRE 6372797.56085
#define GRADOS_RADIANES PI / 180

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
            tem_airport.set_latitude(stod(temp[6])); //
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

vector<airport> filereading::getAirportVector() {
    return airports_vector;
}

vector<route> filereading::getRouteVector() {
    return routes_vector;
}


// double filereading::distance(double lat1, double long1, double lat2, double long2){
//     double haversine;
//     double temp;
//     double distancia_puntos;

//     lat1  = lat1  * GRADOS_RADIANES;
//     long1 = long1 * GRADOS_RADIANES;
//     lat2  = lat2  * GRADOS_RADIANES;
//     long2 = long2 * GRADOS_RADIANES;

//     haversine = (pow(sin((1.0 / 2) * (lat2 - lat1)), 2)) + ((cos(lat1)) * (cos(lat2)) * (pow(sin((1.0 / 2) * (long2 - long1)), 2)));
//     temp = 2 * asin(min(1.0, sqrt(haversine)));
//     distancia_puntos = RADIO_TERRESTRE * temp;

//    return distancia_puntos;
// }

double filereading::distance(double latitude_new, double longitude_new, double latitude_old, double longitude_old)
{
    double  lat_new = latitude_old * GRADOS_RADIANES;
    double  lat_old = latitude_new * GRADOS_RADIANES;
    double  lat_diff = (latitude_new-latitude_old) * GRADOS_RADIANES;
    double  lng_diff = (longitude_new-longitude_old) * GRADOS_RADIANES;

    double  a = sin(lat_diff/2) * sin(lat_diff/2) +
                cos(lat_new) * cos(lat_old) *
                sin(lng_diff/2) * sin(lng_diff/2);
    double  c = 2 * atan2(sqrt(a), sqrt(1-a));

    double  distance = RADIO_TERRESTRE * c;
    
    // std::cout <<__FILE__ << "." << __FUNCTION__ << " line:" << __LINE__ << "  "
    
    return distance/1000;
}

double filereading::distance(int ID1, int ID2) {
    double lat1, long1, lat2, long2;
    bool a = false;
    bool b = false;
    for (unsigned i = 0; i < airports_vector.size(); i++) {
        if (ID1 == airports_vector[i].get_airport_id()) {
            lat1 = airports_vector[i].get_latitude();
            long1 = airports_vector[i].get_longtitude();
            a = true;
        }
        if (ID2 == airports_vector[i].get_airport_id()) {
            lat2 = airports_vector[i].get_latitude();
            long2 = airports_vector[i].get_longtitude();
            b = true;
        }
        if (a == true && b == true) break;
    }
    return distance(lat1, long1, lat2, long2);
}

int filereading::get_route_size() {
    return routes_vector.size();
}

int filereading::IATA_to_airpot_id(string IATA) {
    for (unsigned i = 0; i < airports_vector.size(); i++) {
        if (IATA == airports_vector[i].get_IATA()) {
            return airports_vector[i].get_airport_id();
        }
    }
    return 0;
}
