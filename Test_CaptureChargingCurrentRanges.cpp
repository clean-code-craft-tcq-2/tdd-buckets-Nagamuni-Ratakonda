#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CaptureChargingCurrentRanges.h"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,2) == 1);
}

TEST_CASE("Check for no periodic set of current ranges") {
  int CurrentRanges[] = {7,3};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,2) == 0);
}

TEST_CASE("Checks the charging current of same ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,4};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,2) == 1);
}

TEST_CASE("Checks the charging current of same ranges and captures the no of occurences") {
  int CurrentRanges[] = {3,3,5,4,10,11};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,5) == 2);
}
