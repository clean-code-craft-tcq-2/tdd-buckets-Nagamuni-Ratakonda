#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CaptureChargingCurrentRanges.h"
#include "A2DConverter.h"

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

//Testcases for A2DConverter
TEST_CASE("Testcase to cehck whether Analog current ranges converted to Digital") {
  int AnalogCurrentRanges[] = {4094, 819,3790,1230,1640,2870};
  int TotalNoOfCurrentRanges = sizeof(AnalogCurrentRanges) / sizeof(AnalogCurrentRanges[0]);
  float DigitalCurrentRanges[TotalNoOfCurrentRanges];
  int ExpectedCurrentRangesInAmps[] = {10, 2, 9, 3, 4 , 7};
  
  
  REQUIRE(ConvertAnalogCurrentRangesToDigital(AnalogCurrentRanges,ExpectedCurrentRangesInAmps,TotalNoOfCurrentRanges) == true);
  
  for(int rangeIndex = 0; rangeIndex < TotalNoOfCurrentRanges; rangeIndex++)
  {
    REQUIRE(DigitalCurrentRanges[rangeIndex] == ExpectedCurrentRangesInAmps[rangeIndex]);
  }

}
