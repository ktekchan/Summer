/*
 * Author: Khushboo Tekchandani
 * Remove all spaces from a string
 */

#include <iostream>
#include <string>

using namespace std;

void removeSpaces(char* str){
   
   int count = 0;
   int i = 0;

   while(str[i]){
      
      if(str[i]!=' '){
         str[count] = str[i];
         count++;
         i++;
      }

      else
         i++;
   }

   str[count] = '\0';
   
   cout << str << endl;
}

int main(){
   
   char str[] = "geeks    f  or gee  ks ";
   removeSpaces(str);

   return 0;
}
