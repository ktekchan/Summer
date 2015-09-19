/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Problem 6 Project Euler
 * Sum square difference prroblem
 ----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long sumsq(long long n){
   long long square;
   long long sum;
   long long diff;
   sum = n*(n+1)/2;
   square = n*(n+1)*((2*n)+1)/6;
   diff = (sum*sum)-square;
   return diff;
}

int main() {

   int i,t;
   long long n;
   long long out;
   cin >> t;

   for(i=0 ; i<t; i++){
      cin >> n;
      cout << sumsq(n) << endl;   
   }

   return 0;
}

