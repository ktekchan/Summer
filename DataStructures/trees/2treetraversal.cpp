/*
 * Author: Khushboo Tekchandani
 * Convert a sorted array into a BST
 * Iterative tree traversals on this BST
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct node{
   int val;
   node *left;
   node *right;
}treenode;

treenode *convert (int *arr, int start, int end){
   treenode *root = (treenode*)malloc(sizeof(treenode));

   if(start>end)
      return NULL;
   else{
      int mid = (start+end)/2;
      root->val = arr[mid];
      root->left = convert(arr,start,mid-1);
      root->right = convert(arr,mid+1,end);
      return root;
   }
}

void inorder(treenode *root){
   
   stack<treenode*> s;
   treenode *temp=(treenode*)malloc(sizeof(treenode));
   if(root==NULL)
     return;

   while(!s.empty() || root!=NULL){
      
      if(root!=NULL){
         s.push(root); 
         root = root->left;
      }
      
      else{
         temp = s.top();
         cout << temp->val;
         s.pop();
         root = temp->right;
      }
   }

   cout << endl;
   return;

}

void preorder(treenode *root){
   
   stack<treenode*> s;
   if(root == NULL)
      return;

   s.push(root);
   while(!s.empty()){
      treenode *temp = s.top();
      cout << temp->val;
      s.pop();

      if(temp->right!=NULL)
         s.push(temp->right);
      if(temp->left!=NULL)
         s.push(temp->left);
   }

   cout << endl;
   return;
}

void postorder(treenode *root){

     stack<node*> s;
     node *temp = (node*)malloc(sizeof(node));
     node *last = (node*)malloc(sizeof(node));
     last = NULL;
                     
     if(root==NULL)
       return;
                         
     while(!s.empty() || root!=NULL){
         if(root!=NULL){
            s.push(root);
            root = root->left;
          }    
                                            
          else{
            temp = s.top();
            if(temp->right!=NULL && last!=temp->right){
               root = temp->right;
             }
             else{
               last = s.top();
               s.pop();
               cout << last->val << " ";
             }
         }
      } 

      cout << endl;
      return;
}

int main(){

   int i;
   int *sortedarr = (int*)malloc(sizeof(int)*7);
   for(i=1; i<=6; i++)
      sortedarr[i-1] = i;

   treenode *tree = (treenode*)malloc(sizeof(tree));
   tree = convert(sortedarr,0,6);
   inorder(tree);
   preorder(tree);
   postorder(tree);
}
