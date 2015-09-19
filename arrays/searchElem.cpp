/*
 * Khushboo Tekchandani
 * Find an element in a sorted and a pivoted array.
 * Idea: find the pivot, divide the array into two subarrays
 *       and run binary search.
 * To find pivot, use binary search - O(nlogn)
 * and then again to search the element, we do a binary search O(nlogn)
 */

#include <iostream>

using namespace std;

// Return index of the element where the array needs to be divided
// This happens when next element is greater than the current element
int findPivot(int arr[], int start, int end){
   
   if(start>end)
      return -1;
   if(start==end)
      return start;

   int mid = (start+end)/2;

   if(start<mid && arr[mid-1]>arr[mid])
      return mid-1;
   if(mid<end && arr[mid]>arr[mid+1])
      return mid;
   if(arr[start]>=arr[mid])
      return findPivot(arr,start,(mid-1));
   else
      return findPivot(arr,(mid+1),end);

}

// Standard binary search
int binarySearch(int arr[], int start, int end, int n){
   
   if(start>end)
      return -1;
   if(start==end)
      return start;

   int mid = (start+end)/2;
   if(n == arr[mid])
      return mid;

   if(n<arr[mid])
      return binarySearch(arr,start,(mid-1),n);
   else
      return binarySearch(arr,(mid+1),end,n);

}

// Find the element using the above functions
int findElem(int arr[], int size, int elem){

   int pivot = findPivot(arr,0,(size-1));

   if(pivot==-1)
      return binarySearch(arr,0,(size-1),elem);

   if(elem==arr[pivot])
      return pivot;
   if(elem<arr[pivot])
      return binarySearch(arr,0,(pivot-1),elem);
   else
      return binarySearch(arr,(pivot+1),(size-1),elem);
}

int main(){

   int arr[] = {3,4,5,6,1,2};
   int size = sizeof(arr)/sizeof(arr[0]);
   int elem = 5;

   cout << findElem(arr, size, elem) << endl;

   return 0;
}
