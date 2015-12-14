#include <iostream>

using namespace std;

int search(int *arr, int t, int size){



   if(size <=0 || !arr)
      return -1;

   int left, right, mid;
   left = 0;
   right = size - 1;

   while(left<right){
      mid = (left+right+1)/2;

      if(arr[mid] > t){
         right = mid-1;
      }
      else{
         left = mid+1;
      }
   }

   if(arr[right]==t)
      return right;
   return -1;


}

int main(){

   int *arr = new int[7];
   for(int i=0; i<7; i++){
      arr[i] = i+1;
   }

   cout << search(arr, 4, 7);
}
