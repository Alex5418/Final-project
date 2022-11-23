#pragma once
#include <string>
#include <vector>
using namespace std;

class graph {
public:
    int isNotVisited(int x, vector<int>& path);
    void BFS(vector<vector<int> >& g, int dep, int dst);
    int bfs();
private:
    const vector<Airport>* airports_ptr_;
    const vector<Route>* routes_ptr_;
};