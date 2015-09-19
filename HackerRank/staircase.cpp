/*-----------------------------------------------------------------------------
 * Author: Khushboo Tekchandani
 * Staircase problem
 ------------------------------------------------------------------------------
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static void staircase(int n){
   int i, j;
   for (i=1; i<=n; i++){
      for(j=1; j<=n-i; j++)
         cout << " ";
      for(j=1; j<=i; j++)
         cout << "#";
      cout << endl;
   }

   return;
}
int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

   int n;
   cin >> n;

   staircase(n);
   return 0;
}
