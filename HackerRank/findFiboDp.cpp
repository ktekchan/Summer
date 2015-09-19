/*
 * Author: Khushboo Tekchandani
 * Find the nth Fibonacci number given the first and second fibonacci number
 * This solution uses dynamic programming
 */

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

long long findFibo(long long a, long long b, long long n){
    if(n==0){
       return a;
    }
    else if(n==1){
       return b;
    }

    long long c;
    for(int i=2; i<=n; i++){
      c = a+b;
      a = b;
      b = c;
    }

    return c;
}

int main(){
   int i, t;

   long long a, b, n;
   cin >> t;

   for(i=0; i<t; i++){
      cin >> a;
      cin >> b;
      cin >> n;
     // long long *dp = new long long [n+1]();
     // dp[0] = a;
     // dp[1] = b;
      cout << findFibo(a,b,n) << endl;
   //   delete dp;
   }

   return 0;
}
