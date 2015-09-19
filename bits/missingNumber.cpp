/*
 * Khushboo Tekchandani
 * Find the missing number given an array of n-1 numbers in the range of
 * 1 to n
 * Using XOR
 * Secondary method: Sum of n integer = n(n-1)/2 subtract all from this
 * remaining number is the missing number
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void findMissing(int arr[], int n){
   
   int xor1 = 0;
   int xor2 = 0;

   int i;
   for(i=0; i<n-1; i++){
      xor1 = xor1^arr[i];
   }

   for(i=1; i<=n; i++){
      xor2 = xor2^i;
   }

   cout << (xor1^xor2);
}

int main(){

   int arr[] = {1,2,4,5,6};
   int n = sizeof(arr)/sizeof(int);
   
   findMissing(arr, n);
}
