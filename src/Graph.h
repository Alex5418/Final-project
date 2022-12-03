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
#include "Graph.h"


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
    unordered_map <int, int> airport_id_to_index;

    //or maybe i can map each index to airport object?
    //the index of the airport in the matrix and the airport id is not one-to-one
    //so i need to create a map to map airport index to airport object
    //then when adding vertices to the graph, the index of matrix become the key of the map
    //and the value of the map is the airport object
    unordered_map<int, airport> airport_index_to_airport; 


    //Keep a global or a static variable count to store the count
    //of the number of times the function is called
    //and print the count when the program terminates.
    //static int count;

    //BFS's graph
    vector<vector<int> > g;



public:

    Graph(int v); // constructor
    Graph(vector<airport> a, vector<route> r); //

    // use to create BFS's graph
    void SetBfsGraph(vector<airport> a, vector<route> r);
    int IATA_to_airpot_id(string IATA);

    int get_num_vertices();
    

    void MapAirportIdToIndex(); // map airport id to index
    void MapAirportIndexToAirport(); // map airport index to airport object

    void addVertex(int v);

    void addEdge(int v, int w);

    void addEdge(int v, int w, int weight);

    void updateEdge(int v, int w, int weight);

    bool isConnected(int v, int w);

    vector<airport> getAirportList();

    double getDistance(int v, int w);

    void printDistance(int v, int w);

    void printConnectedAirports(int v);

    void BFS(int source, int destination); //traverse the graph, find all the airports that can be reached from the source airport and all possible routes

    /*
    Create a recursive function that takes the index of a node of a graph and the destination index. Keep a global or a static variable count to store the count. 
    Keep a record of the nodes visited using a visited array and while returning mark the current node to be unvisited to discover other paths.
    if the current node is the destination then increase the count.
    Else for all the adjacent nodes, i.e. nodes that are accessible from the current node, call the recursive function with the index of the adjacent node and the destination.
    Print the Count as the required answer.
    */
    int count_paths(int src, int dst, int vertices);
    void path_counter(int src, int dst, int& path_count, vector<bool>& visited);

    void printGraph(string filename);

    void dijkstra(int source_id, int destination_id); //Dijkstra's algorithm, find the shortest path from source to destination
    vector<int> dijkstraHelper(int source, int destination); //Dijkstra's algorithm without printing the path
    double find_Shortest_Distance(int source, int destination); //Dijkstra's algorithm, find the shortest path from source to destination
    int findMinDistance(vector<int> distance, vector<int> visited);

    void printShortestPath(int source_id, int destination_id);

    bool isNotVisited(int x, vector<int>& path);

    airport FindAirportById(vector<airport> airports, int id);

    void FindAllRoutes(int source_id, int destination_id);
    void FindAllRoutesHelper(int source_id, int destination_id, vector<int>& path, vector<int>& visited);

    //Betweenness Centrality
    void betweennessCentrality();

    int max(vector<int> &v);
    double max(vector<double> &v);

    

    //pagerank algorithm
    //find the most important airport by pagerank algorithm
    vector<size_t> SimplePageRank(int top = 10);

    vector<size_t> sort_indices(const vector<double> &v);

    //setter
    void set_num_vertices(int v);

    void set_num_edges(int e);

    void set_adj_matrix(vector<vector<int>> adj);

    void set_airport_list(vector<airport> a);

    void set_route_list(vector<route> r);


    // ~Graph();
};


