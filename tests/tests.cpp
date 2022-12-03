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





// using namespace cs225;




TEST_CASE("test for test case", "[weight=0][part=1]") {

  REQUIRE( true == true );

}

TEST_CASE("test read data from file", "[weight=0][part=1]") {

  filereading test_fr;
  test_fr.readairport("/workspaces/CS225/Final-project/data/Airports_test");
  std::vector<airport> test_airport_vec = test_fr.getAirportVector();
  for (auto a : test_airport_vec) {
    std::cout << a.get_name() << std::endl;
  }
  REQUIRE( test_airport_vec.size() == 27 );




}