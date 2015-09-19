/*
 * Author: Khushboo Tekchandani
 * Basic string compression problem
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;

void compress(string str){
   int i, j;
   int len = str.length();
   string ret = "";

   i = 0;
   j = 0;
   char comp = str[i];
   int count = 0;

   while(i<len){
      comp = str[i];
      count = 0;
      while(str[i] == comp){
         count++;
         i++;
      } 
      stringstream ss;
      ss << count;
      string s = ss.str();
      ret = ret+comp+s;
   }

   if (ret.length() < len)
      cout << ret << endl;
   else
      cout << str << endl;

   return;
}

int main(){
   
   string str;
   cout << "Enter string for compression: ";
   cin >> str;
   compress(str);
   return 0;
}
