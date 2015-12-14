/*
 * Khushboo Tekchandani
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * Idea : Find the max profit on left of i and then on right of i.
 *        For all left and right i, add them and find the max
 *
 */

#include <iostream>

using namespace std;

int maximizeProfit(int prices[], int len){

   if(len<2)
      return 0;
   // Two arrays for storing max profit before and after i
   int *left = new int[len];
   int *right = new int[len];

   // Two find the max on left of i, we do a DP like solution from left to 
   // right and find the min price at each point to calculate the current max
   left[0] = 0;
   int minPrice = prices[0];
   int i;
   for(i=1; i<len; i++){
      minPrice = min(minPrice, prices[i]);
      left[i] = max(left[i-1], prices[i]-minPrice);
   }

   // Similarly for the right of i, we calculate the max price at each time to
   // calculate the current max profit
   right[len-1] = 0;
   int maxPrice = prices[len-1];
   for(i=len-2; i>=0; i--){
      maxPrice = max(maxPrice, prices[i]);
      right[i] = max(right[i+1], maxPrice-prices[i]);
   }

   // Now to calculate the profit, we iterate through the left and the right
   // transaction profits
   int maxProfit = 0;
   for(i=0; i<len; i++){
      maxProfit = max(maxProfit, left[i]+right[i]);
   }

   return maxProfit;

}


int main(){

   int prices[] = {1,4,5,7,6,3,2,9};
   int len = sizeof(prices)/sizeof(prices[0]);
   cout << maximizeProfit(prices, len) << endl;
   return 0;
}
