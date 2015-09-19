/*
 * Author: Khushboo Tekchandani
 * Detect and remove loops from a linked list.
 * This inherently finds the startinf point of the loop
 *
 * Detection : Fast pointer Slow pointer technique
 * Removal: Find number of nodes in the loop;
 *          Start one ptr from head and one from loop node, move at the same
 *          pace, they meet the beginning.
 *          Point previous node to null
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
   int data;
   Node* next;
};

void insert(Node *head, int data){
   
   Node *temp = head;
   Node *node = (struct Node*)malloc(sizeof(Node));
   node->data = data;
   node->next = NULL;

   while(temp->next!=NULL){
      temp = temp->next;
   }

   temp->next = node;
}

void printlist(Node *head){
   
   Node *temp = head;
   while(temp!=NULL){
      cout << temp->data << "->";
      temp = temp->next;
   }

   cout << endl;
}

void removeLoop(Node *head, Node *loop){
   
   Node *ptr1 = loop;
   Node *ptr2 = loop;

   cout << "Loop node: " << loop->data << endl;
   int k = 1;

   // Number of nodes in the loop
   while(ptr1->next!=ptr2){
      ptr1 = ptr1->next;
      k++;
   }

   //One ptr at head
   ptr1 = head;

   //And other one at k nodes away from head
   int i;
   ptr2 = head;

   for(i=0; i<k; i++)
      ptr2 = ptr2->next;

   //Move both pointers at the same pace, they will meet at the beginning
   while(ptr1!=ptr2){
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
   }

   //Get one pointer to the last node
   ptr2 = ptr2->next;
   while(ptr2->next!=ptr1){
      ptr2 = ptr2->next;
   }

   cout << "Loop starts at: " << ptr1->data<< endl;
   ptr2->next = NULL;

}

int detectRemoveLoop(Node *head){
   
   Node *slow = head;
   Node *fast = head;

   while(slow!=NULL && fast!=NULL && fast->next!=NULL){
      slow = slow->next;
      fast = fast->next->next;
      if(slow==fast){
         cout << "Loop exists\n";
         removeLoop(head,slow);
         return 1;     
      }
   }
   return 0;
}

int main(){

   Node *head = (struct Node*)malloc(sizeof(Node));
   head->data = 1;
   head->next = NULL;

   insert(head,2);
   insert(head,3);
   insert(head,4);
   insert(head,5);

   printlist(head);
   head->next->next->next->next->next = head->next;
   detectRemoveLoop(head);
   cout << "After removing loop\n";
   printlist(head);
   return 0;
}
