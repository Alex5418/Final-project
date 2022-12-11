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
TEST_CASE("test for GetSubstrs", "[weight=0][part=1]") {

  filereading test_fr;
  string test = "1,\"Goroka Airport\",\"Goroka\",\"Papua New Guinea\",\"GKA\",\"AYGA\",-6.081689834590001,145.391998291,5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"";
  vector<string> test_substrs = test_fr.GetSubstrs(test, ',');
  vector<string> correct_vector{"1", "\"Goroka Airport\"", "\"Goroka\"", "\"Papua New Guinea\"", "\"GKA\"", "\"AYGA\"", "-6.081689834590001", "145.391998291", "5282", "10", "\"U\"", "\"Pacific/Port_Moresby\"", "\"airport\"", "\"OurAirports\""};
  REQUIRE( test_substrs == correct_vector );
}

TEST_CASE("test for distance", "[weight=0][part=1]") {
  filereading test_fr;
  test_fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
  REQUIRE( int(test_fr.distance(1, 2)) == 106 );
  REQUIRE( int(test_fr.distance(128, 547)) == 4608 );
  REQUIRE( int(test_fr.distance(4159, 13479)) == 4076 );
}

TEST_CASE("test for IATA_to_airpot_id", "[weight=0][part=1]") {
  filereading test_fr;
  test_fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
  REQUIRE( test_fr.IATA_to_airpot_id("GKA") == 1 );
  REQUIRE( test_fr.IATA_to_airpot_id("YXJ") == 168 );
  REQUIRE( test_fr.IATA_to_airpot_id("AAE") == 220 );
  REQUIRE( test_fr.IATA_to_airpot_id("PYY") == 4159 );
  REQUIRE( test_fr.IATA_to_airpot_id("ELI") == 7184 );
  REQUIRE( test_fr.IATA_to_airpot_id("DTU") == 13479 );
}

TEST_CASE("test for simpleRank", "[weight=0][part=1]") {
  filereading test_fr;
  test_fr.readairport("/workspaces/cs225/Final-project/data/airports.txt");
  test_fr.readairroute("/workspaces/cs225/Final-project/data/Routes.txt");
  Graph G_test(test_fr.getAirportVector(), test_fr.getRouteVector());
  vector<size_t> test_vec = G_test.TestSimplePageRank(5);
  vector<size_t> result{3482, 3170, 1346, 3630, 1655};
  REQUIRE(test_vec == result);
}

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
