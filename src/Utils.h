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
public:
    Graph(int numVertices);
    void addEdge(int source, int destination);
    void BFS(int startVertex);
    // void printShortestDistance(int sourceVertex, int destinationVertex);

    ~Graph();
};



