/*
 * Author: Khushboo Tekchandani
 * Maximum contiguous and non-contiguous subarray sum.
 * Dynamic programming.
 */

#include <iostream>
#include <limits.h>

using namespace std;

long contiguousMaxsum(long *arr,long n){
   
   long i;
   long best_sum = arr[0];
   long current_sum = arr[0];
   long val;

   for(i=1; i<n; i++){
      val = current_sum + arr[i];
      if (val > arr[i])
         current_sum = val;
      else
         current_sum = arr[i];

      if(current_sum > best_sum)
         best_sum = current_sum;
   }

   return best_sum;
}

long nonContiguousMaxsum(long *arr, long n){
   
   long i;
   long best_sum = 0;
   long current_sum = 0;

   for(i=0; i<n; i++){
      current_sum = best_sum + arr[i];
      if (current_sum > best_sum)
         best_sum = current_sum;
   }

   if(best_sum==0)
      return arr[0];

   return best_sum;
}

int main(){
   int t;
   long n;
   cin >> t;

   int i;
   long j;
   long *arr;
   for(i=0; i<t; i++){
      cin >> n;
      arr = new long[n];
      for(j=0; j<n; j++){
         cin >> arr[j];
      }

      cout << contiguousMaxsum(arr, n) << " ";
      cout << nonContiguousMaxsum(arr, n) << endl;
   }

   return 0;
}
