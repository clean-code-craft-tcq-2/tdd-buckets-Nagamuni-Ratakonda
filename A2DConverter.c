#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "A2DConverter.h"

void A2DConversion(int *AnalogCurrentRanges, int *DigitalCurrentRanges, int TotalNoOfCurrentRanges, int A2DConverter, int Temparature_Max, int Temparature_Min)
{
  int currentRangeIndex, conversionMaxValue, totalRanges = 0;
  float convertedValue, ScalingValue, currentValue = 0.0;
  
  conversionMaxValue = (pow(2,A2DConverter) - 2);
  totalRanges = Temparature_Max - Temparature_Min;
  ScalingValue = totalRanges / Temparature_Max;
  printf("Converter = %d, Temp_Max = %d, Temp_Min = %d",A2DConverter,Temparature_Max,Temparature_Min);
  printf("conversionMaxValue = %d\n totalRanges = %d\n ScalingValue = %f\n",conversionMaxValue,totalRanges,ScalingValue);
  
  for(currentRangeIndex = 0; currentRangeIndex < TotalNoOfCurrentRanges; currentRangeIndex++)
  {
    convertedValue = AnalogCurrentRanges[currentRangeIndex] / conversionMaxValue;
    currentValue = Temparature_Min + (Temparature_Max * convertedValue * ScalingValue);
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
