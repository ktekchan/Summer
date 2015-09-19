/*
 * Author: Khushboo Tekchandani
 * Alternating characters, find the number of deletions problem
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int numdel(string str){
   int i;
   int ret = 0;

   for (i=0; i<str.length()-1; i++){
      if(str[i]==str[i+1])
         ret++;
   }

   return ret;
}

int main(){
   int i, t;

   cin >> t;

   for(i=0 ; i<t; i++){
      string str;
      cin >> str;
      cout << numdel(str) << endl;
   }

   return 0;
}
