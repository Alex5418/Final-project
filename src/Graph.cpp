
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

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
    // if (num_vertices < (int)a.size()) {
    //     num_vertices = a.size();
    // }
    num_vertices = a.size();
    num_edges = r.size();
    adj_matrix.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        adj_matrix[i].resize(num_vertices);
    }
    airport_list = a;
    route_list = r;
    MapAirportIdToIndex();
    for (int i = 0; i < num_edges; i++) {
        int source = route_list[i].get_source_airport_id();
        int destination = route_list[i].get_destination_airport_id();
        double distance = calculateDistance(FindAirportById(airport_list, source), FindAirportById(airport_list, destination));
        addEdge(airport_id_to_index[source], airport_id_to_index[destination], distance);
    }
}

void Graph::MapAirportIdToIndex () {
    for (int i = 0; i < num_vertices; i++) {
        airport_id_to_index[airport_list[i].get_airport_id()] = i;
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
    queue<vector<int>> q;
    vector<int> path;
    vector<vector<int>> route;
    path.push_back(source);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        // if last vertex is the desired destination
        // then print the path
        if (last == destination)
            route.push_back(path);
        // traverse to all the nodes connected to
        // current vertex and push new path to queue
        for (unsigned i = 0; i < adj_matrix[last].size(); i++) {
            if (isNotVisited(adj_matrix[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(adj_matrix[last][i]);
                q.push(newpath);
            }
        }
    }
    for(unsigned i = 0; i < route.size();i ++) {
        for(unsigned j = 0 ; j < route[i].size(); j++) {
            cout<< route[i][j] << " ";
        }
        cout<< endl;
    }
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
void Graph::printGraph (string filename) {
    ofstream outfile;
    outfile.open(filename);
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            outfile << adj_matrix[i][j] << " ";
        }
        outfile << endl;
    }
    outfile.close();
}



bool Graph::isNotVisited(int x, vector<int>& path) {
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

//

