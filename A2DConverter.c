#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "A2DConverter.h"

#define A2DCONVERTER_12BIT 12
#define TEMPERATURE_MAX 10
#define TEMPERATURE_MIN 0

void A2DConversion(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges)
{
  int currentRangeIndex, conversionMaxValue, totalRanges = 0;
  float convertedValue, ScalingValue, currentValue = 0.0;
  
  conversionMaxValue = (pow(2,12) - 2);
  totalRanges = TEMPERATURE_MAX - TEMPERATURE_MIN;
  ScalingValue = totalRanges / TEMPERATURE_MAX;
  
  for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
  {
    convertedValue = TEMPERATURE_MAX * AnalogCurrentRanges[currentRangeIndex] / conversionMaxValue;
    currentValue = TEMPERATURE_MIN + (convertedValue * ScalingValue);
    DigitalCurrentRanges[currentRangeIndex] = round(currentValue);
    
    if(DigitalCurrentRanges[currentRangeIndex] < 0)
    {
      DigitalCurrentRanges[currentRangeIndex] = abs(DigitalCurrentRanges[currentRangeIndex]);
    }
  }
}

bool ValidateAnalogCurrentRanges(int *AnalogCurrentRanges, int TotalNoOfCurrentRanges)
{
  bool areAllRangesValid = true;
  int currentRangeIndex = 0;
  
  for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
  {
    if(AnalogCurrentRanges[currentRangeIndex] > 4094)
    {
      printf("Invalid current reading\n");
      areAllRangesValid = false;
    }
  }
  
  return areAllRangesValid;
}

bool ConvertAnalogCurrentRangesToDigital(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges)
{
  bool allCurrentRangesConverted = true;
  int currentRangeIndex = 0;
  
  allCurrentRangesConverted = ValidateAnalogCurrentRanges(AnalogCurrentRanges,TotalNoOfCurrentRanges);
  
  if(allCurrentRangesConverted == true)
  {
    A2DConversion(AnalogCurrentRanges,DigitalCurrentRanges,TotalNoOfCurrentRanges);
  }
  
  
  return allCurrentRangesConverted;
}
