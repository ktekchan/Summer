/*
 * Khushboo Tekchandani
 * Find the minimum element in a sorted and rotated array
 * Idea: Binary search with the fact that only minimum element will be such that
 *       its previous element is greater than itself.
 */

#include <iostream>

using namespace std;

int findMin(int arr[], int len, int start, int end){


   if(start>end)
      return arr[0];

   if(start==end)
      return arr[start];

   int mid = start+(end-start)/2;

   if(mid < end && arr[mid]>arr[mid+1])
      return arr[mid+1];

   if(mid > start && arr[mid]<arr[mid-1])
      return arr[mid];

   if(arr[end]>arr[mid])
      return findMin(arr,len,start,mid-1);

   return findMin(arr,len,mid+1,end);

}

int main(){

   int arr[] = {11,15,6,7,8,9};
   int len = sizeof(arr)/sizeof(arr[0]);
   cout << findMin(arr,len,0,len-1)<< endl;

   return 0;
}
