/*
 * Author: Khushboo Tekchandani
 * Funny string problem
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

void funny(string str){
   int len = str.length();
   //char *rev = (char*)malloc(sizeof(char)*len);
   int i;

   for(i=1; i<len; i++){
      int ret1 = abs((int)str[i]-(int)str[i-1]);
      int ret2 = abs((int)str[len-i]-(int)str[len-i-1]);
      if(ret1!=ret2){
         cout << "Not Funny\n";
         return;
      }
    }

   cout << "Funny\n";
   return;
}

int main(){
   int i, t;
   cin >> t;

   for(i=0; i<t; i++){
      string str;
      cin >> str;
      funny(str);
   }

   return 0;
}
