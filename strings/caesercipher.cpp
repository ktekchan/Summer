/*
 *  -----------------------------------------------------------------------------
 *  Author: Khushboo Tekchandani
 *  Caeser cipher problem
 *  ----------------------------------------------------------------------------
 */



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


static char* encrypt(char *s, int k, int n){

     int i;

     for (i=0; i<n; i++){
         if((s[i]>='a' && s[i]<='z')){
            s[i] = 'a' + ((s[i]-'a'+k)%26);
         }
         if ((s[i]>='A' && s[i]<='Z')){
            s[i] = 'A' + ((s[i]-'A'+k)%26);
         }
     }

     return s;
}

int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int n, k;
   cin >> n;
   char *str;
   str = (char*)malloc(sizeof(char)*n);
   cin >> str;
   cin >> k;

   string out;
   out = encrypt(str, k, n);
   cout << out << endl;
   return 0;
}
