/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Project euler problem 5
 * Smallest multiple problem
 -----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int n1, int n2){
   int temp;
   while(n2){
   
      temp = n2;
      n2 = n1%n2;
      n1 = temp;
   }

   return n1;
}

long long smallestmult(int n){
   long long ret = 1;
   int i;

   for(i=1; i<=n; i++){
      ret = (i*ret)/gcd(i,ret);
   }

   return ret;

}

int main() {

   int i,n,t;
   vector<long long> out;

   cin >> t;
   for (i=0; i<t; i++){
      cin >> n;
      out.push_back(smallestmult(n));
   }

   for (i=0; i<t; i++)
      cout << out[i] << endl;

   return 0;
}

