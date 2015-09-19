/*
 * -----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Problem 1 from Project Euler
 * Multiples of 3 and 5
 * ----------------------------------------------------------------------------
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   long long test, n, i, j, sum;
   long long terms3, terms5, terms15;
   long last3, last5, last15;
   vector<long> collection;

   cin >> test;

   for (j=0; j<test; j++){

      cin >> n;
      sum = 0;
      i = 0;
      terms3 = (n-1)/3;
      terms5 = (n-1)/5;
      terms15 = (n-1)/15;

      last3 = 3 + ((terms3 - 1)*3);
      last5 = 5 + ((terms5 - 1)*5);
      last15 = 15 + ((terms15 - 1)*15);

      sum = sum + ((3+last3)*terms3)/2;
      sum = sum + ((5+last5)*terms5)/2;
      sum = sum - ((15+last15)*terms15)/2;
      collection.push_back(sum);
   } 

   for (j=0 ; j<test; j++){
      cout << collection[j] << endl;
   }
   return 0;
}

