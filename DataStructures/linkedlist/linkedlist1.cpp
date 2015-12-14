/*
 * Khushboo Tekchandani
 * Reverse a linked list from the middle
 */
#include <iostream>

using namespace std;

struct Node{

   int data;
   Node* next;

   Node(int d){
      data = d;
      next = NULL;
   }
};

struct Node* reverse(Node* head){

   Node* ret = (Node*)malloc(sizeof(Node));
   ret = head;

   if(head == NULL)
      return ret;
   else if(head->next == NULL){
      return ret;
   }
   else {
      ret = reverse(head->next);
      head->next->next = head;
      head->next = NULL;
      return ret;
   }
}

void reverseMid(Node* head){

   cout <<  "here";

   if(head == NULL)
      return;

   if(head->next == NULL)
      return;

   Node *slow = head;
   Node *fast = head;
   int mid = 0;

   // find the end and mid simultaneously
   while(fast->next->next != NULL && slow->next != NULL){
      fast = fast->next->next;
      slow = slow->next;
      mid++;
   }

   // Need to move one more step in order to achieve that
   slow = slow->next;
   cout << "slow " << slow->data << endl;
   mid++;
   cout << "mid " << endl;
   slow = reverse(slow);
   Node* curr = head;

   while(curr!=NULL){
      mid--;
      cout << curr->data  << " ";
      if(mid == 0){
         curr->next = slow;
      }
      curr = curr->next;
   }
   cout << endl;
}

int main(){

   Node *head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next = new Node(4);
   head->next->next->next->next = new Node(5);
   head->next->next->next->next->next = new Node(6);

   reverseMid(head);

   return 0;
}
