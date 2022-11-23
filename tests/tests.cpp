#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "/workspaces/CS225/Final-project/src/Airport.h"
#include "/workspaces/CS225/Final-project/src/route.h"
#include "/workspaces/CS225/Final-project/src/filereading.h"
#include "/workspaces/CS225/Final-project/src/Utils.h"





// using namespace cs225;

TEST_CASE("test for test case", "[weight=0][part=1]") {

  REQUIRE( true == true );
}

TEST_CASE("test graph of airports", "[weight=0][part=1]") {

    Graph g(5);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    g.printGraph();

    REQUIRE (true == true);


}