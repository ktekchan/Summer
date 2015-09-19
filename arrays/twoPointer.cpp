/*
 * Greedy algorithms
 * Most basic example of the two pointer algorithm
 * Given two sorted arrays, a and b, find i and j such that a[i]+b[j] = x
 */

#include <iostream>

using namespace std;

void findTwo(int a[], int b[], int aSize, int bSize, int x){
   int i,j;
   i = 0;
   j = bSize-1;

   while(i<aSize){
      while(a[i]+b[j]>x && j>0)
         j--;
      if(a[i]+b[j]==x)
         cout << i << " " << j << endl;
      i++;
   }

   return;
}

int main(){
   
   int a[] = {1,2,3,4,5,6};
   int b[] = {4,5,7,8,9,11,12};

   int aSize = 6, bSize = 7;

   int x = 10;

   findTwo(a, b, aSize, bSize, x);

   return 0;
}
