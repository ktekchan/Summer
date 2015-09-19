/*
 * Author: Khushboo Tekchandani
 * Implementation of stacks using an array
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/* Basic structure for stack */
struct stack{

   int *arr;
   int top;
   int capacity;
};

/* Creates a stack with given capactiy */
struct stack* createstack(int capacity){
   struct stack* Stack = (struct stack*)malloc(sizeof(struct stack)*capacity);
   Stack->top = -1;
   Stack->capacity = capacity;
   Stack->arr = (int *)malloc(sizeof(int)*capacity);

   cout << "Created stack of size " << capacity << endl;
   return Stack;
}

/* Returns 1 if stack is empty, 0 otherwise */
int stackempty(struct stack* Stack){
   if (Stack->top == -1)
      return 1;
   else
      return 0;
}

/* Returns 1 if stack is full, 0 otherwise */
int stackfull(struct stack* Stack){
   if(Stack->top == Stack->capacity-1)
      return 1;
   else
      return 0;
}

/* Returns the top element of a Stack */
int peek(struct stack* Stack){
   return Stack->top;   
}

/* Pushes an element to the stack */
void push(struct stack* Stack, int elem){
   if(stackfull(Stack)){
      cout << "Stack is full, cannot push element\n";
      return;
   }

   else{
      Stack->arr[++Stack->top]=elem;
      cout << "Pushed " << elem << " to the stack\n";
   }

   return;
}

/* Pop the top element of the stack */
void pop(struct stack* Stack){
   if(stackempty(Stack))
      return;
   else{
      cout << "Popped " << Stack->arr[Stack->top] << endl;
      Stack->top--;
   }
   
   return;

}

/* Main function */
int main(){

   struct stack* Stack;
   int capacity = 2;

   Stack = createstack(capacity);
   cout << stackempty(Stack) << endl;
   push(Stack,1);
   push(Stack,2);
   push(Stack,3);
   push(Stack,4);

   pop(Stack);
   push(Stack,4);
   
   cout << peek(Stack) << endl;

   return 0;
}


