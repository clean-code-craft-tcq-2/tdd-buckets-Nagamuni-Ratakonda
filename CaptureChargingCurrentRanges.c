#include <stdio.h>
#include "CaptureChargingCurrentRanges.h"

void SortCurrentRanges(int *CurrentRanges, int TotalCurrentRanges)
{
  int i,swap;
  
  for(i = 0; i <(TotalCurrentRanges - 1); i++)
  {
    if(CurrentRanges[i] > CurrentRanges[i+1])
    {
      swap = CurrentRanges[i];
      CurrentRanges[i] = CurrentRanges[i+1];
      CurrentRanges[i+1] = swap;
      i = -1;
    }
  }
}

int CheckForPeriodicSetRanges(int *CurrentRanges, int TotalCurrentRanges)
{
  int lowerRange,NextElement,RangeDifference;
  int TotalPeriodicSetRanges = 0;
 
    lowerRange = CurrentRanges[0];
    NextElement = CurrentRanges[1];
    RangeDifference = NextElement - lowerRange;
    if(RangeDifference == 0 || RangeDifference == 1)
    {
      TotalPeriodicSetRanges++;
      printf("Range, Readings\n");
      printf("%d-%d, %d",lowerRange,NextElement,TotalCurrentRanges);
    }
    else
    {
      TotalPeriodicSetRanges = 0;
    }
  
  return TotalPeriodicSetRanges;
}

int CaptureChargingCurrentRanges (int *CurrentRanges, int TotalCurrentRanges){
  int TotalPeriodicSetRanges = 0;
  int i;
  
  SortCurrentRanges(CurrentRanges,TotalCurrentRanges);
  
  for(i = 0; i < TotalCurrentRanges ; i++)
  {
   TotalPeriodicSetRanges = CheckForPeriodicSetRanges(CurrentRanges,TotalCurrentRanges);
  }
  
  return TotalPeriodicSetRanges;
}
