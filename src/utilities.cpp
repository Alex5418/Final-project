#include "utilities.h"
#include <iostream>
#include <fstream>
#include <cctype>
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
        // if last vertex is the desired destination
        // then print the path
        if (last == dst)
            route.push_back(path);
        // traverse to all the nodes connected to
        // current vertex and push new path to queue
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
