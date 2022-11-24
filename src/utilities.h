#pragma once
#include <string>
#include <vector>
#include <queue>
using namespace std;

class graph {
public:
    int isNotVisited(int x, vector<int>& path);
    void BFS(vector<vector<int> >& g, int dep, int dst);
    int minDistance(int dist[], bool sptSet[]);
    void printSolution(int dist[14111], int d);
    void dijkstra(vector<vector<double>> graph, int src, int d);
private:
    
};
