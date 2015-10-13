/*
 * Khushboo Tekchandani
 * Given the root of a binary search tree and 2 numbers min and max, trim the
 * tree such that all the numbers in the new tree are between min and max
 * (inclusive).
 * Idea: Use recursion. And do a bottom up post order traversal of sorts
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

node *trim(node *root, int min, int max){

   if(root==NULL)
      return root;

   root->left = trim(root->left, min, max);
   root->right = trim(root->right, min, max);

   if(root->data>=min && root->data<=max)
      return root;
   else if(root->data<min)
      return root->right;
   else
      return root->left;
}

void printIn(node *root){

   if(root==NULL)
      return;
   printIn(root->left);
   cout << root->data << " ";
   printIn(root->right);

   return;
}

int main() {

   node *root = new node(8);
   root->left = new node(3);
   root->left->left = new node(1);
   root->left->right = new node(6);
   root->left->right->left = new node(4);
   root->left->right->right = new node(7);
   root->right = new node(10);
   root->right->right = new node(14);
   root->right->right->left = new node(13);

   printIn(root);
   cout << endl;
   root = trim(root,5,13);
   printIn(root);
   cout << endl;

   return 0;
}
