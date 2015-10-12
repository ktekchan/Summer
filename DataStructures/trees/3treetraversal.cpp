/*
 * Khushboo Tekchandani
 * Level order and morris inorder traversal
 */

#include <iostream>
#include <queue>

using namespace std;

struct node{
   int data;
   node *left;
   node *right;

   node(int a){
      data = a;
      left = NULL;
      right = NULL;
   }
};

void levelOrder(node *root){

   queue<node*> q;
   q.push(root);

   while(!q.empty()){
      node *temp = q.front();
      q.pop();
      cout << temp->data << " ";
      if(temp->left)
         q.push(temp->left);
      if(temp->right)
         q.push(temp->right);
   }
}

void morrisInorder(node *root){

   /*1. Initialize current as root 
     2. While current is not NULL
      If current does not have left child
         a) Print current’s data
         b) Go to the right, i.e., current = current->right
      Else
         a) Make current as right child of the rightmost node in current's left subtree
         b) Go to this left child, i.e., current = current->left
    */

   node *curr, *prev;
   if(root==NULL)
      return;

   curr = root;
   while(curr!=NULL){
      if(curr->left==NULL){
         cout << curr->data << " ";
         curr=curr->right;
      }
      else{
         prev = curr->left;
         while(prev->right!=NULL && prev->right!=curr)
            prev = prev->right;

         if(prev->right==NULL){
            prev->right = curr;
            curr = curr->left;
         }

         else{
            prev->right = NULL;
            cout << curr->data << " ";
            curr = curr->right;
         }
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

   levelOrder(root);
   cout << endl;
   morrisInorder(root);

   cout << endl;

   return 0;
}
