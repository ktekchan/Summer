/*
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(){

   string str ="Hello there, you";
   string str1 = str.substr(6,5);
   cout << str1 << endl;
   int len = str1.length();
   cout << len << endl;
   int start = len+6;
   cout << str.substr(start) << endl;

   return 0;
}
