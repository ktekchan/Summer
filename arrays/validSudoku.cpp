/*
 * Author: Khushboo Tekchandani
 * Check if a given Sudoku is valid or not
 * Here checking for 9x9
 * Idea: Keep a new array to see if the number from 0 - 9 is present in each
 * row, column and matrix
 */

#include <iostream>

using namespace std;

bool isValidSudoku(char **mat, int n){

   // Check each row
   int i,j;
   bool isPresent[9] = {false};
   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
         if(mat[i][j] != '.'){
            if(isPresent[(int)(mat[i][j]-'1')])
               return false;
            isPresent[(int)(mat[i][j]-'1')] = true;
         }
      }
   }

   for(i=0; i<9; i++)
      isPresent[i] = false;

   // Check each column
   for(j=0; j<n; j++){
      for(i=0; i<n; i++){
         if(mat[i][j] !='.'){
            if(isPresent[(int)(mat[i][j]-'1')])
               return false;
            isPresent[(int)(mat[i][j]-'1')] = true;
         }
      }
   }

   for(i=0; i<9; i++)
      isPresent[i] = false;

   // Check for each 3x3 matrix
   for (int block = 0; block < 9; block++) {
      for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++) {
         for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {
            if (mat[i][j] != '.') {
               if (isPresent[(int) (mat[i][j] - '1')]) {
                  return false;
               }
               isPresent[(int) (mat[i][j] - '1')] = true;
            }
         }
      }
   }

   return true;
}

int main(){


}
