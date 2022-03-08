#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges) == 1);
}
