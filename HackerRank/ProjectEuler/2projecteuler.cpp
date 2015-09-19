/*
 -------------------------------------------------------------------------------
   * Author: Khushboo Tekchdani
   * Problem 2 from Project Euler
   * Even values of fibonacci
  -------------------------------------------------------------------------------
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static long long evensum(long long n){
   long long n1,n2,temp;
   n1 = 1;
   n2 = 2;
   long long sum = 2;
   long long i;
   while(n1+n2<=n){ 
      if ((n1+n2)%2 == 0)
         sum = sum+n1+n2;
      temp = n1;
      n1 = n2;
      n2 = n2+temp;
   }

   return sum;

}
int main() {

   long long t, n;
   vector<long long> out;
   cin >> t;
   int i;
   for (i=0; i<t; i++){
      cin >> n;
      out.push_back(evensum(n));
   }

   for (i=0; i<t; i++){
      cout << out[i] << endl;
   }
   return 0;
}
