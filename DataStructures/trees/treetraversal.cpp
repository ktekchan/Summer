/*
 * Author: Khushboo Tekchandani
 * Convert a sorted array into a BST
 * Implementation of various tree traversal on the so formed BST using 
 * recursion
 * This file also contains a few other problem solutions like
 * 1. Reverse a binary tree (iterative and recursive)
 *    This is like forming a mirror image of a binary tree
 * 2. Lowest common ancestor (BST)
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>

using namespace std;

typedef struct treenode{
   int val;
   treenode *left;
   treenode *right;
}treenode;

treenode *convertoBST(int *arr, int start, int end){

   treenode *root = (treenode*)malloc(sizeof(treenode));

   if (start>end)
      return NULL;
   else{
      int mid = ((end+start)/2);
      root->val = arr[mid];
      root->left = convertoBST(arr,start,mid-1);
      root->right = convertoBST(arr,mid+1,end);
      return root;
   }

}

void inorder(treenode *root){

   if(root == NULL)
      return;
   else{
      inorder(root->left);
      cout << root->val;
      inorder(root->right);
   }

   return;
}

void preorder(treenode *root){
   if(root == NULL)
      return;
   else{
      cout << root->val;
      preorder(root->left);
      preorder(root->right);
   }

   return;
}

void postorder(treenode *root){
   if(root==NULL)
      return;
   else{
      postorder(root->left);
      postorder(root->right);
      cout << root->val;
   }
   return;
}

void findlca(treenode *root, int n1, int n2){
   
   if(root == NULL)
      return;

   if(n1<root->val && n2>root->val){
      cout << root->val;
      return;
   }
   
   else if(n1<root->val && n2<root->val)
         findlca(root->left,n1,n2);

   else
      findlca(root->right,n1,n2);
}

void reverse(treenode *root){
   if(root == NULL)
      return;
   treenode *temp = (treenode*)malloc(sizeof(treenode));
   temp = root->right;
   root->right = root->left;
   root->left = temp;

   reverse(root->left);
   reverse(root->right);
}

void iterativeReverse(treenode *root){

   if(root==NULL)
      return;

   list<treenode*> queue;
   queue.push_back(root);

   while(!queue.empty()){

      treenode *popped = queue.front();
      queue.pop_front();
      treenode *temp = (treenode*)malloc(sizeof(treenode));
      temp = popped->right;
      popped->right = popped->left;
      popped->left = temp;

      if (popped->left)
         queue.push_back(popped->left);
      if(popped->right)
         queue.push_back(popped->right);
   }
}

int ksmallest(treenode *root, int k){
   
   if(root==NULL)
      return -1;

   list<treenode*> stack;
   int count = 0;

   while(!stack.empty() || root!=NULL){
      
      if(root!=NULL){
         stack.push_back(root);
         root = root->left;
      }

      else{
         treenode *temp = stack.back();
         count++;
         if (count == k){
            return temp->val; 
         }
         stack.pop_back();
         root = temp->right;
      }
      
   
   }

}

int main(){

   int i;
   int *sortedarray = (int*)malloc(sizeof(int)*7);

   for (i=1; i<=7; i++)
      sortedarray[i-1] = i;

   treenode *test = (treenode*)malloc(sizeof(treenode));
   test = convertoBST(sortedarray, 0, 6);
   cout << ksmallest(test, 3) << endl;

   return 0;
}
