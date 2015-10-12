/*
 * Khushboo Tekchandani
 * There are N children standing in a line. Each child is assigned a rating
 * value. You are giving candies to these children subjected to the following
 * requirements:
 *
 * 1. Each child must have at least one candy.
 * 2. Children with a higher rating get more candies than their neighbors.
 *
 * What is the minimum candies you must give?
 *
 * Idea : Scan from the front and assign candies. If in ascending order assign
 * one extra. Scan from the back and calculate the result
 */

#include <iostream>

using namespace std;

int distribute(int ratings[], int n){

   int *candies =  new int[n];
   int i;

   candies[0] = 1;
   for(i=1; i<n; i++){
      
      if(ratings[i]>ratings[i-1])
         candies[i] = candies[i-1]+1;
      else
         candies[i] =1;
   }

   int result = candies[n-1];

   for(i=n-2; i>=0; i--){
      int curr = 1;
      if(ratings[i]>ratings[i+1])
         curr = candies[i+1] + 1;
      candies[i] = curr;
      result = result+candies[i];
//      result = result + max(curr, candies[i]);
   }

   return result;
}

int main(){
   int kids[] = {1 ,4, 3,3,3, 1};
   int n = sizeof(kids)/sizeof(kids[0]);
   cout << distribute(kids, n) << endl;
   return 0;
}
