/*
 * Author: Khushboo Tekchandani
 * Construct a complete Binary tree.
 * Count the number of nodes in the tree.
 */

#include <iostream>
#include <list>

using namespace std;

// Node struct
struct node{
   int val;
   node *left;
   node *right;
};

// Utility to create a new node
node *newNode(int v){
   node *temp = new node;
   temp->val = v;
   temp->left = NULL;
   temp->right = NULL;
}

// Calculate left height of the tree
int leftHeight(node *root){
   
   if(root==NULL)
      return 0;

   int height=0;
   while(root!=NULL){
      height++;
      root=root->left;
   }

   return height;
}

// Calculate right height of the tree
int rightHeight(node *root){
   
   if(root==NULL)
      return 0;

   int height = 0;
   while(root!=NULL){
      height++;
      root=root->right;
   }

   return height;
}

// Count the number of nodes
int countNodes(node *root){
   
   if(root==NULL)
      return 0;

   int left, right;
   left = leftHeight(root);
   right = rightHeight(root);

   if(left==right){
      return (2 << (left-1)) - 1;
   }

   else{
      return countNodes(root->left) + countNodes(root->right) + 1;
   }

}

int main(){
   
   node *tree1 = newNode(1);
   tree1->left = newNode(2);
   tree1->right = newNode(3);
   tree1->left->left = newNode(4);
   tree1->left->right = newNode(5);
   tree1->right->left = newNode(6);

   cout << countNodes(tree1) << endl;

   return 0;
}

