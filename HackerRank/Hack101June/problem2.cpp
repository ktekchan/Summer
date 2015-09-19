#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static long long weirdsum(long long n, long long m){
   long long sum = 0;
   long long pos = 0;
   long long n1, m1;

   while(n && m){
      n1 = n%10;
      m1 = m%10;

      if(n1+m1>=10){
         sum = sum + (pow(10,pos)*9);
      }
      else {
         sum = sum + (pow(10,pos)*(n1+m1));
      }
      pos++;
      n /= 10;
      m /= 10;
   }

   while(n){
      n1 = n%10;
      sum = sum +(pow(10,pos)*n1);
      n /= 10;
      pos++;
   }

   while(m){
      m1 = m%10;
      sum = sum + (pow(10,pos)*m1);
      m /= 10;
      pos++;
   }
   return sum;
}


int main() {

   int t, i;
   long long n, m;
   vector<long long> out;
   cin >> t;

   for(i=0; i<t; i++){
      cin >> n;
      cin >> m;
      out.push_back(weirdsum(n,m));
   }

   for(i=0; i<t; i++){
      cout << out[i] << endl;
   }
   return 0;
}

