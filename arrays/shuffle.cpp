/*
 * Khushboo Tekchandani
 * Shuffle a deck of cards represented as an array
 *
 * Fisher-Yates algorithm. Generate a random number between 0 to i at every step
 * and swap with the ith number
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shuffle(int arr[], int len){

   srand(time(NULL));
   for(int i=len-1; i>0; i--){
      int j = rand() % (i+1);
      swap(arr[i], arr[j]);
   }

   return;
}

int main(){

   int arr[52];
   int i;
   for(i=0; i<52; i++)
      arr[i] = i;
   shuffle(arr, 52);

   for(i=0; i<52; i++)
      cout << arr[i] << " ";
   cout << endl;
   return 0;
}
