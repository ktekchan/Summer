/*
 * Author: Khushboo Tekchandani
 * atoi
 * Convert each char to int and multiply by 10 and add the remaining
 */

#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str){

   int i = 0;
   int num = str[i++] - '0';

   while(i<str.length()){
      num = num*10 + str[i++] - '0';
   }

   return num;
}


int main(){

   string str = "12345";
   cout << myAtoi(str) << endl;
}
