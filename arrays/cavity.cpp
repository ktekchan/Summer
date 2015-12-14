/*
 * Author: Khushboo Tekchandani
 * Fill the cavities with x. Cavity - should not be an edge cell and mus tbe
 * surrounded by all cells smaller than itself.
 */

#include <iostream>

using namespace std;


void cavity(int **mat, int n){

   int i, j;
   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
         if(i==0 || j==0 || i==n-1 || j==n-1){
            continue;
         }
         else{
            if(mat[i-1][j]<mat[i][j]  && mat[i][j-1]<mat[i][j] 
                  && mat[i][j+1]<mat[i][j] && mat[i+1][j]<mat[i][j]){
               mat[i][j] = 10;
            }
         }
      }
   }

   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
         if(mat[i][j]==-1){
            cout << 'X';
         }
         else{
            cout << mat[i][j];
         }
      }
      cout << endl;
   }

   return;
}

int main(){


   int n;
   cin >> n;
   int **mat;
   mat = new int*[n];
   int i,j;
   for(i=0; i<n; i++){
      mat[i] = new int[n];
   }


   char ch;
   int num;
   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
         cin >> ch;
         int num = ch;
         mat[i][j] = num % 48;
      }
   }

   cavity(mat, n);

   return 0;
}
