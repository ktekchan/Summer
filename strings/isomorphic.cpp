/*
 * Author: Khushboo Tekchandani
 * Find if two strings are isomorphic
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

void isomorphic(string str1, string str2){

   int i;

   if(str1.size() != str2.size()){
      cout << "No\n";
      return;
   }
   map<char, char> map1;
   map<char, char> map2;

   for(i=0; i<str1.size(); i++){
      if(map1.find(str1[i])==map1.end() && map2.find(str2[i])==map2.end()){
         map1[str1[i]] = str2[i];
         map2[str2[i]] = str1[i];
      }else{
         if(map1[str1[i]]!=str2[i] || map2[str2[i]]!=str1[i]){
            cout << "No\n";
            return;
          }
      }
   }

   cout << "Yes\n";
   return;
}

int main(){

   string str1 = "paper";
   string str2 = "title";

   isomorphic(str1,str2);

   return 0;
}
