/*
 * Khushboo Tekchandani
 * Find the longest palindromic substring
 * Idea : Fix a center, eith one character or two characters and then find the
 * longest string made by characters on either side which constitute a
 * plaindrome
 */

#include <iostream>
#include <cstring>

using namespace std;

string palindromeSub(string str, int begin, int end){
   
   while(begin>=0 && end<=str.length()-1 && str.at(begin)==str.at(end)){
      begin--;
      end++;
   }

   int len = end-begin;
   return str.substr(begin+1,len-1);
}

string lps(string str){

   if(str.length()==0)
      return NULL;
   if(str.length()==1)
      return str;

   string longest = str.substr(0,1);

   int i;
   for(i=0; i<str.length(); i++){
   
      string temp = palindromeSub(str,i,i);
      if(temp.length()>longest.length()){
         longest.erase(longest.begin(),longest.end());
         longest = temp;
      }

      string temp1 = palindromeSub(str,i,i+1);
      if(temp1.length()>longest.length()){
         longest.erase(longest.begin(),longest.end());
         longest = temp1;
      }

   }

   return longest;

}

int main(){

   string str = "defabbachi";
   cout << lps(str) << endl;
   return 0;
}
