/*
 * Khushboo Tekchandani
 * Compare two strings lexicographically but whenever you account 'ch', place it
 * between 'h' and 'i'
 */

#include <iostream>
#include <cstring>

using namespace std;

void compare(char *str1, char *str2){

   // preprocess and replace 'ch' with 'AA'
   int len1 = strlen(str1);
   int len2 = strlen(str2);

   int i;

   for(i=0; i<len1-1; i++){
      if(str1[i]=='c' && str1[i+1] == 'h'){
         str1[i] = 'A';
      cout << "here1\n";
         str1[i+1] = 'A';
      }
   }

   cout << "here\n";
   for(i=0; i<len2-1; i++){
      if(str2[i]=='c' && str2[i+1] == 'h'){
         str2[i] = 'A';
         str2[i+1] = 'A';
      }
   }

   int high = 0;
   for(i=0; i<len1 && i<len2; i++){
   
      if(str1[i] == 'A' && str2[i] == 'h'){
         //indicate str1 > str2
         high = 1;
         i++;
      }

      else if(str1[i] > str2[i]){
         high = 1;
      }
   }

   for(i=0; i<len1-1; i++){
      if(str1[i]=='A' && str1[i+1] == 'A'){
         str1[i] = 'c';
         str1[i+1] = 'h';
      }
   }

   for(i=0; i<len2-1; i++){
      if(str2[i]=='A' && str2[i+1] == 'A'){
         str2[i] = 'c';
         str2[i+1] = 'h';
      }
   }

   if(high)
      cout << str1 << " is higher than " << str2 << endl;
   else
      cout << str2 << " is higher than " << str1 << endl;

   return;
}


int main(){

   char str1[] = "teach";
   char str2[] = "weai";
   compare(str1,str2);
   return 0;
}
