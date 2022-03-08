#include <stdio.h>
#include "CaptureChargingCurrentRanges.h"

int CaptureChargingCurrentRanges (int *CurrentRanges, int TotalCurrentRanges){
  
  int i,j,swap,lowerRange,NextElement,RangeDifference;
  int TotalPeriodicSetRanges = 0;
  
//   for(i = 1; i <= (TotalCurrentRanges-1); i++)
//   {
//     j = i;
//     while(j > 0 && CurrentRanges[j-1] > CurrentRanges[j])
//     {
//       swap = CurrentRanges[j];
//       CurrentRanges[j] = CurrentRanges[j-1];
//       CurrentRanges[j-1] = swap;
//       j--;
//       printf("sorted");
//     }
//   }
  
  
  for (i = 0; i < TotalCurrentRanges ; i++) 
  {
    lowerRange = CurrentRanges[i];
    NextElement = CurrentRanges[i+1];
    RangeDifference = lowerRange - RangeDifference;
    if(RangeDifference == 0 || RangeDifference == 1)
    {
      TotalPeriodicSetRanges++;
      printf("Range, Readings");
      printf("%d-%d, %d",lowerRange,NextElement,TotalPeriodicSetRanges);
    }
  }
  
  return TotalPeriodicSetRanges;
}
