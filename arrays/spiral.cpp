/*
 * Author: Khushboo Tekchandani
 * Print a matrix spirally
 * Recursive solution
 */

#include <iostream>
using namespace std;

void spiral(int **mat, int r, int c, int x, int y){

   if(mat == NULL || r==0)
      return;

   if(r<=0 || c<=0)
      return;

   // one element
   if(r==1 || c==1){
      cout << mat[x][y] << " ";
      return;
   }

   // Move right
   for(int i=0; i<c-1; i++){
      cout << mat[x][y++] << " ";
   }

   // Move down
   for(int i=0; i<r-1; i++){
      cout << mat[x++][y] << " ";
   }

   // Move left
   if(r>1){
      for(int i=0; i<c-1; i++){
         cout << mat[x][y--] << " ";
      }
   }

   // Move up
   if(c>1){
      for(int i=0; i<r-1; i++){
         cout << mat[x--][y] << " ";
      }
   }

   if(r==1||c==1){
      spiral(mat,x,y,1,1);
   }
   else{
      spiral(mat, x+1, y+1, r-2, c-2);
   }

   return;
}

int main(){

   int row, col;
   cin >> row >> col;
   int ** mat;
   mat = new int*[row];

   for(int i=0; i<row; i++){
      mat[i] = new int[col];
   }

   for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
         cin >> mat [i][j];
      }
   }

   spiral(mat, row, col, 0,  0);
   cout << endl;
   return 0;
}

