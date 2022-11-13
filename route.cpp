#include "route.h"

route::route() {
    airline_ = "";
    airline_id_ = 0;
    source_airport_ "";
    source_airport_id_ = 0;
    destination_airport_ = "";
    destination_airport_id_ = 0;
    codeshare_ = false;
    equipment = "";
}

rout::route(string airline,
    int airline_id,
    string source_airport,
    int source_airport_id,
    string destination_airport,
    int destination_airport_id,
    bool codeshare,
    string equipment) {
        airline_ = airline;
        airline_id_ = airline_id;
        source_airport_ = source_airport;
        source_airport_id_ = source_airport_id;
        destination_airport_ = destination_airport;
        destination_airport_id_ = destination_airport_id;
        codeshare_ = codeshare;
        equipment_ = equipment;
    }

void rout::set_airline(string airline) {
    airline_ = airline;
}

void route::set_airline_id(int airline_id) {
    airline_id_ = airline_id;
}

void route::set_source_airport(string source_airport) {
    source_airport_ = source_airport;
}

void route::set_source_airport_id(int source_airport_id) {
    source_airport_id_ = source_airport_id;
}

void route::set_destination_airport(string destination_airport) {
    destination_airport_ = destination_airport;
}

void route::set_destination_airport_id(int destination_airport_id) {
    destination_airport_id_ = destination_airport_id;
}

void route::set_codeshare(bool codeshare) {
    codeshare_ = codeshare;
}

void route::set_equipment(string equipment_) {
    equipment_ = equipment;
}

string route::get_airline() [
    return airline_;
]
int route::get_airline_id() {
    return airline_id_;
}
string route::get_source_airport() {
    return source_airport_;
}
int route::get_source_airport_id() {
    return source_airport_id_;
}
string route::get_destination_airport() {
    return destination_airport_;
}
int route::get_destination_airport_id() {
    return destination_airport_id_;
}
bool route::get_codeshare() {
    return codeshare_;
}
string route::get_equipment() {
    return equipment_;
}
