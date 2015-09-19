/*
 * Author: Khushboo Tekchandani
 * Number of squares in a range
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int numsq(long long a, long long b){
   int ret;
   ret = floor(sqrt(b))-ceil(sqrt(a)) + 1;
   return ret;
}


int main(){
   int i,t;
   long long a,b;
   cin >> t;

   for (i=0; i<t; i++){
      cin >> a;
      cin >> b;
      cout << numsq(a,b) << endl;
   }

   return 0;
}
