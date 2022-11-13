#include "Airport.h"

airport::airport() {
    airport_id_ = 0;
    name_ = "";
    city_ = "";
    country_ = "";
    IATA_ = "";
    ICAO_ = "";
    latitude_ = 0;
    longtitude_ = 0;
    altitude_ = 0;
    timezone_ = "";
}
airport::airport(int airport_id,
        string name,
        string city,
        string country,
        string IATA,
        string ICAO,
        double latitude,
        double longtitude,
        double altitude){
            airport_id_ = airport_id;
            name_ = name;
            city_ = city;
            country_ = country;
            IATA_ = IATA;
            ICAO_ = ICAO;
            latitude_ = latitude;
            longtitude_ = longtitude;
            altitude_ = altitude;
        }
        
void airport::set_airport_id(int airport_id) {
    airport_id_ = airport_id;
}
void airport::set_name(string name) {
    name_ = name;
}
void airport::set_city(string city) {
    city_ = city;
}
void airport::set_country(string country) {
    country_ = country;
}
void airport::set_IATA(string IATA) {
    IATA_ = IATA;
}
void airport::set_ICAO(string ICAO) {
    ICAO_ = ICAO;
}
void airport::set_latitude(double latitude) {
    latitude_ = latitude;
}
void airport::set_longtitude(double longtitude) {
    longtitude_ = longtitude;
}
void airport::set_altitude(double altitude) {
    altitude_ = altitude;
}

int airport::airport_id() {
    return airport_id_
}
string airport::name() {
    return name_;
}
string airport::city() {
    return city_;
}
string airport::country() {
    return country_;
}
string airport::IATA() {
    return IATA_;
}
string airport::ICAO() {
    return ICAO_;
}
double airport::latitude() {
    return latitude_;
}
double airport::longtitude() {
    return longtitude_;
}
double airport::altitude() {
    return altitude_;
}