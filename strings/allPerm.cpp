/*
 * Author: Khushboo Tekchandani
 * Print all permutations of a given string
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

   if(l==r)
      cout << str << endl;
   else{
      for(i=l; i<=r; i++){
         swap((str+l),(str+i)); //Swap with ith elem
         allPerm(str,i+1,r); //new permutation
         swap((str+l),(str+i)); //Swap back to original to have only one ref
      }
   }
}


int main(){

   char str[] = "abcdef";
   int len = sizeof(str)/sizeof(char);
   allPerm(str,0,len-1);
   return 0;
}
