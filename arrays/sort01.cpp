/*
 * Khushboo Tekchandani
 * Given an array containing 0s and 1s, sort it.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

void sort01(int arr[], int len){

   int i,j;
   i = 0;
   j = len-1;
   while(i<j){

      while(i<j && arr[i]==0)
         i++;
      while(i<j && arr[j]==1)
         j--;
      if(i<j){
         arr[i] = 0;
         arr[j] = 1;
         i++;
         j--;
      }
   }

   for(i=0; i<len; i++)
      cout << arr[i] << " ";
   cout << endl;
}

int main(){

   int arr[] = {0,1,1,0,0,0,1,0,1};
   int len = sizeof(arr)/sizeof(arr[0]);
   sort01(arr, len);
   return 0;
}
