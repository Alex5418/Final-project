#pragma once
#include <string>
#include <vector>
using namespace std;

class graph {
public:
    int isNotVisited(int x, vector<int>& path);
    void BFS(vector<vector<int> >& g, int dep, int dst);
    
private:
    
};
