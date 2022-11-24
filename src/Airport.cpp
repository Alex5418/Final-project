#include "Airport.h"

airport::airport() {
    airport_id_ = 0;
    name_ = "";
    city_ = "";
    country_ = "";
    IATA_ = "";
    ICAO_ = "";
    latitude_ = 0;
    longitude_ = 0;
    altitude_ = 0;
    // timezone_ = "";
}

airport::airport(int airport_id,
        string name,
        string city,
        string country,
        string IATA,
        string ICAO,
        long double latitude,
        long double longtitude,
        long double altitude,
        string timezone) {
            airport_id_ = airport_id;
            name_ = name;
            city_ = city;
            country_ = country;
            IATA_ = IATA;
            ICAO_ = ICAO;
            latitude_ = latitude;
            longitude_ = longtitude;
            altitude_ = altitude;
            // timezone_ = timezone;
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
void airport::set_longtitude(double longitude) {
    longitude_ = longitude;
}
void airport::set_altitude(double altitude) {
    altitude_ = altitude;
}

int airport::get_airport_id() {
    return airport_id_;
}

string airport::get_name() {
    return name_;
}
string airport::get_city() {
    return city_;
}
string airport::get_country() {
    return country_;
}
string airport::get_IATA() {
    return IATA_;
}
string airport::get_ICAO() {
    return ICAO_;
}
double airport::get_latitude() {
    return latitude_;
}
double airport::get_longitude() {
    return longitude_;
}
double airport::get_altitude() {
    return altitude_;
}