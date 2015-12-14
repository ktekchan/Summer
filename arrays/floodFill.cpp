/*
 * Khushboo Tekchandani
 * Flood fill. Replace all 'o' with 'x' if it is surrounded by 'x' on four sides
 * of it.
 * Idea : Replace 'o' with a different character like '-'. And then call a
 * recursive function
 */

#include <iostream>

using namespace std;

#define R 6
#define C 6

// function to replace O by -
void diff(char mat[][C], int r, int c){

   int i,j;
   for(i=0; i<r; i++){
      for(j=0; j<c; j++){
         if(mat[i][j]=='O')
            mat[i][j] = '-';
      }
   }
}

void replaceUtil(char mat[R][C], int r, int c, char prev, char next){

   // Bounds case
   if(r>=R || r<0 || c>=C || c<0)
      return;

   // If the char is not prev
   if(mat[r][c]!=prev)
      return;

   //replace
   mat[r][c] = next;

   //Recursive calls
   replaceUtil(mat, r+1, c, prev, next);
   replaceUtil(mat, r, c+1, prev, next);
   replaceUtil(mat, r-1, c, prev, next);
   replaceUtil(mat, r, c-1, prev, next);

}

void replace(char mat[R][C], int r, int c){
   
   // replace with a third character
   diff(mat, r, c);

   // replace all '-' on edges with 'O'
   // Left
   for(int i=0; i<R; i++){
      if(mat[i][0]=='-')
         replaceUtil(mat, i, 0, '-', 'O');
   }

   // Right
   for(int i=0; i<R; i++){
      if(mat[i][C-1]=='-')
         replaceUtil(mat, i, C-1, '-', 'O');
   }

   // Top
   for(int i=0; i<C; i++){
      if(mat[0][i]=='-')
         replaceUtil(mat, 0, i, '-', 'O');
   }

   // Bottom
   for(int i=0; i<C; i++){
      if(mat[R-1][i]=='-')
         replaceUtil(mat, R-1, i, '-', 'O');
   }

   // Replace all remaining '-' with 'O'
   for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
         if(mat[i][j] == '-')
            mat[i][j] = 'X';
      }
   }
}

int main(){

   char mat[R][C] = {{'X', 'O', 'X', 'X', 'X', 'X'},
      {'X', 'O', 'X', 'X', 'O', 'X'},
      {'X', 'X', 'X', 'O', 'O', 'X'},
      {'O', 'X', 'X', 'X', 'X', 'X'},
      {'X', 'X', 'X', 'O', 'X', 'O'},
      {'O', 'O', 'X', 'O', 'O', 'O'},
   };

   replace(mat, R, C);
   for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
         cout << mat[i][j] << " ";
      }

      cout << endl;
   }
   return 0;
}
