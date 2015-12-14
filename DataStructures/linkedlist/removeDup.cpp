/*
 * Author: Khushboo Tekchandani
 * Remove duplicates from a linked list.
 * Idea: Keep adding elements to a set and keep track of previous pointer, so
 * that if an element is repeated, its previous can point to its next
 */

#include <iostream>
#include <set>

using namespace std;

struct node{
   int data;
   node *next;
   node(int d){
      data = d;
      next = NULL;
   }
};

void printlist(node *head){
   node *curr = head;
   while(curr!=NULL){
      cout << curr->data << " ";
      curr = curr->next;
   }
   cout << endl;
}

node* removeDuplicate(node* head){
   set<int> elems;
   node *prev = head;
   node *curr = head;

   elems.insert(curr->data);
   prev = curr;
   curr= curr->next;

   while(curr!=NULL){
      if(elems.find(curr->data)!=elems.end()){
         prev->next = curr->next;
         curr = curr->next;
      }
      else{
         elems.insert(curr->data);
         prev = curr;
         curr = curr->next;
      }
   }

   printlist(head);
   return head;
}

int main(){

   node* head = new node(1);
   head->next = new node(2);
   head->next->next = new node(1);
   head->next->next->next = new node(1);
   head->next->next->next->next = new node(3);

   head = removeDuplicate(head);

   return 0;
}
