/*
 * Author: Khushboo Tekchandani
 * Find if a substring is there in two strings
 * (This technically requires only to find one common character in both strings
 */

#include <iostream>
#include <string>

using namespace std;

void hasSub(string str1, string str2){

   int alpha1[26] ={0};
   int alpha2[26] ={0};

   int i,index;
   for(i=0; i<str1.size(); i++){
      index = (int)str1[i] - 'a';
      alpha1[index]++;
   }

   for(i=0; i<str2.size(); i++){
      index = (int)str2[i] - 'a';
      alpha2[index]++;
   }

   for(i=0; i<26; i++){
      if(alpha1[i]>0 && alpha2[i]>0){
         cout << "YES\n";
         return;
      }
   }

   cout << "NO\n";
   return;
}

int main(){
   
   int i,t;
   cin >> t;

   string str1, str2;
   for(i=0; i<t; i++){
      
      cin >> str1;
      cin >> str2;

      hasSub(str1,str2);
   }

   return 0;
}
