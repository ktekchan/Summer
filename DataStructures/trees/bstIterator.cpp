/*
 * Khushboo Tekchandani
 * Implement an iterator over a binary search tree (BST). Your iterator will be
 * initialized with the root node of a BST. Calling next() will return the next
 * smallest number in the BST.
 *
 * Idea: The smallest numbers will be on the left of the tree. Psuh them on
 * stack. Once you pop one from stack, push all it's right children.
 */

#include <iostream>
#include <stack>

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

class BSTIterator{

   private:
      stack<node*> s;
   public:
      BSTIterator(node *root){
         while(root!=NULL){
            s.push(root);
            root = root->left;
         }
      }
      bool hasNext();
      int next();
};

bool BSTIterator::hasNext(){
   return !this->s.empty();
}

int BSTIterator::next(){
   
   node *temp = s.top();
   s.pop();
   int ret = temp->data;
   if(temp->right!=NULL){
      temp = temp->right;
      while(temp!=NULL){
         s.push(temp);
         temp =temp->left;
      }
   }

   return ret;
}

int main(){
   
   node *root = new node(8);
   root->left = new node(3);
   root->right = new node(10);
   root->left->left = new node(1);
   root->left->right = new node(6);
   root->left->right->left = new node(4);
   root->left->right->right = new node(7);
   root->right->right = new node(14);
   root->right->right->left = new node(13);

   BSTIterator *it = new BSTIterator(root);
   cout << it->hasNext() << endl;

   int i;
   for(i=0; i<9; i++){
      cout << it->next() << endl;
   }

   return 0;
}
