// #include "Utilities.h"


// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// #include <cctype>
// #include <algorithm>
// #include <queue>
// #include <cmath>

// #define PI 3.14159265358979323846
// #define RADIO_TERRESTRE 6372797.56085
// #define GRADOS_RADIANES PI / 180



// // using namespace std;

// // // int graph::isNotVisited(int x, std::vector<int>& path)
// // // {
// // //     int size = path.size();
// // //     for (int i = 0; i < size; i++)
// // //         if (path[i] == x)
// // //             return 0;
// // //     return 1;
// // // }

// // void graph::BFS(vector<vector<int> >& g, int dep, int dst) {
// //     queue<vector<int> > q;
// //     vector<int> path;
// //     vector<vector<int>> route;
// //     path.push_back(dep);
// //     q.push(path);
// //     while (!q.empty()) {
// //         path = q.front();
// //         q.pop();
// //         int last = path[path.size() - 1];
// //         // if last vertex is the desired destination
// //         // then print the path
// //         if (last == dst)
// //             route.push_back(path);
// //         // traverse to all the nodes connected to
// //         // current vertex and push new path to queue
// //         for (unsigned i = 0; i < g[last].size(); i++) {
// //             if (isNotVisited(g[last][i], path)) {
// //                 vector<int> newpath(path);
// //                 newpath.push_back(g[last][i]);
// //                 q.push(newpath);
// //             }
// //         }
// //     }
// //     for(unsigned i = 0; i < route.size();i ++) {
// //         for(unsigned j = 0 ; j < route[i].size(); j++) {
// //             cout<< route[i][j] << " ";
// //         }
// //         cout<< endl;
// //     }
// // }


// double calculateDistance(airport source, airport destination){
//     //get the latitude and longitude of the source and destination airports
//     double lat1 = source.get_latitude();
//     double lon1 = source.get_longitude();
//     double lat2 = destination.get_latitude();
//     double lon2 = destination.get_longitude();
//     //convert the latitude and longitude to radians
//     lat1 = lat1 * GRADOS_RADIANES;
//     lon1 = lon1 * GRADOS_RADIANES;
//     lat2 = lat2 * GRADOS_RADIANES;
//     lon2 = lon2 * GRADOS_RADIANES;

//     double haversine = (pow(sin((1.0 / 2) * (lat2 - lat1)), 2)) + ((cos(lat1)) * (cos(lat2)) * (pow(sin((1.0 / 2) * (lon2 - lon1)), 2)));
//     double temp = 2 * asin(min(1.0, sqrt(haversine)));
//     double distancia_puntos = RADIO_TERRESTRE * temp;

//     return distancia_puntos;


// }

// airport FindAirportById (int id, vector<airport> airport_list) {
//     for (unsigned i = 0; i < airport_list.size(); i++) {
//         if (airport_list[i].get_airport_id() == id) {
//             return airport_list[i];
//         }
//     }
//     return airport();
// }
