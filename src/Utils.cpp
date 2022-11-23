


// #include <cmath>
// #include <iostream>
// #include <cstdlib>
// #include <limits>


// #include "route.h"
// #include "Airport.h"
// #include "filereading.h"
// #include "Utils.h"


// Graph::Graph(int numVertices)
// {
//     this->numVertices = numVertices;
//     adjMatrix.resize(numVertices, std::vector<int>(numVertices));
//     visited.resize(numVertices);
//     parent.resize(numVertices);
// }

// void Graph::addVertex(int v)
// {
//     if (v >= numVertices)
//     {
//         std::cout << "Vertex number out of range" << std::endl;
//         return;
//     }
//     visited[v] = 0;
//     parent[v] = -1;
// }

// void Graph::addEdge(int source, int destination)
// {
//     // add edge from source to destination
//     adjMatrix[source][destination] = 1;

//     // add edge from destination to source
//     adjMatrix[destination][source] = 1;
// }

// // Breadth First Search to traverse the graph
// void Graph::BFS(int startVertex) {
//     std::queue<int> q;
//     visited[startVertex] = 1;
//     q.push(startVertex);

//     while (!q.empty()) {
//         int currentVertex = q.front();
//         q.pop();
//         std::cout << currentVertex << " ";
//         for (int i = 0; i < numVertices; i++) {
//             if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
//                 visited[i] = 1;
//                 q.push(i);
//             }
//         }
//     }
// }

// // Djikstra's algorithm to find the shortest path
// void Graph::Djikstra(int sourceVertex, int destinationVertex) {
//     // set all distance to infinity
//     for (int i = 0; i < numVertices; i++) {
//         distance[i] = std::numeric_limits<int>::max();
//     }

//     // set distance of source vertex to 0
//     distance[sourceVertex] = 0;

//     // create a min heap
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

//     // insert source vertex in the min heap and initialize its distance to 0
//     pq.push(std::make_pair(0, sourceVertex));

//     while (!pq.empty()) {
//         // extract the vertex with the minimum distance
//         int currentVertex = pq.top().second;
//         pq.pop();

//         // iterate through all the adjacent vertices of the current vertex
//         for (int i = 0; i < numVertices; i++) {
//             // if there is an edge between the current vertex and the adjacent vertex
//             if (adjMatrix[currentVertex][i] == 1) {
//                 // if the distance to the adjacent vertex is greater than the distance to the current vertex + weight of the edge
//                 if (distance[i] > distance[currentVertex] + adjMatrix[currentVertex][i]) {
//                     // update the distance of the adjacent vertex
//                     distance[i] = distance[currentVertex] + adjMatrix[currentVertex][i];

//                     update the parent of the adjacent vertex
//                     parent[i] = currentVertex;

//                     // insert the adjacent vertex with its updated distance in the min heap
//                     pq.push(std::make_pair(distance[i], i));
//                 }
//             }
//         }
//     }
// }

// void Graph::printGraph() {
//     for (int i = 0; i < numVertices; i++) {
//         for (int j = 0; j < numVertices; j++) {
//             std::cout << adjMatrix[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }






