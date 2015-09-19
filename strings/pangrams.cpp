/*
 * Author: Khushboo Tekchandani
 * Find whether a string is a pangram
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

void ispangram(string str){

   int alpha[26]={0};
   int len = str.length();
   int i;

   for(i=0; i<len; i++){
      if((int)str[i]>=97 && (int)str[i]<=122)
         alpha[(int)str[i]-97]++;
      if((int)str[i]>=65 && (int)str[i]<=90)
         alpha[(int)str[i]-65]++;
   }

   for(i=0; i<26; i++){
      if(alpha[i]==0){
         cout << "not pangram\n";
         return;
      }
   }

   cout << "pangram\n";
   return;
}

int main(){

   string str;
   getline(cin,str);
   ispangram(str);
   return 0;
}
