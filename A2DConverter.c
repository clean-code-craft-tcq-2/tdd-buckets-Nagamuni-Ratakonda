#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "A2DConverter.h"

void A2DConversion(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges)
{
  int currentRangeIndex = 0;
  
  for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
  {
    DigitalCurrentRanges[currentRangeIndex] = ((AnalogCurrentRanges[currentRangeIndex] * 10) / 4094);
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
      printf("Invalid current reading");
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
