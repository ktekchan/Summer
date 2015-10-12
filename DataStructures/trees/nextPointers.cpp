/* 
 * Khushboo Tekchandani
 * Special tree with next pointer connecting nodes on the same level
 * Case 1 is complete binary tree
 * Need four pointers to keep track of lastHead, lastCurrent, CurrentHead and
 * Current. Need to maintain two levels to be able to move across subtrees.
 */

#include <iostream>

using namespace std;

struct node{
   int data;
   node *left;
   node *right;
   node* next;
   node(int d) : data(d){
      this->left = NULL;
      this->right = NULL;
      this->next = NULL;
   }
};

node* populateNextComplete(node *root){
   
   node *lastHead = root; //previous level head
   node *lastCurr = NULL; // previous level current
   node *currHead = NULL; // current level head
   node *curr = NULL; // current pointer

   while (lastHead != NULL){
      lastCurr = lastHead;
      while(lastCurr!=NULL){
      
         if(currHead == NULL){
            currHead = lastCurr->left;
            curr = currHead;
         }
         else{
            curr->next = lastCurr->left;
               curr = curr->next;
         }

         if(currHead!=NULL){
            curr->next = lastCurr->right;
            curr = curr->next;
         }
   
         lastCurr = lastCurr->next;
      }

      lastHead = currHead;
      currHead = NULL;

   }

   return root;

}

node *populateNextIncomplete(node *root){

   node *lastHead = root;
   node *lastCurr = NULL;
   node *currHead = NULL;
   node *curr = NULL;

   while(lastHead!=NULL){
      lastCurr = lastHead;
      
      while(lastCurr!=NULL){
   
         if(lastCurr->left!=NULL){

            if(currHead==NULL){
               currHead = lastCurr->left;
               curr = currHead;
            }
         else{
            curr->next = lastCurr->left;
            curr = curr->next;
         }

        }

         if(lastCurr->right!=NULL){
            if(currHead == NULL){
               currHead = lastCurr->right;
               curr = currHead;
            }

            else{
               curr->next = lastCurr->right;
               curr = curr->next;
            }
         }

         lastCurr = lastCurr->next;
      }

      lastHead = currHead;
      currHead = NULL;
    }

   return root;
}

void print(node *root){
   
   node *curr = root;
   node *currHead = root;
   node *nextLevel = root->left;

   while(currHead!=NULL){
      while(curr!=NULL){
         cout << curr->data << " ";
         curr = curr->next;
      }

      cout << endl;
      if(nextLevel!=NULL){
         currHead = nextLevel;
         curr = currHead;
      }
      else
         currHead = NULL;

      if(currHead->left!=NULL)
         nextLevel = currHead->left;
      else
         nextLevel = NULL;
   }

}


int main(){
   node *root = new node(1);
   root->left = new node(2);
   root->right = new node(3);
   root->left->left = new node(4);
   root->left->right = new node(5);
   root->right->left = new node(6);
   root->right->right = new node(7);
   root->left->left->left = new node(8);
   root->left->left->right = new node(9);
   root->right->left->left = new node(10);
   root->right->left->right = new node(11);

   root = populateNextIncomplete(root);
   print(root);
   return 0;
}
