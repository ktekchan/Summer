/*
 * Author: Khushboo Tekchandani
 * Implementation of stacks using a linked list
 *
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Stack{

   private:
      typedef struct snode{
         int data;
         snode *next;
      } node;

      node *top;
         
   public:
      Stack();
      ~Stack();
      int peek();
      void push(int);
      int pop();
      int stackempty();
      friend void printstack(Stack&);
};

Stack::Stack(){
   top = NULL;
}

Stack::~Stack(){
   while(top){
      node *temp = (node*)malloc(sizeof(node));
      top = top->next;
      free(temp);
   }
}

int Stack::peek(){
   return top->data;
}

void Stack::push(int n){
   node *temp = (node *)malloc(sizeof(node));
   temp->data = n;
   temp->next = top;
   top = temp;
}

int Stack::pop(){
   if(top != NULL){
      node *temp = (node *)malloc(sizeof(node));
      temp = top;
      int ret = temp->data;
      top = top->next;
      free(temp);
      return ret;
   }
   else
      return 0;
}

int Stack::stackempty(){
   if(top == NULL)
      return 1;
   else
      return 0;
}

void printstack(Stack &s){
   Stack::node *curr = s.top;
   while(curr){
      cout << curr->data << "-->";
      curr = curr->next;
   }

   cout << endl;

}

int main(){

   Stack *s = new Stack;
   cout << s->stackempty() << endl;
   s->push(1);
   s->push(2);
   s->push(3);
   printstack(*s);
   s->pop();
   printstack(*s);
   cout << "Top: " << s->peek() << endl;

   return 0;
}
