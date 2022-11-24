#pragma once
#include <string>
using namespace std;
class airport {
    public:
        airport();
        airport(int airport_id,
        string name,
        string city,
        string country,
        string IATA,
        string ICAO,
        long double latitude,
        long double longtitude,
        long double altitude,
        string timezone);
        
        void set_airport_id(int airport_id);
        void set_name(string name);
        void set_city(string city);
        void set_country(string country);
        void set_IATA(string IATA);
        void set_ICAO(string ICAO);
        void set_latitude(double latitude);
        void set_longtitude(double longtitude);
        void set_altitude(double altitude);

        // string get_airport_id();

        int get_airport_id();
        string get_name();
        string get_city();
        string get_country();
        string get_IATA();
        string get_ICAO();
        double get_latitude();
        double get_longtitude();
        double get_altitude();
    private:
        int airport_id_;
        string name_;
        string city_;
        string country_;
        string IATA_;
        string ICAO_;
        long double latitude_;
        long double longtitude_;
        long double altitude_;
};