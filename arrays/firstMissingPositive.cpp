/*
 * Khushboo Tekchandani
 * Find the smallest positive number missing from an unsorted array
 * Idea: Mark the presence of an element x, change the value of the index x to
 * some identifiable value, say (-1)
 *
 * For input with negative values, push all the negatives to one side of the
 * array
 */

#include <iostream>
#include <cstdlib>

using namespace std;

// Function to put all negatives on one side of the array since we dont care
// about it
int pushNeg(int arr[], int len){

   int i,j;
   j = 0;
   for(i=0; i<len; i++){
      if(arr[i]<=0){
         swap(arr[i],arr[j]);
         j++;
      }
   }

   return j;
}


// Function to find the first missing positive
int findMissingPostive(int arr[], int len){

   int i;

   //Mark all the arr[i] as visited by making arr[arr[i]-1] negative.
   for(i=0; i<len; i++){
      if(abs(arr[i])-1 < len && arr[abs(arr[i])-1]>0)
         arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
   }

   //Now traverse the array and return the first index value which is positive
   for(i=0; i<len; i++)
      if(arr[i]>0)
         return i+1;

   return len+1;
}


// Facilitating function when the array contains negatives
int findMissing(int arr[], int len){

   int start = pushNeg(arr,len);
   return findMissingPostive(arr+start,len-start);
}

int main(){

   int arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 };
   int len = sizeof(arr)/sizeof(arr[0]);
   cout << findMissing(arr,len) << endl;
   return 0;
}
