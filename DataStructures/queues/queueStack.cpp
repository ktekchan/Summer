/*
 * Author: Khushboo Tekchandani
 * Implement a stack using two queues
 * Idea: Have two queues. To push: Enqueue in q2, dequeue everything from q1
 *       and enqueue to q2. Swap the names of q1 and q2
 */

#include <iostream>
#include <queue>

using namespace std;

class queueStack{
   private:
      queue<int> q1;
      queue<int> q2;
      queue<int> temp;
   public:
      void spush(int data);
      int spop();
};

void queueStack::spush(int data){
   q2.push(data);
   while(!q1.empty()){
      int num = q1.front();
      q2.push(num);
      q1.pop();
   }

   temp = q1;
   q1 = q2;
   q2 = temp;
}

int queueStack::spop(){
   int num;
   if(!q1.empty()){
      num = q1.front();
      q1.pop();
      return num;
   }
   else
      return -99999;
}

int main(){

   queueStack *qs = new queueStack();
   qs->spush(1);
   qs->spush(2);
   qs->spush(3);
   cout << qs->spop() << endl;
   cout << qs->spop() << endl;

   return 0;
}
