/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Hacker Rank Epic Code Sprint
 * Dance in Pairs Problem
-----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT*/
   long n, k;
   long pairs = 0;
   int i,j;

   cin >> n;
   cin >> k;

   long boys[n];
   long girls[n];

   for(i=0; i<n; i++){
      cin >> boys[i];
   }

   for(i=0; i<n; i++){
      cin >> girls[i];
   }

   sort(boys, boys+n);
   sort(girls, girls+n);

   i = 0;
   j = 0;
   while(i!=n && j!=n){
      if(abs(boys[i]-girls[j]) <= k){
         pairs++;
         i++;
         j++;
      }
      else if(boys[i]<girls[j])
         i++;
      else
         j++;
   }

   cout << pairs << endl;
   return 0;
}
