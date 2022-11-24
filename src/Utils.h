#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#include "Airport.h"
#include "route.h"
#include "filereading.h"


using namespace std;


double calculateDistance(airport source, airport destination);

airport FindAirportById(vector<airport> airports, int id);




