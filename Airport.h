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
        double latitude,
        double longtitude,
        double altitude,
        string timezone);
        
        void set_airport_id();
        void set_name();
        void set_city();
        void set_country();
        void set_IATA();
        void set_ICAO();
        void set_latitude();
        void set_longtitude();
        void set_altitude();
        void set_timezone();
        int airport_id();
        string name();
        string city();
        string country();
        string IATA();
        string ICAO();
        double latitude();
        double longtitude();
        double altitude();
        string timezone();
    private:
        int airport_id_;
        string name_;
        string city_;
        string country_;
        string IATA_;
        string ICAO_;
        double latitude_;
        double longtitude_;
        double altitude_;
        string timezone_;
}