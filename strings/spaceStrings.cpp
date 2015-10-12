/*
 * Khushboo Tekchandani
 * Print all strings that can made from a string by placing spaces in the string
 */

#include <iostream>
#include <string>

using namespace std;

void spaceStrings(char str[], char buffer[], int i, int j, int len){
   
   if(i==(len-1)){
      buffer[j] = '\0';
      cout << buffer << endl;
      return;
   }

   buffer[j] =  str[i];
   spaceStrings(str, buffer, i+1, j+1, len);

   buffer[j] = ' ';
   buffer[j+1] = str[i];
   spaceStrings(str, buffer, i+1, j+2, len);

   return;
}

int main(){

   char str[] = "abc";
   int len = sizeof(str)/sizeof(str[0]);
   char buffer[2*len] = {'\0'};
   buffer[0] = str[0];
   spaceStrings(str, buffer, 1, 1, len);
   return 0;
}
