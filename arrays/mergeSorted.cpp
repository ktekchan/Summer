/*
 * Khushboo Tekchandani
 * Merge an array of size m+n containing m elements with an array of size n
 * Both of these are sorted arrays
 * Idea: Move all elements of m+n to the end
 *       Merge
 */

#include <iostream>

using namespace std;

void moveToEnd(int arr[], int size){

   int i, j;

   j = size-1;
   for(i=size-1; i>=0; i--){
      if(arr[i]!=-1){
         arr[j] = arr[i];
         j--;
      }
   }

}

void mergeArr(int arrMN[], int arrN[], int m, int n){
   
   int i,j,k;
   i = n; // where elements in arr m+n starts from
   j = 0; // starting of arrn
   k = 0; // starting of newly merged m+n

   while(k < (m+n)){
      if((j==n)||(i < m+n && arrMN[i]<=arrN[j])){
         arrMN[k] = arrMN[i];
         k++;
         i++;
      }

      else{
         arrMN[k] = arrN[j];
         k++;
         j++;
      }
   }

   for(i=0; i<(m+n-1); i++){
      cout << arrMN[i] << " ";
   }

   cout << endl;
} 

int main(){

   int arrMN[] = {2,8,-1,-1,-1,13,-1,15,20};
   int arrN[] = {5,7,9,25};
   
   int size = sizeof(arrMN)/sizeof(arrMN[0]);
   int n = sizeof(arrN)/sizeof(arrN[0]);
   int m = size - n;

   moveToEnd(arrMN,size);
   mergeArr(arrMN,arrN,m,n);

   return 0;
}
