/*
 * Author: Khushboo Tekchandani
 * Find the path with minimum cost
 */

#include <iostream>

using namespace std;

struct node{
   int cost;
   node *left;
   node *right;

   node(int d){
      cost = d;
      left = NULL;
      right = NULL;
   }
};

int minCost(node *root){
      if (root == NULL)
         return 0;
      if(root->left==NULL && root->right==NULL)
         return root->cost;
      
      int curr = root->cost;
      int minSum;
      if(root->left==NULL){
         minSum = curr+minCost(root->right);
      }

      else if(root->right==NULL){
         minSum = curr+minCost(root->left);
      }

      else
         minSum = curr+min(minCost(root->left),minCost(root->right));
      return minSum;
}

int main(){

   node *root = new node(1);
   root->left = new node(4);
   root->right = new node(1);
   root->right->left = new node(1);
   root->right->right = new node(1);
   root->right->right->right = new node(1);

   cout << minCost(root) << endl;
   return 0;
}
