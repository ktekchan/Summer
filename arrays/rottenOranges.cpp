/*
 * Khushboo Tekchandani
 * Find the minimum time required to rot all oranges
 * 0 - empty cell
 * 1 - fresh orange
 * 2 - rotten orange
 * A rotten orange can rot oranges around itself
 *
 */

#include <iostream>
#include <queue>
#define ROW 3
#define COL 5

using namespace std;

struct elem{
   int x;
   int y;
};

// Check validity of a cell
bool isValid(int i, int j){
   return (i>=0 && i<ROW && j>=0 && j<COL);
}

// Check if an element is a delimiter
bool isDelem(elem e){
   return (e.x==-1 && e.y==-1);
}

int rotOranges(int arr[ROW][COL], int R, int C){

   queue<elem> q;
   int time = 0;

   // Add all rotten oranges that are already present in the arr and separate it
   // from the oranges that will rot in the future, using a delimiter (-1,-1)
   int i,j;
   elem temp;
   for(i=0; i<R; i++){
      for(j=0; j<C; j++){
         if(arr[i][j]==2){
            temp.x = i;
            temp.y = j;
            q.push(temp);
         }
      }
   }

   temp.x = -1;
   temp.y = -1;
   q.push(temp);

   // We need to mark the first orange to rot so that we can count the time from
   // there on
   while(!q.empty()){
      bool timeFlag = false;

      // Process these rotten oranges and rot the oranges around them
      while(!isDelem(q.front())){

         temp = q.front();

         // Check if the there is right cell
         if(isValid(temp.x,temp.y+1) && arr[temp.x][temp.y+1]==1){

            // Check if flag is set or not
            if(!timeFlag) time++, timeFlag = true;

            // Rot the orange
            arr[temp.x][temp.y+1] = 2;

            // Push this to the queue
            temp.y++;
            q.push(temp);

            // Go back to the original
            temp.y--;
         }

         // Check the left cell
         if(isValid(temp.x,temp.y-1) && arr[temp.x][temp.y-1]==1){

            if(!timeFlag) time++, timeFlag = true;

            arr[temp.x][temp.y-1] = 2;

            temp.y--;
            q.push(temp);

            temp.y++;
         }

         // Check the upper cell
         if(isValid(temp.x-1,temp.y) && arr[temp.x-1][temp.y]==1){

            if(!timeFlag) time++, timeFlag = true;

            arr[temp.x-1][temp.y] = 2;

            temp.x--;
            q.push(temp);

            temp.x++;
         }


         // Check the lower cell
         if(isValid(temp.x+1,temp.y) && arr[temp.x+1][temp.y]==1){

            if(!timeFlag) time++, timeFlag = true;

            arr[temp.x+1][temp.y] = 2;

            temp.x++;
            q.push(temp);

            temp.x--;
         }

         q.pop();
      }
      // popping the delimiter
      q.pop();

      if(!q.empty()){
         temp.x=-1;
         temp.y=-1;
         q.push(temp);
      }

   // Now check if all oranges are rotten. If so return time, else return -1
      for(i=0; i<R; i++){
         for(j=0; j<C; j++){
            if(arr[i][j]!=0 && arr[i][j]!=2)
               time = -1;
         }
      }
      
   }
   return time;
}

int main(){

   int arr[ROW][COL] = { {2, 1, 0, 2, 1},
      {1, 0, 1, 2, 1},
      {1, 0, 0, 2, 1}};

   cout << rotOranges(arr,ROW,COL) << endl;
   int i,j;
   for(i=0; i<ROW; i++){
      for(j=0; j<COL; j++)
         cout << arr[i][j] << " ";
      cout << endl;
   }

   return 0;
}
