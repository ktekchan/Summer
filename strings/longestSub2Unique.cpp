/*
 * Khushboo Tekchandani
 * Find the longest substring with only two unique characters
 * Idea : Keep track of two unique characters and their last appearance index
 * in the string.
 */

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

string longestSub(string str){

   int maxLen = 0;
   string longest = "";
   int m = 0;

   map<char, int> hash;

   int i, j;
   for(i=0; i<str.length(); i++){

      char ch = str[i];
      // if hashmap contains two characters including this character, process it
      if(hash.size()==2 && hash.find(ch)==hash.end()){
         if(i-m > maxLen){
            maxLen = i-m;
            longest.erase(longest.begin(),longest.end());
            longest = str.substr(m, i-m);
         }

         // get the leftmost index so that the new index will start from the one
         // next to the left most index
         int left = str.length();
         for(auto &iter: hash){   
            if(iter.second < left)
               left = iter.second;
         }

         // Start longest string from the character next to the one removed
         m = left + 1;
         hash.erase(str[left]);
      }

      hash[ch] = i;
   }


   if(hash.size()==2 && maxLen==0)
      return str;

   return longest;
}

int main(){

   string str = "abaaabc";
   cout << longestSub(str) << endl;
   return 0;
}
