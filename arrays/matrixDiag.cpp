/*
 * Khushboo Tekchandani
 * Print the elements of a matrix diagonally
 * Starting from (n,n)
 * Print (n,n-1),(n-1,n) etc
 */
#include <iostream>

using namespace std;

#define r 3
#define c 3

void printDiag(int arr[r][c], int n){

   int i,j,k;

   int dia = 2*n-1;

   for(i=dia-1; i>=0; i--){
      if(i<n)
         k = 0;
      else
         k = i-n+1;
      for(j=i-k; j>=k; j--)
         cout << arr[i-j][j] << " ";

      cout << endl;
   }

}

int main(){

   int arr[r][c] = {{1,2,3},{4,5,6},{7,8,9}};

   int n = 3;
   int i, j;

   printDiag(arr,n);

   return 0;
}
