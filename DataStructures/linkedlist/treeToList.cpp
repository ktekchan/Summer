/*
 * Author: Khushboo Tekchandani
 * Convert and ordered(bin search) tree to a circular doubly linked list.
 * Idea: Split the tree into left, right and root
 * Recursively convertthe subtrees into doubly linked lists
 */

#include <iostream>

using namespace std;

struct Node{
   int data;
   Node *small;
   Node *large;

   Node(int d){
      data = d;
      small = NULL;
      large = NULL;
   }
};

/*
 * Utility function to join two given list nodes
 */
void join(Node* node1, Node* node2){

   node1->large = node2;
   node2->small = node1;
}

/*
 * Utility function two join two circular doubly linked lists
 */
Node* append(Node* node1, Node* node2){

   if(node1 == NULL)
      return node2;
   if(node2 == NULL)
      return node1;

   Node *node1End = node1->small;
   Node *node2End = node2->large;

   join(node1End, node2);
   join(node2End, node1);

   return node1;
}

/*
 * Recursive function to flatten the tree
 */
Node* treeToList(Node *root){

   if(root == NULL)
      return;

   Node *node1List = treeToList(root->left);
   Node *node2List = treeToList(root->right);

   node1List = append(node1List, root);
   node1List = append(root, node2List);

   return node1List;

}

