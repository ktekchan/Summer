/*
 * Khushboo Tekchandani
 * Nqueens. Given an NxN chessboard, place N queens on the boards such that no
 * two queens can attack each other.
 */

#include <iostream>

using namespace std;

#define N 4


bool isValid(int board[N][N], int row, int col){

   int i,j;

   //Check for other queens in that row
   for(i=0; i<col; i++){
      if(board[row][i]==1)         
         return false;
   }

   // Check for other queens in that column
   for(i=0; i<row; i++){
      if(board[i][col]==1)
         return false;
   }

   //Check for upper left diagonal
   for(i=row,j=col; i>=0 && j>=0; i--,j--){
      if(board[i][j]==1)
         return false;
   }

   //Check for lower left diagonal
   for(i=row, j=col; i<N && j>=0; i++, j--){
      if(board[i][j]==1)
         return false;
   }

   return true;
}

bool helper(int board[N][N], int col){
   
   // If all queens are placed in appropriate columns till N-1
   if(col>=N)
      return true;

   int i;
   for(i=0; i<N; i++){
   
      //Check if placing this queen in this row is safe
      if(isValid(board,i,col)){
     
         // This is safe so proceed with placing other queens and trying this
         // recursively
         
         board[i][col]=1;
         
         if(helper(board,col+1))
            return true;

         //backtrack
         board[i][col]=0;
      }

   }

   // Nothing works out
   return false;
}

void nqueens(){

   int board[N][N] = { {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}
   };

   if(!helper(board,0))
      cout << "No solution\n";
   else{
   
      int i,j;
      for(i=0; i<N; i++){
         for(j=0; j<N; j++)
            cout << board[i][j] << " ";
         cout << endl;
      }

      cout << endl;
   }

}

int main(){
   
   nqueens();
   return 0;
}
