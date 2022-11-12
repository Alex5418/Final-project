#include "Airport.h"

airport::airport() {}
airport::airport(int airport_id,
        string name,
        string city,
        string country,
        string IATA,
        string ICAO,
        double latitude,
        double longtitude,
        double altitude,
        string timezone){
            airport_id_ = airport_id;
            name_ = name;
            city_ = city;
            country_ = country;
            IATA_ = IATA;
            ICAO_ = ICAO;
            latitude_ = latitude;
            longtitude_ = longtitude;
            altitude_ = altitude;
            timezone_ = timezone;
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
void airport::set_IATA() {
    
}
void airport::set_ICAO();
void airport::set_latitude();
void airport::set_longtitude();
void airport::set_altitude();
void airport::set_timezone();
int airport::airport_id();
string airport::name();
string airport::city();
string airport::country();
string airport::IATA();
string airport::ICAO();
double airport::latitude();
double airport::longtitude();
double airport::altitude();
string airport::timezone();