/*
 * Khushboo Tekchandani
 * Search in a 2 D array with special features.
 * 1. Each row is sorted
 * 2. First row element is greater than last element of the previous row
 *
 * Idea: Use a binary search with the special features
 */

#include <iostream>

using namespace std;

#define R 3
#define C 4

bool binaryInRow(int mat [][C], int i, int start, int end, int num){

   if(start>end)
      return false;

   int mid = (start+end)/2;
   if(num ==  mat[i][mid])
      return true;

   if(num>mat[i][mid])
      return binaryInRow(mat, i, mid+1, end, num);
   else
      return binaryInRow(mat, i, 0, mid-1, num);
}

void search(int mat[][C], int num){

   int i;
   for(i=0; i<R-1; i++){
      if(num>=mat[i][0] && num<=mat[i+1][0])
         break;
   }

   cout << binaryInRow(mat, i, 0, C-1, num) << endl;
}
int main(){

   int arr[R][C] = {{1,3,5,7},
                    {10,11,16,20},
                    {23,30,34,50}
                  };


   search(arr, 4);
}
