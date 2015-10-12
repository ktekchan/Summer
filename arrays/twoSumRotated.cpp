/*
 * Khushboo Tekchandani
 * Given a sorted and rotated array, find if there is a pair with a given sum
 * Idea: find pivot of the rotated array
 *       Use the two pointer logic with pointer arithmetic
 */

#include <iostream>

using namespace std;

bool rotatedSum(int arr[], int len, int sum){

   int i;
   int pivot;
   for(i=0; i<len; i++){
      if(arr[i+1]<arr[i])
         break;
   }

   pivot = i;

   int start = (pivot+1)%len;
   int end = pivot;

   while(start!=end){
   
      if(arr[start]+arr[end]==sum)
         return true;
      // Sum is smaller so increment towards a bigger number by moving the start
      // pointer twords the right
      else if(arr[start]+arr[end]<sum)
         start = (start+1)%len;
      // Otherwise move the end pointer towards the left
      else
         end = (end+len-1)%len;
   }
   return false;
}

int main() {

   int arr[] = {11, 15, 6, 8, 9, 10};
   int sum = 16;
   int len = sizeof(arr)/sizeof(arr[0]);

   cout << rotatedSum(arr,len,sum) << endl;

   return 0;
}
