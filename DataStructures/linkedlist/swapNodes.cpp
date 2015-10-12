/*
 * Khushboo Tekchandani
 * Swap each pair of nodes in a linked list.
 * Keep track of the previous and next nodes of each node pair.
 */

#include <iostream>

using namespace std;

struct node{

   int data;
   node *next;
   node(int d) : data(d){
      this->next = NULL;
   }
};

node* swapNodes(node *head){
   
   if(head==NULL || head->next==NULL)
      return head;

   node *prev = new node(0);
   prev->next = head;
   node *nH = prev;

   while(prev->next!=NULL && prev->next->next!=NULL){
   
      node *p1 = prev;
      prev = prev->next;
      p1->next = prev->next;

      node *p2 = prev->next->next;
      prev->next->next = prev;

      prev->next = p2;
   }

   return nH->next;
}

void print(node *head){

   node *temp = head;
   while(temp!=NULL){
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}


int main(){

   node *head = new node(1);
   head->next = new node(2);
   head->next->next = new node(3);
   head->next->next->next = new node(4);

   print(head);
   head = swapNodes(head);
   print(head);

   return 0;
}
