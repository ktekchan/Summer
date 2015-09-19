/*
 * Author: Khushboo Tekchandani
 * Rotate an entire matrix
 * This has to be done clockwise
 */

#include <iostream>
#define R 3
#define C 3

using namespace std;


//Function to rotate an array
void rotateArr(int arr[R][C], int rsize, int csize){

  int row, col;
  int i,j;
  int prev, curr;
  row = 0;
  col = 0;

  while(row<R && col<C){
   
     if(row+1==rsize || col+1==csize)
        break;

     //Save the element of the next row same column
     prev = arr[row+1][col];

     //Move the elements of first row
     for(i=col; i<csize; i++){
         curr = arr[row][i];
         arr[row][i] = prev;
         prev = curr;
     }

     row++;

     //Move elements of the last column
     for(i=row; i<rsize; i++){
         curr = arr[i][csize-1];
         arr[i][csize-1] = prev;
         prev = curr;
     }

     //Reduce column index
      csize--;

      //Move elements of the last row
     for(i=csize-1; i>=col; i--){
         curr = arr[rsize-1][i];
         arr[rsize-1][i] = prev;
         prev = curr;
     }

      //Reduce row index
      rsize--;

      //Move elements of the first column
      for(i=rsize-1; i>=row; i--){
         curr = arr[i][col];
         arr[i][col] = prev;
         prev = curr;
      }

      col++;

  }

  for(i=0; i<R; i++){
     for(j=0; j<C; j++)
        cout << arr[i][j];
     cout << endl;
  }


}

//Driver function
int main(){

   int i,j;
   int rsize = R;
   int csize = C;

   int arr[R][C] = {{1,2,3},{4,5,6},{7,8,9}};


   rotateArr(arr, rsize, csize);
}
