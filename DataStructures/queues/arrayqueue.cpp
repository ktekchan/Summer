/*
 * Author: Khushboo Tekchandani
 * Implementation of Queue using an array
 */


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* Class definition */
class queue{

   private:
      int front, rear, size;
      int capacity;
      int *arr;
      
   public:
      queue(int);
      ~queue();
      int isfull();
      int isempty();
      int frontindex();
      int rearindex();
      void enqueue(int);
      int dequeue();
      friend void printqueue(queue&);
};

/* Constructor to initialize queue with capacity 'capacity' */
queue::queue(int capacity){
   front = 0;
   rear = 0;
   size = 0;
   this->capacity = capacity;
   arr = (int*)malloc(sizeof(int)*capacity);
}

/* Destructor */
queue::~queue(){

   free (arr);
}

/* Checks if the queue is full */
int queue::isfull(){
   if(front==0 && rear==capacity)
      return 1;
   else
      return 0;
}

int queue::isempty(){
   
   if(front==0 && rear==0)
      return 1;
   else
      return 0;
}

/* Returns the front of the queue */
int queue::frontindex(){
   return front;
}

/* Returns the rear of the queue */
int queue::rearindex(){
   return rear;
}

/* Enqueues an element at the rear */
void queue::enqueue(int elem){
   if(this->isfull())
      cout << "Queue is full\n";
   else{
      arr[rear] = elem;
      rear++;
      size++;
      cout << "Added: " << arr[rear-1] << endl;
   }
   return;
}

/* Dequeues an element from the front */
int queue::dequeue(){
   int ret;
   if(this->isempty()){
      cout << "Queue is empty\n";
      ret = 0;
   }
   else{
      ret = arr[front];
      front++;
      size--;
   }
   return ret;
}

/* Prints the queue */
void printqueue(queue &q){
   int i;
   for (i=q.front; i<=q.size; i++){
      cout << q.arr[i] << "-->";
   }
   cout << endl;
}


/* Driver */
int main(){

   queue *q = new queue(3);
   cout << q->isfull() << endl;
   q->enqueue(1);
   q->enqueue(2);
   q->enqueue(3);
   q->enqueue(4);
   cout << q->dequeue() << endl;
   printqueue(*q);
   return 0;
}
