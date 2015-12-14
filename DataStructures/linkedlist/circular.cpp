/*
 * Author: Khushboo Tekchandani
 * Insert a node in a sorted circular linked list
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

Node* insert(Node* head, int data){
   
   Node *newNode = new Node(data);

   if(head == NULL){
      newNode->next = newNode;
      head = newNode; 
   }

   if(data <= head->data){
      
      Node* current = head;
      while(current->next != head){
         current = current->next;
      }

      current->next = newNode;
      newNode->next = head;
      head = newNode;
   }

   else{
     
      Node* current;
      current = head;
      while(current->data < data && current->next!=head){
         current = current->next;
      }

      newNode->next = current->next;
      current->next = newNode;
   }

   return head;
}

void printList(Node* head){

   if(head == NULL)
      return;

   Node* current;
   current = head;
   do{
   
      cout << current->data << " ";
      current = current->next;
   } while(current!=head);

}


int main(){

  Node *head = insert(NULL, 2);
  head = insert(head, 1);
  printList(head);
  cout << endl;

  head = insert(head, 3);
  printList(head);
  cout << endl;

  return 0;
}

