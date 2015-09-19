/*
 * Author: Khushboo Tekchandani
 * Anagram
 * Number of characters that need to be changed to make two strings an anagram
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void ana(string str){

   if(str.size()%2!=0){
      cout << -1 << endl;
      return;
   }

   int i,index;
   int alpha1[26] = {0};
   int alpha2[26] = {0};
   for(i=0; i<str.size()/2; i++){
      index = (int)str[i] - 'a';
      alpha1[index]++;
   }

   for(i=str.size()/2; i<str.size(); i++){
      index = (int)str[i] - 'a';
      alpha2[index]++;
   }

   int count = 0;
   for(i=0; i<26; i++){
      if(alpha1[i]>alpha2[i])
         count = count + alpha1[i] - alpha2[i];
      //count = count + (alpha1[i]-alpha2[i]);
   }

   cout << count << endl;
   return;
}


int main(){
   
   int i,t;
   string str;

   cin >> t;

   for(i=0; i<t; i++){
      cin >> str;
      ana(str);
   }

   return 0;
}
