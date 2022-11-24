
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <unordered_map>
#include <limits.h>

#include "Graph.h"
#include "Airport.h"
#include "route.h"
#include "filereading.h"
#include "Utils.h"

using namespace std;

Graph::Graph (int v) {
    num_vertices = v;
    num_edges = 0;
    adj_matrix.resize(v);
    for (int i = 0; i < v; i++) {
        adj_matrix[i].resize(v);
    }
}

//Generate graph based on vector of airports and routes
//Each airport is a vertex, and each route is an edge
//The weight of each edge is the distance between two airports
Graph::Graph (vector<airport> a, vector<route> r) {
    num_vertices = a.size();
    num_edges = r.size();
    adj_matrix.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i].resize(num_vertices);
    }
    airport_list = a;
    route_list = r;
    MapAirportIdToIndex();
    MapAirportIndexToAirport();
    for (int i = 0; i < num_edges; i++) {
        int source = airport_id_to_index[route_list[i].get_source_airport_id()];
        int destination = airport_id_to_index[route_list[i].get_destination_airport_id()];
        double distance = calculateDistance(airport_index_to_airport[source], airport_index_to_airport[destination]);
        adj_matrix[source][destination] = distance;
        adj_matrix[destination][source] = distance;
    }
}

void Graph::MapAirportIdToIndex () {
    for (int i = 0; i < num_vertices; i++) {
        airport_id_to_index[airport_list[i].get_airport_id()] = i;
    }
}

void Graph::MapAirportIndexToAirport() {
    for (int i = 0; i < num_vertices; i++) {
        airport_index_to_airport[i] = airport_list[i];
    }
}

airport Graph::FindAirportById(vector<airport> airports, int id) {
    for (int i = 0; i < (int)airports.size(); i++) {
        if (airports[i].get_airport_id() == id) {
            return airports[i];
        }
    }
    return airport();
}



void Graph::addVertex(int v) {
    if (v > num_vertices) {
        adj_matrix.resize(v);
        for (int i = 0; i < v; i++) {
            adj_matrix[i].resize(v); // resize the columns
        }
        num_vertices = v; // update the number of vertices
    }
}


//connects two vertices (connect airports by routes)
void Graph::addEdge(int v, int w) {
    if (v < num_vertices && w < num_vertices) {
        adj_matrix[v][w] = 1;
        adj_matrix[w][v] = 1;
        num_edges++;
    }
}

void Graph::addEdge(int v, int w, int weight) {
    if (v < num_vertices && w < num_vertices) {
        adj_matrix[v][w] = weight;
        adj_matrix[w][v] = weight;
        num_edges++;
    }
}

void Graph::updateEdge (int v, int w, int weight) {
    if (v < num_vertices && w < num_vertices) {
        adj_matrix[v][w] = weight;
        adj_matrix[w][v] = weight;
    }
}

//calculate distance between two airports


//checks if two vertices are connected
bool Graph::isConnected(int v, int w) {
    if (v < num_vertices && w < num_vertices) {
        if (adj_matrix[v][w] >= 1) {
            return true;
        }
    }
    return false;
}

//prints all airports connected to a given airport
void Graph::printConnectedAirports(int v) {
    if (v < num_vertices) {
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[v][i] >= 1) {
                cout << airport_list[i].get_name() << endl;
            }
        }
    }
}

//breadth first search
//finds all possible routes between two airports
//parameters: departure airport, destination airport
void Graph::BFS (int source, int destination) {
    vector<int> visited;
    queue<int> q;
    q.push(source);
    visited.push_back(source);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < num_vertices; i++) {
            if (adj_matrix[current][i] >= 1 && find(visited.begin(), visited.end(), i) == visited.end()) {
                q.push(i);
                visited.push_back(i);
            }
        }
    }
    if (find(visited.begin(), visited.end(), destination) != visited.end()) {
        cout << "There is a route between " << airport_list[source].get_name() << " and " << airport_list[destination].get_name() << endl;
    } else {
        cout << "There is no route between " << airport_list[source].get_name() << " and " << airport_list[destination].get_name() << endl;
    }
    //print out all airports in the route
    cout << "The route is: " << endl;
    for (int i = 0; i < (int)visited.size(); i++) {
        cout << airport_list[visited[i]].get_airport_id() << " ";
    }

}


//dijkstra's algorithm
//finds the shortest path between two airports
/*
for each vertex v in Graph:             // Initialization
    dist[v] := infinity ;              // Unknown distance function from source to v
    previous[v] := undefined ;         // Previous node in optimal path from source
    set all vertices to unvisited
    while destination not explored;
    v = least-valued unexplored vertex
    set v to visited
    for each edge (v,w):
        if dis[v] + len[v,w] < dist[w]:
            dist[w] := dis[v] + len[v,w]  // A shorter path to w has been found
            previous[w] := v
*/
void Graph::dijkstra(int source_id, int destination_id) {

    //first convert airport id to index in matrix
    int source = airport_id_to_index[source_id];
    int destination = airport_id_to_index[destination_id];

    //create a vector to store the shortest distance from source to each airport
    vector<double> distance;
    distance.resize(num_vertices);
    //for each vertex, set the distance to infinity
    for (int i = 0; i < num_vertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    vector<int> previous;
    previous.resize(num_vertices);
    previous[source] = -1;
    vector<bool> visited;
    visited.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }

    //while the destination has not been visited
    while (!visited[destination]) {
        //find the vertex with the least distance from the source
        int least_distance = INT_MAX;
        int least_distance_index = -1;
        for (int i = 0; i < num_vertices; i++) {
            if (!visited[i] && distance[i] < least_distance) {
                least_distance = distance[i];
                least_distance_index = i;
            }
        }
        //set the vertex with the least distance to visited
        visited[least_distance_index] = true;
        //for each edge (v,w):
        for (int i = 0; i < num_vertices; i++) {
            //if dis[v] + len[v,w] < dist[w]:
            if (adj_matrix[least_distance_index][i] >= 1 && distance[least_distance_index] + adj_matrix[least_distance_index][i] < distance[i]) {
                //dist[w] := dis[v] + len[v,w]  // A shorter path to w has been found
                distance[i] = distance[least_distance_index] + adj_matrix[least_distance_index][i];
                //previous[w] := v
                previous[i] = least_distance_index;
            }
        }
    }



    //print out the shortest distance
    cout << "The shortest distance between " << airport_list[source].get_name() << " and " << airport_list[destination].get_name() << " is " << distance[destination] << " miles." << endl;

}

int Graph::findMinDistance(vector<int> distance, vector<int> visited) {
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < num_vertices; i++) {
        if (find(visited.begin(), visited.end(), i) == visited.end() && distance[i] < min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}




//print distance between two airports
void Graph::printDistance (int v, int w) {
    //first check if the two airports are connected
    if (isConnected(v, w)) {
        cout << "The distance between " << airport_list[v].get_name() << " and " << airport_list[w].get_name() << " is " << adj_matrix[v][w] << " miles." << endl;
    }
    else {
        cout << "The two airports are not connected." << endl;
    }
    if (v < num_vertices && w < num_vertices) {
        cout << adj_matrix[v][w] << endl;
    }
}


//print the graph and output to test folder
//replace the vertices with airport names
void Graph::printGraph (string filename) {
    ofstream outfile;
    outfile.open(filename);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j] >= 1) {
                outfile << airport_list[i].get_name() << " " << airport_list[j].get_name() << " " << adj_matrix[i][j] << endl;
            }
        }
    }
}



bool Graph::isNotVisited(int x, vector<int>& path) {
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}



