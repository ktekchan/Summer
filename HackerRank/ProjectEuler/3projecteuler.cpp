/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Problem 3 Project Euler
 * Largest Prime Factor
-----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


static long long largestprime(long long n){

   long long out = 1;
   long long i;

   while(n%2==0){
      n = n/2;
      out = 2;
   }

   for(i=3; i<=(int)sqrt(n); i+=2){
      while(n%i == 0){
         n = n/i;
         out = i;
      }
   }

   if(n>2)
      out = n;

   return out;
}

int main() {

   int t, i;
   cin >> t;

   long long n;
   vector <long long> out;

   for (i=0; i<t; i++){
      
      cin >> n;
      out.push_back(largestprime(n));
   }

   for (i=0; i<t; i++){
      cout << out[i] << endl;
   }
   return 0;
}
