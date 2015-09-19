/*
 * Author: Khushboo Tekchandani
 * Game of Thrones - I
 * Check if any anagram of the input string is a palindrome
 */

#include <iostream>
#include <string>

using namespace std;

int findKey(string str){
   
   int alpha[26] = {0};
   int i,index;
   int count = 0;
   
   for(i=0; i<str.size(); i++){
      index = (int)str[i] - 'a';
      alpha[index]++;
   }

   if(!str.size()%2){
      for(i=0; i<26; i++){
         if(alpha[i]%2 != 0)
            count++;
      }

      if(count!=0)
         return 0;
      else
         return 1;
   }

   else{
      
      for(i=0; i<26; i++){
         if(alpha[i]%2!=0)
            count++;
      }

      if(count>1)
         return 0;
      else
         return 1;

   }
}


int main(){

   string str;
   cin >> str;

   int flag  = findKey(str);
   if(flag == 0)
      cout << "NO";
   else
      cout << "YES";
   return 0;
}
