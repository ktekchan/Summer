/*
 * Khushboo Tekchandani
 * Find a path in a tree where node values sum up to a given number
 */

#include <iostream>
#include <vector>

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

void findPath(node *root, vector<int> &path, int sum){

   if(root==NULL && sum==0){
      int i;
      for(i=0; i<path.size(); i++){
         cout << path[i] << " ";
      }
      cout << endl;
      return;
   }

   if(root==NULL && sum!=0)
      return;

   path.push_back(root->data);

   findPath(root->left,path,sum-root->data);
   findPath(root->right,path,sum-root->data);
   path.pop_back();
}

int main(){

   node *tree = new node(5);
   tree->left = new node(2);
   tree->right = new node(3);
   tree->left->left = new node(1);
   tree->left->right = new node(6);

   int sum = 8;
   vector<int> path;
   findPath(tree,path,8);

   return 0;
}
