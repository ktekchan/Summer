/*
 * Find the number of distinct elements in every window of size k
 * Geeks for Geeks (Arrays)
 */

#include <iostream>

using namespace std;

int countInK(int win[], int k){
   int i,j;
   int count = 0;

   for(i=0; i<k; i++){
      for(j=0; j<i; j++){
         if(win[i] == win[j])
            break;
      }
      if(j==i)
         count++;
   }

   return count;
}

void countDist(int arr[], int n, int k){

   int i;
   for(i=0; i<=n-k; i++)
      cout << countInK(arr+i,k) << endl;

   return;
}

int main(){

   int arr[] = {1,2,1,3,4,2,3};
   int k = 4;
   int n = sizeof(arr)/sizeof(arr[0]);
   countDist(arr,n,k);
   return 0;

}
