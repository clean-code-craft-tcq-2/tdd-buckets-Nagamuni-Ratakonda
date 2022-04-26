#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "CaptureChargingCurrentRanges.h"
#include "A2DConverter.h"

TEST_CASE("Checks the charging current ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,5};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,2) == 1);
}

TEST_CASE("Checks the charging current of same ranges and captures the no of occurences") {
  int CurrentRanges[] = {4,4};
  REQUIRE(CaptureChargingCurrentRanges(CurrentRanges,2) == 1);
}

#define A2DCONVERTER_12BIT 12
#define TEMPERATURE_MAX 10
#define TEMPERATURE_MIN 0

//Testcases for 12BIT A2DConverter
TEST_CASE("Testcase to check whether Analog current ranges converted to Digital") {
  int AnalogCurrentRanges[] = {1110, 3333, 1112, 3700, 1234, 4094};
  int TotalNoOfCurrentRanges = sizeof(AnalogCurrentRanges) / sizeof(AnalogCurrentRanges[0]);
  int DigitalCurrentRanges[TotalNoOfCurrentRanges];
  int ExpectedCurrentRangesInAmps[] = {3, 8, 3, 9, 3, 10};
  
  
  REQUIRE(ConvertAnalogCurrentRangesToDigital(AnalogCurrentRanges,DigitalCurrentRanges,TotalNoOfCurrentRanges,A2DCONVERTER_12BIT,TEMPERATURE_MAX,TEMPERATURE_MIN) == true);
  
  for(int rangeIndex = 0; rangeIndex < TotalNoOfCurrentRanges; rangeIndex++)
  {
    REQUIRE(DigitalCurrentRanges[rangeIndex] == ExpectedCurrentRangesInAmps[rangeIndex]);
  }
  
  REQUIRE(CaptureChargingCurrentRanges(DigitalCurrentRanges,TotalNoOfCurrentRanges) == 2);

}

TEST_CASE("Testcase to check whether Analog current ranges are not converted to Digital since the current range is invalid") {
  int AnalogCurrentRanges[] = {4095};
  int TotalNoOfCurrentRanges = sizeof(AnalogCurrentRanges) / sizeof(AnalogCurrentRanges[0]);
  int DigitalCurrentRanges[TotalNoOfCurrentRanges];
  
  REQUIRE(ConvertAnalogCurrentRangesToDigital(AnalogCurrentRanges,DigitalCurrentRanges,TotalNoOfCurrentRanges,A2DCONVERTER_12BIT,TEMPERATURE_MAX,TEMPERATURE_MIN) == false);

}


#define A2DCONVERTER_10BIT 10
#define TEMPERATURE_MAX_10BIT 15
#define TEMPERATURE_MIN_10BIT -15


//Testcases for 10Bit A2DConverter
TEST_CASE("Testcase to check whether Analog current ranges converted to Digital using 10Bit A2DConverter") {
  int AnalogCurrentRanges_10Bit[] = {0, 1022, 511};
  int TotalNoOfCurrentRanges = sizeof(AnalogCurrentRanges_10Bit) / sizeof(AnalogCurrentRanges_10Bit[0]);
  int DigitalCurrentRanges_10Bit[TotalNoOfCurrentRanges];
  int ExpectedCurrentRangesInAmps_10Bit[] = {15, 15, 0};
  
  
  REQUIRE(ConvertAnalogCurrentRangesToDigital(AnalogCurrentRanges_10Bit,DigitalCurrentRanges_10Bit,TotalNoOfCurrentRanges,A2DCONVERTER_10BIT,TEMPERATURE_MAX_10BIT,TEMPERATURE_MIN_10BIT) == true);
  
  for(int rangeIndex = 0; rangeIndex < TotalNoOfCurrentRanges; rangeIndex++)
  {
    REQUIRE(DigitalCurrentRanges_10Bit[rangeIndex] == ExpectedCurrentRangesInAmps_10Bit[rangeIndex]);
  }
  
  REQUIRE(CaptureChargingCurrentRanges(DigitalCurrentRanges_10Bit,TotalNoOfCurrentRanges) == 2);

}
