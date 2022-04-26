#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "A2DConverter.h"

#define A2DCONVERTER_12BIT 12
#define TEMPERATURE_MAX 10
#define TEMPERATURE_MIN 0

void A2DConversion(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges, int A2DConverter, int Temparature_Max, int Temparature_Min)
{
  int currentRangeIndex, conversionMaxValue, totalRanges = 0;
  float convertedValue, ScalingValue, currentValue = 0.0;
  
  conversionMaxValue = (pow(2,A2DConverter) - 2);
  totalRanges = Temparature_Max - Temparature_Min;
  ScalingValue = totalRanges / Temparature_Max;
  
  for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
  {
    convertedValue = Temparature_Max * AnalogCurrentRanges[currentRangeIndex] / conversionMaxValue;
    currentValue = Temparature_Min + (convertedValue * ScalingValue);
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

bool ConvertAnalogCurrentRangesToDigital(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges, int A2DConverter, int Temparature_Max, int Temparature_Min)
{
  bool allCurrentRangesConverted = true;
  int currentRangeIndex = 0;
  
  allCurrentRangesConverted = ValidateAnalogCurrentRanges(AnalogCurrentRanges,TotalNoOfCurrentRanges);
  
  if(allCurrentRangesConverted == true)
  {
    A2DConversion(AnalogCurrentRanges,DigitalCurrentRanges,TotalNoOfCurrentRanges,A2DConverter,Temparature_Max,Temparature_Min);
  }
  
  
  return allCurrentRangesConverted;
}
