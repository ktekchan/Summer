/*
 * Author: Khushboo Tekchandani
 * Find the number of digits of a number that exactly divide the number.
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


long long digits(long long n){
   int rem;
   long long num = n;
   int count = 0;
   while(n){
      rem = n%10;
      if(rem!=0 && num%rem==0)
         count++;
      n = n/10;
   }
   return count;
}


int main(){
   int i,t;
   long long n;

   cin >> t;
   for(i=0; i<t; i++){
      cin >> n;
      cout << digits(n) << endl;
   }
   return 0;
}

