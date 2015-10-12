/*
 * Khushboo Tekchandani
 * Given weights and values of n items, put these items in a knapsack of
 * capacity W to get the maximum total value in the knapsack.
 *
 * Start from the back. If last item weight > w, then that cannot be included
 * else two cases, max (nth val included, nth value not included)
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int knapsack(int w, int wt[], int val[], int n){

   if(n==0||w==0)
      return 0;

   if(wt[n-1]>w)
      return knapsack(w,wt,val,n-1);
   else
      return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1) , knapsack(w,wt,val,n-1));
}

int main(){

   int val[] = {60,100,120};
   int wt[] ={10,20,30};
   int w = 50;
   int n = sizeof(val)/sizeof(val[0]);
   cout << knapsack(w,wt,val,n) << endl;
   return 0;
}

