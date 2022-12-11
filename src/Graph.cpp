
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
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
    g.resize(14111);
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
//
void Graph::SetBfsGraph(vector<airport> a, vector<route> r){
    airport_list = a;
    route_list = r;
    for (unsigned int i = 0; i < r.size(); i++) {
        int tem_destination_id = r[i].get_destination_airport_id();
        int tem_source_id = r[i].get_source_airport_id();
        if (r[i].get_source_airport_id() == 0) {
            tem_source_id = IATA_to_airpot_id(r[i].get_source_airport());
        }
        if (r[i].get_destination_airport_id() == 0) {
            tem_destination_id = IATA_to_airpot_id(r[i].get_destination_airport());
        }
        g[tem_source_id].push_back(tem_destination_id);
    }
}

int Graph::IATA_to_airpot_id(string IATA) {
    for (unsigned i = 0; i < airport_list.size(); i++) {
        if (IATA == airport_list[i].get_IATA()) {
            return airport_list[i].get_airport_id();
        }
    }
    return 0;
}
//
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

int Graph::get_num_vertices () {
    return num_vertices;
}

std::vector<airport> Graph::getAirportList() {
    return airport_list;
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
//used to find all possible routes between two airports
//parameters: departure airport, destination airport
void Graph::BFS(int source, int destination) {
    queue<vector<int> > q;
    vector<int> path;
    vector<vector<int>> route;
    path.push_back(source);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        
        if (last == destination)
            route.push_back(path);
        
        for (unsigned i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
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

void Graph::SetBfsTestGraph(vector<vector<int> > test) {
    g = test;
}


//same as the BFS except that BFS print paths TestBFS return paths
vector<vector<int>> Graph::TestBFS(int source, int destination) {
    queue<vector<int> > q;
    vector<int> path;
    vector<vector<int>> route;
    path.push_back(source);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        
        if (last == destination)
            route.push_back(path);
        
        for (unsigned i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
    return route;
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
    //if the destination is not reachable
    if (distance[destination] == INT_MAX) {
        cout << "No route found" << endl;
    }



    //print out the shortest distance
    cout << "The shortest distance between " << airport_list[source].get_name() << " and " << airport_list[destination].get_name() << " is " << distance[destination] << " meters." << endl;

    //print out the route
    //reverse the vector for correct order 
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = previous[current];
    }
    reverse(path.begin(), path.end());
    cout << "The route is: " << endl;
    for (unsigned i = 0; i < path.size(); i++) {
        cout <<airport_list[path[i]].get_airport_id() << " "<< airport_list[path[i]].get_name() << endl;
    }


}

//same as previous dijkstra's algorithm, but no printing, instead returns the shortest distance in vector of path airport ids
vector<int> Graph::dijkstraHelper (int source_id, int destination_id) {

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
    //return the route
    //reverse the vector for correct order 
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = previous[current];
    }
    reverse(path.begin(), path.end());
    return path;




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

//same as previous dijkstra's algorithm, but no printing, instead returns the shortest distance between two airports
double Graph::find_Shortest_Distance (int source_id, int destination_id) {
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

    //return the shortest distance
    return distance[destination];




}

//Betweenness Centrality
//finds the most important airports
//parameters: number of airports to find

// void BetweennessCentrality () {
//     //for each edge (u,v) in graph
//     //remove edge (u,v)
//     //run dijkstra's algorithm
//     //for each vertex w on the shortest path from u to v
//     //increment the number of shortest paths that pass through w
//     //add the number of shortest paths that pass through w to the betweenness centrality of w
//     //add edge (u,v) back to the graph
//     //divide the betweenness centrality of each vertex by 2
//     //sort the vertices by betweenness centrality

//     //print the top n vertices





    
// }

//Betweenness Centrality
void Graph::betweennessCentrality () {
    vector<int> weight (num_vertices, 0);

    for (int i = 0; i < num_vertices; i++) {
        for (int x = 0; x < num_vertices; x++) {
            if (x == i) { continue; }
            for (int y = 0; y < num_vertices; y++) {
                if (y == i) { continue; }
                //run dijkstra's algorithm
                vector<int> paths = dijkstraHelper(x, y);

                if (find(paths.begin(), paths.end(), i) != paths.end()) {
                    weight[i]++;
                }
            }
        }
    }
    
    
    cout << "The most important airport is " << airport_list[max(weight)].get_name() << endl;

    
}

vector<size_t> Graph::sort_indices(const vector<double> &v) {
    
      // initialize original index locations
      vector<size_t> idx(v.size());
      iota(idx.begin(), idx.end(), 0);
    
      // sort indices based on comparing values in v
      sort(idx.begin(), idx.end(),
         [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});
    
      return idx;
}




int Graph::max (vector<int> &v) {
    int max = 0;
    int num = 0;
    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
            num = i;
        }
    }
    return num;
}

double Graph::max (vector<double> &v) {
    double max = 0;
    int num = 0;
    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
            num = i;
        }
    }
    return num;
}


