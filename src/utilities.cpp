#include "utilities.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <limits.h>
using namespace std;

int graph::isNotVisited(int x, std::vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}

void graph::BFS(vector<vector<int> >& g, int dep, int dst) {
    queue<vector<int> > q;
    vector<int> path;
    vector<vector<int>> route;
    path.push_back(dep);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
        
        if (last == dst)
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

int graph::minDistance(int dist[], bool sptSet[])
{
 
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < 14111; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 

void graph::printSolution(int dist[14111], int d)
{
    cout << "Vertex \t Distance from Source" << endl;
    cout << d << " \t\t" << dist[d] << endl;
}
 
void graph::dijkstra(vector<vector<double>> graph, int src, int d)
{
    int dist[14111]; 
 
    bool sptSet[14111]; 
    for (int i = 0; i < 14111; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;

    for (int count = 0; count < 14111 - 1; count++) {
        int u = minDistance(dist, sptSet);
 
        
        sptSet[u] = true;
 
        
        for (int v = 0; v < 14111; v++)
 
            
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    
    printSolution(dist, d);
}
 