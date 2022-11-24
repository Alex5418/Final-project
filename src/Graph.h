#pragma once
#include <string>
#include <vector>

#include "Airport.h"
#include "route.h"
#include "utilities.h"
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
    vector<route> route_list; // list of routes


public:

    Graph(int v); // constructor
    Graph(vector<airport> a, vector<route> r); //

    void addVertex(int v);

    void addEdge(int v, int w);

    bool isConnected(int v, int w);

    double getDistance(int v, int w);

    void printConnectedAirports(int v);

    void BFS(int source, int destination);

    void printGraph(string filename);

    void dijkstra(int s);

    bool isNotVisited(int x, vector<int>& path);

    //setter
    void set_num_vertices(int v);

    void set_num_edges(int e);

    void set_adj_matrix(vector<vector<int>> adj);

    void set_airport_list(vector<airport> a);

    void set_route_list(vector<route> r);


    // ~Graph();
};