//PageRank
//finds the most important airports

vector<size_t> Graph::SimplePageRank(int top) {
    // vector<size_t> Rank;

    // // assume each page has equal weight at the beginning
    // double initial_PR = 1.0/numAirports;
    // vector<double> PR(numAirports,initial_PR);

    // // initialize the number of outbound links for each airport
    // vector<double> L(numAirports,0);
    // for (size_t row = 0; row < numAirports; row++) {
    //     int num_zeros = count(adj_[row].begin(), adj_[row].end(), 0);
    //     L[row] = numAirports-num_zeros;
    // }

    // // update weight of each airport using PR(i) = sum of PR(j)/L(j)
    // //     where j is each airport that has a route ending in i
    // for (size_t i = 0; i < PR.size(); i++) {
    //     double income = 0;
    //     for (size_t j = 0; j < PR.size(); j++) {
    //         if (adj_[j][i]>0) {
    //             income += initial_PR/L[j];
    //         }   
    //     }
    //     PR[i] = income;      
    // }
    // // cout<<endl;
    // // cout<<"PageRank value for each Airport is:"<<endl;
    // // cout<<"    ";
    // // printVec(PR);

    // // sort the weight of airports and keep track of the indices
    // int count = 0;
    // for (auto i: sort_indices(PR)) {
    //     if (count==top) {
    //         break;
    //     }
    //     Rank.push_back(i);
    //     count++;
    // }
    // return Rank;

vector<size_t> Rank;

    double initial_PR = 1.0/airport_list.size();
    vector<double> PR(airport_list.size(),initial_PR);

    vector<double> Links(airport_list.size(),0);
    for (size_t row = 0; row < airport_list.size(); row++) {
        int num_zeros = count(adj_matrix[row].begin(), adj_matrix[row].end(), 0);
        Links[row] = airport_list.size()-num_zeros;
    }
    int num = 0;
    while (num <= 50) {

    for (size_t i = 0; i < PR.size(); i++) {
        double income = 0;
        for (size_t j = 0; j < PR.size(); j++) {
            if (adj_matrix[j][i]>0) {
                income += PR[j]/Links[j];
            }   
        }
        PR[i] = income;
    }
    num++;
    }


    
    int count = 0;
    for (auto i: sort_indices(PR)) {
        if ( i == 0) {
            continue;
        }
        if (count==top) {
            
            break;
        }
        Rank.push_back(i);
        count++;
    }
    return Rank;
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

// This for the testcase
//Similar to SimplePageRank, but it only run 3 loop
vector<size_t> Graph::TestSimplePageRank(int top) {
    vector<size_t> Rank;

    double initial_PR = 1.0/airport_list.size();
    vector<double> PR(airport_list.size(),initial_PR);

    vector<double> Links(airport_list.size(),0);
    for (size_t row = 0; row < airport_list.size(); row++) {
        int num_zeros = count(adj_matrix[row].begin(), adj_matrix[row].end(), 0);
        Links[row] = airport_list.size()-num_zeros;
    }
    int num = 0;
    while (num <= 3) {

    for (size_t i = 0; i < PR.size(); i++) {
        double income = 0;
        for (size_t j = 0; j < PR.size(); j++) {
            if (adj_matrix[j][i]>0) {
                income += PR[j]/Links[j];
            }   
        }
        PR[i] = income;
    }
    num++;
    }


    
    int count = 0;
    for (auto i: sort_indices(PR)) {
        if ( i == 0) {
            continue;
        }
        if (count==top) {
            
            break;
        }
        Rank.push_back(i);
        count++;
    }
    return Rank;
}
