/*
 * Author: Khushboo Tekchandani
 * Rotate an array by k, to th right
 */

#include <iostream>
#include <algorithm>
using namespace std;

// O(n*k) time complexity
// O(1) space complexity
// Bubble sort like solution
void rotate(int *arr, int size, int k){

   int i,j;
   int temp;

   for(i=0; i<k; i++)
      for(j=size-1; j>0; j--)
         swap(arr[j],arr[j-1]);

   for(i=0; i<size; i++)
      cout << arr[i] << " " ;

   cout << endl;

}

// O(n) space
// O(n) time
void rotate1(int *arr, int size, int k){

   int *newArr = new int[size];
   int index;
   int i;

   for(i=0; i<size; i++){
      index = (i+k)%size;
      newArr[index] = arr[i];
   }

   for(i=0; i<size; i++)
      cout << arr[i] << " ";

   cout << endl;
}

int main(){
   
   int size = 6;
   int *arr = new int[6];
   int k = 2;

   int i;
   for(i=0; i<size; i++)
      arr[i] = i+1;

   for(i=0; i<size; i++)
      cout << arr[i] << " ";

   cout << endl;

   rotate(arr,size,k);
   rotate1(arr,size,k);
   return 0;
}

