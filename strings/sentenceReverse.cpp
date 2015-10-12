/*
 * Khushboo Tekchandani
 * Reverse the words in a string. Like reversing a sentence
 */

#include <iostream>

using namespace std;

void reverse(char *start, char *end){

   char temp;
   while(start<end){
      temp = *start;
      *start = *end;
      *end = temp;
      start++;
      end--;
   }
}

void reverseWords(char *s){

   char *temp = s;
   char *begin = NULL;

   while(*temp){
   
      if(begin==NULL && *temp!=' '){
         begin = temp;
      }

      if(begin && (*(temp+1)==' ') || (*(temp+1)=='\0')){
         reverse(begin,temp);
         begin = NULL;
      }

      temp++;
   }

   reverse(s,temp-1);
}

int main(){

   char str[] = "a lazy fox town";
   char *temp = str;
   reverseWords(str);
   cout << str << endl;
}
