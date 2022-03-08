#include <stdio.h>
#include "CaptureChargingCurrentRanges.h"

void SortCurrentRanges(int *CurrentRanges, int TotalCurrentRanges)
{
  int i,j,swap;
  
  for(i = 0; i <TotalCurrentRanges; ++i)
  {
    for(j = i+1; j < TotalCurrentRanges; ++j)
    {
      if(CurrentRanges[i] > CurrentRanges[j])
      {
        swap = CurrentRanges[i];
        CurrentRanges[i] = CurrentRanges[j];
        CurrentRanges[j] = swap;
        printf("sorted");
      }
    }
  }
}

int CaptureChargingCurrentRanges (int *CurrentRanges, int TotalCurrentRanges){
  
  int i,j,swap,lowerRange,NextElement,RangeDifference;
  int TotalPeriodicSetRanges = 0;
  
  SortCurrentRanges(CurrentRanges,TotalCurrentRanges);
  
  for (i = 0; i < TotalCurrentRanges ; i++) 
  {
    lowerRange = CurrentRanges[i];
    NextElement = CurrentRanges[i+1];
    RangeDifference = NextElement - lowerRange;
    if(RangeDifference == 0 || RangeDifference == 1)
    {
      TotalPeriodicSetRanges++;
      printf("Range, Readings");
      printf("%d-%d, %d",lowerRange,NextElement,TotalCurrentRanges);
    }
  }
  
  return TotalPeriodicSetRanges;
}
