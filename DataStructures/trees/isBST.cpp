/*
 * Author: Khushboo Tekchandani
 * Find if a tree is BST or not without recursion
 * Idea: In order traversal without recursion and see if it is sorted.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

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

bool isBST(node *root){

   if(root==NULL)
      return true;
   stack<node*> s;
   vector<int> inorder;

   while(!s.empty() || root!=NULL){
      if(root!=NULL){
         s.push(root);
         root = root->left;
      }
      else{
         node *temp = s.top();
         inorder.push_back(temp->data);
         s.pop();
         root = temp->right;
      }
   }

   cout << endl;

   if(is_sorted(inorder.begin(), inorder.end()))
      return true;

   return false;
}

int main(){

   node *root = new node(4);
   root->left = new node(1);
   root->right = new node(5);
   root->left->left = new node(2);
   root->left->right = new node(3);
   root->right->left = new node(6);
   root->right->left = new node(7);

   if(isBST(root))
      cout << "Yes\n";
   else
      cout <<  "No\n";

   return 0;
}
