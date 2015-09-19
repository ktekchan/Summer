/*
 * Khushboo Tekchandani
 * Same as rotate array by k
 * Then for each query print the element at the given index
 * Using the bubble sort method to rotate the array
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void rotate(int *&arr, int size, int k){

   int i,j;

   for(i=0; i<k; i++)
      for(j=size-1; j>0; j--)
         swap(arr[j],arr[j-1]);
}

int main(){

   int n,k,numQuery;
   cin >> n >> k >> numQuery;

   int i;

   int *arr = (int*)malloc(sizeof(int)*n);
   int ai;

   for(i=0; i<n; i++){
      cin >> ai;
      arr[i] = ai;
   }

   int qi;

   rotate(arr,n,k);

   for(i=0; i<numQuery; i++){
      cin >> qi;
      cout << arr[qi] << endl;
   }

   return 0;
}
