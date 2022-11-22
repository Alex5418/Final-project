


#include <cmath>


#include "route.h"
#include "Airport.h"
#include "filereading.h"
#include "Utils.h"

// Breadth fisrt search algorithm
void Graph::BFS(int startVertex) {
    std::queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;
    parent[startVertex] = -1;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        std::cout << "Visited " << currentVertex << std::endl;

        for (int i = 0; i < adjLists[currentVertex].size(); i++) {
            int adjVertex = adjLists[currentVertex][i];

            if (!visited[adjVertex]) {
                q.push(adjVertex);
                visited[adjVertex] = true;
                parent[adjVertex] = currentVertex;
            }
        }
    }
}


