/*
 * Khushboo Tekchandani
 * Find the inorder successor of a give node in a tree
 * Idea : If it has a right child, then minimum in the right tree is the inorder
 * successor. Else, its parent is the inorder successor. Keep saving the parent
 * while traversing the tree and return at the correct point
 */

#include <iostream>

using namespace std;

struct node{
   int data;
   node *left;
   node *right;

   node(int d){
      data = d;
      left = NULL;
      right = NULL;
   }
};

node *minNode(node *root){
   while(root->left!=NULL)
      root = root->left;
   return root;
}

node *inorderSuccessor(node *root, node *testNode){

   if(testNode->right){
      return minNode(testNode->right);
   }

   node *successor = NULL;

   // Search starting from the root
   while(root!=NULL){
   
      if(testNode->data < root->data){
         successor = root;
         root = root->left;
      }

      else if(testNode->data > root->data
            root = root->right;
      else
         break;
   }

   return successor;
}
int main();
