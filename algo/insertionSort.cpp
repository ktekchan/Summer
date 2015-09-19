/*
 * Insertion sort
 */

#include <iostream>

using namespace std;

void insertionSort(int ar_size, int *ar){
   int i,j,k;
   int val;

   for(k=0; k<ar_size; k++){
      val = ar[k];

      for(i=0; i<ar_size; i++){
         if(ar[k] < ar[i]){
            swap(ar[k],ar[i]);
         }

      }

      for(j=0; j<ar_size; j++)
         cout << ar[j] << " ";
      cout << endl;
   }
}

int main(){

   int _ar_size;
   cin >> _ar_size;

   int _ar[_ar_size], _ar_i;

   for(_ar_i=0; _ar_i<_ar_size; _ar_i++){
      cin >> _ar[_ar_i];
   }

   insertionSort(_ar_size, _ar);

   return 0;
}
