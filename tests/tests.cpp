#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "/workspaces/CS225/Final-project/src/Airport.h"
#include "/workspaces/CS225/Final-project/src/route.h"
#include "/workspaces/CS225/Final-project/src/filereading.h"
#include "/workspaces/CS225/Final-project/src/Utils.h"
#include "/workspaces/CS225/Final-project/src/Graph.h"





// using namespace cs225;




TEST_CASE("test for test case", "[weight=0][part=1]") {

  REQUIRE( true == true );

}

TEST_CASE("test read data from file", "[weight=0][part=1]") {

  filereading test_fr;
  test_fr.readairport("/workspaces/CS225/Final-project/data/Airports_test");
  std::vector<airport> test_airport_vec = test_fr.getAirportVector();
  // for (auto a : test_airport_vec) {
  //   std::cout << a.get_name() << std::endl;
  // }
  REQUIRE( test_airport_vec.size() == 27 );


}

TEST_CASE("test build Graph", "[weight=0][part=1]") {

  filereading test_fr;
  test_fr.readairport("/workspaces/CS225/Final-project/data/Airports_test");
  test_fr.readairroute("/workspaces/CS225/Final-project/data/Routes");
  std::vector<airport> test_airport_vec = test_fr.getAirportVector();
  std::vector<route> test_route_vec = test_fr.getRouteVector();
  Graph test_G(test_airport_vec, test_route_vec);
  //print names of airports in this graph
  std::vector <airport> test_airports = test_G.getAirportList();
  for (auto a : test_airports) {
    std::cout << a.get_name() << std::endl;
  }

  REQUIRE(test_G.get_num_vertices() == 27);

}