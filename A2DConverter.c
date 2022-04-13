#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "A2DConverter.h"

bool ConvertAnalogCurrentRangesToDigital(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges)
{
  bool allCurrentRangesConverted = true;
  int currentRangeIndex = 0;
  
  for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
  {
    if(AnalogCurrentRanges[currentRangeIndex] > 4094)
    {
      printf("Invalid current reading");
      allCurrentRangesConverted = false;
    }
  }
  
  if(allCurrentRangesConverted == true)
  {
    for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
    {
      DigitalCurrentRanges[currentRangeIndex] = ((AnalogCurrentRanges[currentRangeIndex] * 10) / 4094);
    }
  }
  
  
  return allCurrentRangesConverted;
}
