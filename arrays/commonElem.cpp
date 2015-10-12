/*
 * Khushboo Tekchandani
 * Given a row-wise sorted matrix, find a common element in all the rows
 * Idea: Start with the last column of all rows and see if there is a common
 *       element. Otherwise, find the minimum element and reduce the index of
 *       all other columns
 */

#include <iostream>
#define r 4
#define c 5

using namespace std;

int findCommon(int mat[r][c]){

   // track the current indices of the columns of each row
   int column[r];

   // Index of the row holding the min value
   int minRowIndex;

   int i;
   // all rows currently at the last column
   for(i=0; i<r; i++)
      column[i] = c-1;

   minRowIndex = 0;
   // Keep a tab of number of rows having the same element
   // When count reaches r, return the element
   int count = 0;
   while(column[minRowIndex]>=0){

      //find the minimum of all the rows
      for(i=0; i<r; i++){
         if(mat[i][column[i]]<mat[minRowIndex][column[minRowIndex]])
            minRowIndex = i;
      }

      count = 0;

      // Decrease the column indices for those rows whose elements are 
      // greater than the minimum
      for(i=0; i<r; i++){
         if(mat[i][column[i]]>mat[minRowIndex][column[minRowIndex]]){
            if(column[i] == 0)
               return -1;
            column[i]--;
         }

         else
            count ++;
      }

      if (count==r)
         return mat[minRowIndex][column[minRowIndex]];
   }

   return -1;
}

int main(){

   int mat[r][c] = { {1, 2, 3, 4, 5},
      {2, 4, 5, 8, 10},
      {3, 5, 7, 9, 11},
      {1, 3, 5, 7, 9},
   };

   cout << findCommon(mat) << endl;

   return 0;
}
