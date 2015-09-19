/*
 * Author: Khushboo Tekchandani
 * Does bigger string contain a substring that is an anagram of the smaller
 * string
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void subAna(string str1, string str2){

   int alpha1[26]={0};
   int alpha2[26]={0};

   int len1 = str1.size();
   int len2 = str2.size();

   int i, j, index;
   for(i=0; i<len1; i++){
      index = (int)str1[i] - 'a';
      alpha1[index]++;
   }

   for(i=0; i<len1; i++){
      index = (int)str2[i] - 'a';
      alpha2[index]++;
   }

   int flag = 0;

   for(j=0; j<26; j++){
      if(alpha1[j]!=alpha2[j])
         break;
      else if(j==25){
         flag=1;
         cout << "YES\n";
         return;
      }
   }

   for(i=len1; i<len2; i++){

      index = (int)str2[i] - 'a';
      alpha2[index]++;
      index = (int)str2[i-len1]-'a';
      alpha2[index]--;

      cout << str2.substr(i,i+len1-1) << endl;

      for(j=0; j<26; j++){
         if(alpha1[j]!=alpha2[j]){
            cout << j << endl;
            break;
         }
         else if(j==25){
            flag=1;
            cout << "YES\n";
            return;
         }
      }
   }

   cout << "NO\n";
   return;

}

int main(){

   string str1,str2;
   cin >> str1;
   cin >> str2;

   subAna(str1,str2);

}
