/*
 * Khushboo Tekchandani
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 * Idea: Do a left and right scan. Find the max left height before ith block
 * find right max height before i and then height trapped there is min(left,
 * right) - height(i)
 *
 */

#include <iostream>

using namespace std;

int trapped(int heights[], int n){
   
   int result = 0;
   int *left = new int[n];
   int *right = new int[n];

   int max = heights[0];
   left[0] = heights[0];

   int i;

   for(i=1; i<n; i++){
      
      if(heights[i]<max){
         left[i] = max;
      }
      else{
         max = heights[i];
         left[i] = heights[i];
      }
   
   }

   max = heights[n-1];
   right[n-1] = heights[n-1];

   for(i=n-2; i>=0; i--){
      
      if(heights[i]<max){
         right[i] = max;
      }

      else{
         max = heights[i];
         right[i] = heights[i];
      }
   }

   for(i=0; i<n; i++){
      result += (min(left[i], right[i]) - heights[i]);
   }

   return result;
}

int main(){
   
   int heights[] = {0,1,0,2,1,0,1,3,2,1,2,1};
   int n = sizeof(heights)/sizeof(heights[0]);
   cout << trapped(heights,n) << endl;
   return 0;
}
