/*
 * Khushboo Tekchandani
 * Print all possible permutations of a string
 */

#include <iostream>
#include <string>

using namespace std;

void swap(char *x, char *y){
   char temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

void allPerm(char *str, int l, int r){
   int i;

   if(l==r){
      cout << str <<endl;
   }
   else{
      for(i=l; i<=r; i++){
         swap((str[l]),(str[i]));
         allPerm(str, l+1, r);
         swap((str[l]), (str[i]));
      }
   }
}    

int main(){

   char str[] = "ABC";
   int len = sizeof(str)/sizeof(str[0]);
   cout << len << endl;
   allPerm(str,0,len-1);
   return 0;
}
