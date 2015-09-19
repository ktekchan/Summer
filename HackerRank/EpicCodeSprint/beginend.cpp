/*-----------------------------------------------------------------------------
 *   Author: Khushboo Tekchandani
 *   Hacker Rank Epic Code Sprint
 *   Begin End Problem
-----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT*/

   int i, j;  
   long len, sum;
   cin >> len;
   char input[len];
   cin >> input;
   long alphabet[26] = {0};
   int index;
   sum = 0;

   for (i=0; i<len; i++){

      if (input[i] >= 'A' && input[i] <= 'Z' )
         input[i] = input[i] + 32;

      index = input[i]-'a';
      alphabet[index]++;
   }

   for (i=0; i<26; i++){
      if(alphabet[i] != 0){
         sum = sum + ((alphabet[i]*(alphabet[i]-1))/2);
      }
   }

   sum = sum + len;
   
   cout << sum << endl;
   return 0;
}
