/*
 * Author: Khushboo Tekchandani
 * Gemstones
 * Find the number of characters that appear at least once in all the strings
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findElem(vector<string> str){
   
   int index;
   bool alpha[26];
   int gemElem[26] = {0};
   int i,j;
   int count = 0;
   for(i=0; i<str.size(); i++){
      
      //Initialize all alphabets existence to false
      fill(alpha,alpha+26,false);

      //Make the entries for existing alphabets in a gem as true
      for(j=0; j<str[i].size();j++){
         index = str[i][j] - 'a';
         alpha[index] = true;
      }

      //Increment count of gemstones having an element
      for(j=0; j<26; j++){
         if(alpha[j])
            gemElem[j]++;
      }

   }

   for(i=0; i<26; i++){
      if(gemElem[i]==str.size())
         count++;
   }

   cout << count << endl;

   return;
}


int main(){
   
   int n,i;
   vector<string> str;
   int elemCount[26] = {0};
   cin >> n;

   for(i=0; i<n; i++){
      string strIn;
      cin >> strIn;
      str.push_back(strIn);
   }

   findElem(str);

   return 0;
}
