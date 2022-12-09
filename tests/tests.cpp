#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "/workspaces/cs225/Final-project/src/Airport.h"
#include "/workspaces/cs225/Final-project/src/route.h"
#include "/workspaces/cs225/Final-project/src/filereading.h"
#include "/workspaces/cs225/Final-project/src/Utils.h"
#include "/workspaces/cs225/Final-project/src/Graph.h"
 
using namespace std;



// using namespace cs225;

TEST_CASE("BFS", "[weight=0][part=1]") {
  vector<vector<int>> test1 = {
    {1,2},
    {2},
    {3},
    {},
  };
  Graph gra1(4);
  gra1.SetBfsTestGraph(test1);
  vector<vector<int>> output1 = gra1.TestBFS(0,3);
  vector<vector<int>> result1 = {
    {0,2,3},
    {0,1,2,3},
  };
  REQUIRE(output1 == result1);

  vector<vector<int>> test2 = {
    {1,2},
    {2,3,4},
    {3,4},
    {4},
    {}
  };
  Graph gra2(4);
  gra2.SetBfsTestGraph(test2);
  vector<vector<int>> output2 = gra2.TestBFS(0,4);
  vector<vector<int>> result2 = {
    {0,1,4},
    {0,2,4},
    {0,1,2,4},
    {0,1,3,4},
    {0,2,3,4},
    {0,1,2,3,4},
  };
  REQUIRE(output2 == result2);

}
