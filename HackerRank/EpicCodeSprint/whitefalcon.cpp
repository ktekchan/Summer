/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Hacker Rank Epic Code Sprint
 * White Falcon and Sequence Problem
-------------------------------------------------------------------------------*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){

   int i, j, k;

   long n;
   cin >> n;
   cout << n;
   long long A[n];
   long long prodA[n][n];
   long long currentmax = 0;
   long long sum;

   for (i=0; i<n; i++){
      cin >> A[i];
   }

   for (i=0; i<n; i++){
   
      for(j=0; j<n; j++){
      
         prodA[i][j] = A[j]*A[n-i-1];
      }
   }

   i=0;
   j=0;
   k=0;

   for(k=n-2; k>0; k--){
   
      i=0;
      j=k;
      sum=0;

      while(i<n-j-1){
      
         sum = sum + prodA[i][j];
         i++;
         j++;
      }

      if (sum>currentmax)
         currentmax = sum;
   }

   for(k=0; k<n-1; k++){
   
      i=k;
      j=0;
      sum=0;

      while(i<n-j-1){
      
         sum = sum + prodA[i][j];
         i++;
         j++;
      }

      if (sum>currentmax)
         currentmax = sum;
   } 


   cout << currentmax << endl;
   return 0;
}

