#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CaptureChargingCurrentRanges.h"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,2) == 1);
}
