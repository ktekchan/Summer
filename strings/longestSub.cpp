/*
 * Khushboo Tekchandani
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * Idea: Keep a bool array to track existence of the character, when repeats,
 * move starting point to that index and reset the array.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int longestSub(string str){

   char exists[26] = {false};
   int currMax = 0;
   int i;
   int start = 0;

   for(i=0; i<str.length(); i++){
      
      if(exists[str[i]-'a']){
         currMax = max(currMax,i-start);
         start = i;

         // Reset the previous characters
         for(int j=start; j<i; j++){
            if(str[j]==str[i]){
               start = j+1;
               break;
            }
            exists[str[j]-'a']=false;
         }
      }
      else
         exists[str[i]-'a'] = true;
   }

   int len = str.length();
   currMax = max(currMax,len-start);
   return currMax;
}

int main(){
   string str = "abcabcbb";
   cout << longestSub(str) << endl;
   cout << longestSub("bbbb") << endl;
   return 0;

}
