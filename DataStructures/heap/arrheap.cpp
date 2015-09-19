/*
 * Author: Khushboo Tekchandani
 * Heap implementation using an array
 */

#include <iostream>
#include <cstdio>

using namespace std;

void swap(int *a, int *b);

class minheap{
   private:
      int *arr;
      int capacity;
      int size;

   public:
      minheap(int capacity);
     void heapify(int i); //Heapify a subtree at an index i
      int parent(int i) {return ((i-1)/2);}
      int left(int i) {return (2*i +1);}
      int right(int i) {return (2*i + 2);}
      int getMin() {return arr[0];}
      void insert(int val);
      int extractMin();
      void decreaseKey(int i, int val);
      void del(int i);
};

void swap (int *a, int *b){
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

minheap::minheap(int capacity){
   this->capacity = capacity;
   size = 0;
   arr = new int[capacity];
}

void minheap::heapify(int i){
   int lt = left(i);
   int rt = right(i);
   int smallest = i;

   if (arr[lt] < arr[smallest] && lt < size)
      smallest = lt;
   if (arr[rt] < arr[smallest] && rt < size)
      smallest = rt;
   if (i!=smallest){
      swap(&arr[i], &arr[smallest]);
      heapify(smallest);
   }
   return;
}

void minheap::insert(int val){
   if (size == capacity){
      cout << "Heap is full\n";
      return;
   }

   size++;
   arr[size-1] = val;
   int index = size -1;

   while(index!=0 && arr[index] < arr[parent(index)]){
      swap(&arr[index], &arr[parent(index)]);
      index = parent(index);
   }

   return;
}

int minheap::extractMin(){
   if (size <= 0)
      return -1;
   if (size == 1){
      size--;
      return arr[0];
   }

   int min = arr[0];
   arr[0] = arr[size-1];
   size--;
   heapify(0);

   return min;

} 

void minheap::decreaseKey(int i, int val){
   if(size <= i){
      cout << "Index out of range.\n";
      return;
   }

   arr[i] = val;

   while(i!=0 && arr[parent(i)] > arr[i]){
      swap(&arr[i], &arr[parent(i)]);
      i = parent(i);
   }
   return;
}

void minheap::del(int i){
   decreaseKey(i, -999);
   extractMin();
}

int main(){
   
   minheap h(3);
   h.insert(4);
   h.insert(5);
   h.insert(6);
   h.del(0);
   cout << h.getMin() << endl;
   return 0;

}
