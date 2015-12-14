/*
 * Khushboo Tekchandani
 * Regex pattern matching. For . and *. '.' matches any single character and
 * '*' matches 0 or more preceeding characters
 * Idea: Use recursion
 */

#include <iostream>

using namespace std;

bool regexMatch(char *str, char *pat){

   // If it is an empty pattern
   if(*pat =='\0')
      return (*str=='\0');

   // If next character of pat is not *, string must match the current character
   if(*(pat+1) != '*'){
      return (((*pat == *str) || (*pat=='.' && *str!='\0')) && regexMatch(str+1, pat+1));
   }

   // If next character of pat is *
   while((*pat == *str) || (*pat=='.' && *str!='\0')){
      if (regexMatch(str,pat+2))
         return true;
      str++;
   }

   return regexMatch(str,pat+2);
}

int main(){

   char str[] = "abbba";
   char pat[] = "ab*a";
   cout << regexMatch(str,pat) << endl;
   return 0;
}
