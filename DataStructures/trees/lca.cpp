/*
 * Author: Khushboo Tekchandani
 * 1. Lowest common ancestor in a binary tree.
 * 2. Longest path in a tree/ Diameter of a tree.
 */

#include <iostream>
#include <vector>

using namespace std;

/* Tree node structure */
struct node{
   int val;
   node* left;
   node* right;
};

/* Create new tree with the given values */
node *newNode(int v){
   node *temp = new node;
   temp->val = v;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

/* To find a path from the root to the given node*/
bool findPath(node *root, vector<int> &path, int key){
   
   if (root == NULL)
      return false;

   path.push_back(root->val);

   if (root->val == key)
      return true;

   if((root->left && findPath(root->left, path, key)) 
      || (root->right && findPath(root->right, path, key))) {
      return true;
   }

   path.pop_back();
   return false;
}

// Lowest common ancestor
int findlca(node *root, int v1, int v2){

   vector<int> path1, path2;

   if(!findPath(root,path1,v1) || !findPath(root,path2,v2))
      return -1;

   int i;

   for(i=0; i<path1.size()&&i<path2.size(); i++){
      if(path1[i] != path2[i])
         break;
   }

   return path1[i-1];
}

// Diameter of a tree
// It is the maximum of either left height + right height (which is through the
// root) and a path from a leaf node to another not through the root.

int max(int a, int b){
   return (a>b) ? a : b;
}

// Length of the longest path from root OR height
int height(node *root){
   
   if(root==NULL)
      return 0;
   else
      return 1+max(height(root->left),height(root->right));
}

// Lenght of the shortest path from the root
int shortest(node *root){
   if(root==NULL)
      return 0;
   else
      return 1+min(height(root->left),height(root->right));
}

int diameter(node *root){
   
   if(root==NULL)
      return 0;
   
   int lheight = height(root->left);
   int rheight = height(root->right);

   int ldia = diameter(root->left);
   int rdia = diameter(root->right);

   return max(lheight+rheight+1, max(ldia,rdia));
}

// Difference between the longest and the shortest path from root
int differ(node *root){

   if(root==NULL)
      return 1000;
   int max = height(root);
   int min = shortest(root);
   int diff = max - min;
   return diff;
}

int main(){
   
   node *tree = newNode(1);
   tree->left = newNode(2);
  // tree->right = newNode(3);
   tree->left->left = newNode(4);
   tree->left->left->left = newNode(5);
//   tree->left->right->right = newNode(6);
  // tree->left->right->right->right = newNode(7);

   //cout << "Lowest Common Ancestor(4,5) " << findlca(tree,4,5) << endl;
  // cout << "Lowest Common Ancestor(6,4) " <<findlca(tree,6,4) << endl;

   //cout << "Diameter: " << diameter(tree) << endl;
   cout << "Diff : " << differ(tree) << endl;
   cout << "Min : " << shortest(tree) << endl;

   return 0;
}
