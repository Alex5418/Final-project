#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include "Airport.h"
#include "route.h"
#include "Utils.h"
#include "filereading.h"

using namespace std;


/**
 * @brief This class is used to construct a graph of airports and routes
 * 
 * 
 * 
 */

class Graph
{
private:
    /* data */

    int num_vertices = 14110; // number of vertices in the graph
    int num_edges; // number of edges in the graph
    vector<vector<int>> adj_matrix; // adjacency matrix
    vector<airport> airport_list; // list of airports
    vector<route> route_list; // list of routes id 

    //airport id need to be accessed by index
    //airport id and the index of the airport in the matrix is not the same
    //airport id is the id of the airport in the airport.txt file
    //airport index is the index of the airport in the matrix
    //so i need to create a map to map airport id  to airport_list index
    std::unordered_map <int, int> airport_id_to_index;



public:

    Graph(int v); // constructor
    Graph(vector<airport> a, vector<route> r); //

    

    void MapAirportIdToIndex(); // map airport id to index

    void addVertex(int v);

    void addEdge(int v, int w);

    void addEdge(int v, int w, int weight);

    void updateEdge(int v, int w, int weight);

    bool isConnected(int v, int w);

    double getDistance(int v, int w);

    void printDistance(int v, int w);

    void printConnectedAirports(int v);

    void BFS(int source, int destination);

    void printGraph(string filename);

    void dijkstra(int s);

    bool isNotVisited(int x, vector<int>& path);

    airport FindAirportById(vector<airport> airports, int id);

    //setter
    void set_num_vertices(int v);

    void set_num_edges(int e);

    void set_adj_matrix(vector<vector<int>> adj);

    void set_airport_list(vector<airport> a);

    void set_route_list(vector<route> r);


    // ~Graph();
};


