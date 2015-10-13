/*
 * Khushboo Tekchandani
 * Spirally traverse a tree.
 * Idea: Use two different stacks. One for traversing left to right and the
 * other for traversing right to left
 */

#include <iostream>
#include <stack>

using namespace std;

struct node{

   int data;
   node *left;
   node *right;

   node(int d){
      data = d;
      left= NULL;
      right = NULL;
   }
};

void spiral(node *root){

   stack<node*> st1;
   stack<node*> st2;

   if(root==NULL)
      return;
   st1.push(root);

   while(!st1.empty() || !st2.empty()){

      while(!st1.empty()){
         node *temp = st1.top();
         cout << temp->data << " ";
         st1.pop();
         if(temp->right)
            st2.push(temp->right);
         if(temp->left)
            st2.push(temp->left);
      }

      while(!st2.empty()){
         node *temp = st2.top();
         cout << temp->data << " ";
         st2.pop();
         if(temp->left)
            st1.push(temp->left);
         if(temp->right)
            st1.push(temp->right);
      }

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

   spiral(root);
   cout << endl;
   return 0;
}
