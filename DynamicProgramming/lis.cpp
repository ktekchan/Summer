/*
 * Author: Khushboo Tekchandani
 * Find the length of the longest increasing subsequence
 * Dynamic Programming
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void findlis(int arr[], int n){

   int *lis;
   lis = (int*)malloc(sizeof(int)*n);

   int i;

   //Initializing length of longest increasing subsequence to one for all
   //indices
   for(i=0; i<n; i++){
      lis[i] = 1;
   }

   // Calculating lis for each index
   for(i=1; i<n; i++){
      for(int j=0; j<i; j++){
         if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[i] + 1;
      }
   }

   int max = lis[0];

   // find max of all found lis
   for(i=0; i<n; i++){
      if (max < lis[i])
         max = lis[i];
   }

   cout << "Length of the longest increasing subsequence is: " << max << endl;
   return;
}

int main(){

   int arr[] = {10,22,9,33,21,50,41,60};
   int n = sizeof(arr)/sizeof(arr[0]);
   findlis(arr,n);
   return 0;
}
