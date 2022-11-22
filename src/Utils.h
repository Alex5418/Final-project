#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#include "Airport.h"

class Graph
{
private:
    /* data */
    int numVertices;

    // adjacency list
    std::vector<std::vector<int>> adjLists;

    // visited array
    std::vector<bool> visited;

    // parent array
    std::vector<int> parent;

    // distance array (weight)
    std::vector<int> distance;



public:
    Graph(int numVertices);
    void addEdge(int source, int destination);
    void BFS(int startVertex);  // Breadth First Search to traverse the graph
    void Djikstra(int sourceVertex, int destinationVertex); // Djikstra's algorithm to find the shortest path
    void printShortestDistance(int sourceVertex, int destinationVertex);


    ~Graph();
};



