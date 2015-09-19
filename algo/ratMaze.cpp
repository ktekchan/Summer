/*
 * Author: Khushboo Tekchandani
 * Rat in a Maze problem
 * Problem demonstrates the backtracking algorithm
 * Need to find a path to solve the maze
 */

#include <iostream>

#define size 4

using namespace std;

//Print the solution once it has been found
void print(int solution[size][size]){

   int i,j;

   for(i=0; i<size; i++){
      for(j=0; j<size; j++){
         cout << solution[i][j] << " ";
      }

      cout << endl;
   }
}

//Function to check if a step is valid or not
bool isValid(int maze[size][size], int x, int y){
   
   if(x>=0 && x<size && y>=0 && y<size && maze[x][y]==1)
      return true;
   else
      return false;
}

//Utility to help solve the maze
bool solveMazeUtil(int maze[size][size], int x, int y, int sol[size][size]){

   if(x==size-1 && y==size-1){
      sol[x][y] = 1;
      return true;
   }

   if(isValid(maze,x,y)) {

      sol[x][y]=1;

      if(solveMazeUtil(maze,x+1,y,sol))
         return true;

      if(solveMazeUtil(maze,x,y+1,sol))
         return true;

      sol[x][y]=0;
      return false;

   }

   return false;

}

//Driver function that solves the maze
bool solveMaze(int maze[size][size]){
   
   int sol[size][size];

   int i,j;

   //initialize the solution matrix to 0
   for(i=0; i<size; i++){
      for(j=0; j<size; j++){
         sol[i][j] = 0;
      }
   }

   if(solveMazeUtil(maze, 0, 0, sol)==false){
      cout << "Solution does not exist\n";
      return false;
   }

   else{
      print(sol);
      return true;
   }
   
}

int main(){

   int maze[size][size] = {{1,0,0,0}, {1,1,0,1},
      {0,1,0,0},{1,1,1,1}};

   solveMaze(maze);
   return 0;
}
