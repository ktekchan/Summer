/*
 * Khushboo Tekchandani
 * Implement a queue using stack
 * Idea : Interview cake
 */

#include <iostream>
#include <stack>

using namespace std;

class stackQueue{

   private:
      stack<int> inStack;
      stack<int> outStack;
   public:
      void enq(int data);
      int deq();
      int getInStackTop(){
         return inStack.top();
      }
      int getOutStackTop(){
         return outStack.top();
      }
};

void stackQueue::enq(int data){
   inStack.push(data);
}

int stackQueue::deq(){
   int temp;
   if(!outStack.empty()){
      temp = outStack.top();
      outStack.pop();
      return temp;
   }
   else{
      while(!inStack.empty()){
         temp = inStack.top();
         inStack.pop();
         outStack.push(temp);
      }
      temp = outStack.top();
      outStack.pop();
   }

   return temp;
}

int main(){

   stackQueue *sq = new stackQueue();
   sq->enq(1);
   sq->enq(2);
   sq->enq(3);
   cout << sq->deq() << endl;
   cout << sq->deq() << endl;
   return 0;
}
