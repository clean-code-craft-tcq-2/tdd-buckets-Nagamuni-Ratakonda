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
    }
    else
    {
      TotalPeriodicSetRanges = 0;
    }
  
  return TotalPeriodicSetRanges;
}

int CaptureChargingCurrentRanges (int *CurrentRanges, int TotalCurrentRanges){
  int NoOfRangeSets, TotalPeriodicSetRanges,PeriodicSetRanges = 0;
  int i,lowerRange = 0;
  
  SortCurrentRanges(CurrentRanges,TotalCurrentRanges);
  
  printf("Range, Readings\n");
  lowerRange = CurrentRanges[0];
  for(i = 0; i < (TotalCurrentRanges-1) ; i++)
  {
    NoOfRangeSets = CheckForPeriodicSetRanges(&CurrentRanges[i],TotalCurrentRanges);
    PeriodicSetRanges += NoOfRangeSets;
    
    if(NoOfRangeSets == 0)
    {
      printf("%d-%d %d\n",lowerRange,CurrentRanges[i],(PeriodicSetRanges+1));
      lowerRange = CurrentRanges[i+1];
      PeriodicSetRanges = 0;
      TotalPeriodicSetRanges++;
    }
    
    if(i == TotalCurrentRanges-2)
    {
      printf("%d-%d %d\n",lowerRange,CurrentRanges[i+1],(PeriodicSetRanges+1));
      TotalPeriodicSetRanges++;
    }
    
  }
  
  return TotalPeriodicSetRanges;
}
