/*
 * Author: Khushboo Tekchandani
 * Palindrome index problem 
 * Find the index of the char, the deletion of which makes the string a
 * palindrome.
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ispalindrome(string str){
   int i;
   int ret = 1;
   int len = str.length();
   for(i=0; i<len/2; i++){
      if(str[i] != str[len-1-i]){
         ret = 0;
         break;
      }
   }

   return ret;
}

int index(string str){
   int i,j;
   int len = str.length();
   int ret = -1;
   int flag = 0;


   if (ispalindrome(str))
      return ret;

   else{


      for(i=0; i<len/2; i++){
         if(str[i] != str[len-1-i]){
            if (flag==0){
               string temp = str;
               temp.erase(temp.begin()+i);
               str.erase(str.begin()+len-1-i);
               if(ispalindrome(temp)){
                  ret = i;
                  return ret;
               }
               else if(ispalindrome(str)){
                  ret = len-1-i;
                  return ret;
               }
               flag = 1;
            }
            else
               break;
         }
      }

      return ret;
   } 

}

int main(){

   int t, i;
   long long n;
   cin >> t;

   for (i=0; i<t; i++){
      string str;
      cin >> str;
      cout << index(str) << endl;
   }

   return 0;
}
