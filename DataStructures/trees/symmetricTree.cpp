/*
 * Khushboo Tekchandani
 * Find if the tree is symmetric or not
 * Idea : Find if the two subtrees are mirror images of each other
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

// Find if two subtrees are mirror images of each other or not
bool isMirror(node *root1, node *root2){

   if(root1==NULL && root2==NULL)
      return true;

   if(root1 && root2 && root1->data==root2->data){
      return isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
   }

   return false;
}

// Check if the tree is symmetric to itself or not
bool isSymmetric(node *root){

   return isMirror(root,root);
}

int main(){

   node *root = new node(1);
   root->left = new node(2);
   root->right = new node(2);
   root->left->right = new node (3);
  // root->left->right = new node (4);
  // root->right->left = new node(4);
   root->right->right = new node(3);

   cout << isSymmetric(root) << endl;

   return 0;
}
