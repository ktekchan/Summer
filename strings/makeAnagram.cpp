/*
 * Author: Khushboo Tekchandani
 * Make Anagram
 * Find the number of char deletions required to make two strings anagrams of
 * each other
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void makeAna(const string &str1, const string &str2){

   int alpha1[26] = {0};
   int alpha2[26] = {0};
   int i,index;

   for(i=0; i<str1.size(); i++){
      index = (int)str1[i] - 'a';
      alpha1[index]++;
   }

   for(i=0; i<str2.size(); i++){
      index = (int)str2[i] - 'a';
      alpha2[index]++;
   }

   int count = 0;

   for(i=0; i<26; i++){
      count = count + abs(alpha1[i]-alpha2[i]);
   }

   cout << count << endl;
}


int main(){

   string str1,str2;
   cin >> str1;
   cin >> str2;

   makeAna(str1, str2);

   return 0;
}
