/*
 * Author: Khushboo Tekchandani
 * Given a matrix of cost, find the min cost path to (m,n)
 * Allowed to moved down, right and diagonally right.
 * Dynamic Programming
 */

#include <iostream>

using namespace std;

#define R 3
#define C 3

int min(int a, int b, int c){

   if(a<b)
      return (a < c ? a : c);
   if(b<a)
      return (b < c ? b : c);

}

void minCost(int cost[R][C], int m, int n){

   if (m<0 || n<0){
      cout << "Cannot determine\n";
      return;
   }

   int totalCost[R][C];
   totalCost[0][0] = cost[0][0];

   int i,j;

   for(i=1; i<=m; i++)
      totalCost[i][0] = totalCost[i-1][0] + cost[i][0];

   for(j=1; j<=n; j++)
      totalCost[0][j] = totalCost[0][j-1] + cost[0][j];

   for(i=1; i<=m; i++){
      for(j=1; j<=n; j++){
         totalCost[i][j] = min(totalCost[i-1][j], totalCost[i][j-1], totalCost[i-1][j-1]) 
            + cost[i][j];
      }
   }

   cout << "Cost of minimum cost path is " << totalCost[m][n] << endl;

   return;
   

}

int main(){

   int cost [R][C] = {{1,2,3}, {4,8,2}, {1,5,3}};
   int m = 2;
   int n = 2;

   minCost(cost,m,n);

   return 0;
}
