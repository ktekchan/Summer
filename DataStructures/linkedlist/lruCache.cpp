/*
 * Author: Khushboo Tekchandani
 * LRU Cache implementation.
 * Two main functions - get and set. Get value of key and Insert key and val 
 * if they do no already exist
 * Idea - Doubly linked list. Implement a hash of keys and nodes of the doubly
 * linked list.
 * This makes get and set O(1) function.
 */
#include <iostream>
#include <map>

using namespace std;

//Node class for the hashmap
class Node{
   friend class LRU;
   protected:
   int key;
   int val;
   Node *prev;
   Node *next;
   public:
   Node(int key, int val){
      this->key = key;
      this->val = val;
   }
};

//LRU Cache class
class LRU{
   private:
      int capacity;
      map<int, Node*> hash;
      Node *head = NULL;
      Node *tail = NULL;

   public:
      LRU(int capacity);
      int get(int key);
      void removeNode(Node *temp);
      void setHead(Node *temp);
      void set(int key, int val);
};

LRU::LRU(int capacity){
   this->capacity = capacity;
}

int LRU::get(int key){
   if(hash.find(key)!=hash.end()){
      Node *temp;
      temp = hash.at(key);
      removeNode(temp);
      setHead(temp);
      return temp->val;
   }

   return -1;
}

void LRU::removeNode(Node *temp){

   if(temp->prev==NULL){
      head = temp->next;
   }

   else{
      temp->prev->next = temp->next;
   }

   if(temp->next == NULL){
      tail = temp->prev;
   }

   else{
      temp->next->prev = temp->prev;
   }

}

void LRU::setHead(Node *temp){

   temp->next = head;
   temp->prev = NULL;

   if(head!=NULL){
      head->prev = temp;
   }

   head = temp;

   if(tail==NULL)
      tail = head;
}

void LRU::set(int key, int val){

   if(hash.find(key)!=hash.end()){
      Node *old = hash.at(key);
      old->val = val;
      removeNode(old);
      setHead(old);
   }

   else{
      Node *newNode = new Node(key,val);

      if(hash.size()>=this->capacity){
         hash.erase(key);
         removeNode(tail);
         setHead(newNode);
      }

      else{
         setHead(newNode);
      }

      hash.insert(pair<int,Node*>(key,newNode));
   }
}

int main(){

   LRU *lrucache = new LRU(10);
   return 0;
}
