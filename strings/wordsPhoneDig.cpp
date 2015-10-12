/*
 * Khushboo Tekchandani
 * Print all possible words from phone digits
 * Idea: whenever character at position i changes, character at position i+1
 * goes through all possible characters and it creates ripple effect till we
 * reach at end.
 *
 * Recursion
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// Save all the characters corresponding to the digit on the phone
const char hash[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printPhoneWords(int number[], int currDigit, char out[], int len){

   //Base case to check if currDigit is len, then you have reached the output
   if(currDigit==len){
      cout << out << endl;
      return;
   }

   int i;
   for(i=0; i<strlen(hash[number[currDigit]]); i++){
      out[currDigit] = hash[number[currDigit]][i];
      printPhoneWords(number,currDigit+1,out,len);
      if(number[currDigit]==0||number[currDigit]==1)
         return;
   }
}

void printWords(int number[], int len){

   char out[len+1];
   out[len]='\0';
   printPhoneWords(number,0,out,len);

}

int main(){

   int number[] = {2,3,4};
   int len = sizeof(number)/sizeof(number[0]);
   printWords(number,len);
   return 0;
}
