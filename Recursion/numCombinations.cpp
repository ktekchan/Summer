/*
 * Khushboo Tekchandani
 * Given a number N, write a program that returns all possible combinations of
 * numbers that add up to N, as lists. (Exclude the N+0=N) 
 *
 * Recursion. Save one, iterate on the rest of the array
 */

#include <iostream>

using namespace std;

void print(int *arr, int n){
   int i;

   for(i=0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void sumCombination(int n, int start, int end,int *arr){

   if(n==0)
      print(arr,start);
   else if(n>0){
      
      int j;
      for(j=1; j<end; j++){
         arr[start] = j;
         sumCombination(n-j,start+1,end,arr);
      }
   }
}

int main(){

   int *arr = new int[4];
   sumCombination(4,0,4,arr);
   return 0;
}
