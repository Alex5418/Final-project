#pragma once
#include <string>
using namespace std;
class route {
    public:
        route();
        route(string airline,
        int airline_id,
        string source_airport,
        int source_airport_id,
        string destination_airport,
        int destination_airport_id,
        bool codeshare,
        string equipment);
        
        void set_airline(string airline);
        void set_airline_id(int airline_id);
        void set_source_airport(string source_airport);
        void set_source_airport_id(int source_airport_id);
        void set_destination_airport(string destination_airport);
        void set_destination_airport_id(int destination_airport_id);
        void set_codeshare(bool codeshare);
        void set_equipment(string equipment);

        string get_airline();
        int get_airline_id();
        string get_source_airport();
        int get_source_airport_id();
        string get_destination_airport();
        int get_destination_airport_id();
        bool get_codeshare();
        string get_equipment();
    private:
        string airline_;
        int airline_id_;
        string source_airport_;
        int source_airport_id_;
        string destination_airport_;
        int destination_airport_id_;
        bool codeshare_;
        //stops are not considered since all stops of airline are 0
        string equipment_;
};
