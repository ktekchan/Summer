/*
 * Khushboo Tekchandani
 * Simple implementation of trie or prefix tree
 */

#include <iostream>
#include <vector>

using namespace std;

class trieNode{

   private:
      char ch; // Node itself
      bool isLeaf; // Marker for leaf
      vector<trieNode*> children; // vector of children
   public:
      trieNode(char c) : ch(c), isLeaf(false){}
      char getC() {return ch;}
      bool getEnd() {return isLeaf;}
      vector<trieNode*> getChildren() {return children;}
      void setEnd() {isLeaf = true;}
      void addChild(trieNode* child) {children.push_back(child);}
      trieNode* findChild(char ch);

};

// find if a char is a child node of a give node
trieNode* trieNode::findChild(char c){

   int i;
   for(i=0; i<children.size(); i++){
      if(children[i]->ch == c){
         trieNode* temp = children[i];
         return temp;
      }
   }
   return NULL;
}

class Trie{

   private:
      trieNode* root;
   public:
      Trie();
      ~Trie();
      void addWord(string s);
      bool searchWord(string s);
      bool deleteWord(string s);
};

Trie::Trie(){

   root = new trieNode(' ');
}

Trie::~Trie(){
   delete root;
}

// Add a word to the trie structure
void Trie::addWord(string s){

   trieNode* current = root;
   if(s.length()==0){
      current->setEnd(); // Empty string marking the leaf
      return;
   }

   int i;
   for(i=0; i<s.length(); i++){

      // if the characer child exist, make it the current and move to next
      // character
      trieNode* child = current->findChild(s[i]);
      if(child!=NULL){
         current = child;
      }
      else{

         // Add new node and append it to the existing current's children
         trieNode *temp = new trieNode(s[i]);
         current->addChild(temp);
         current = temp;
      }

      // Mark leaf
      if(i==s.length()-1){
         current->setEnd();
      }
   }

}

// Search a word from the trie structure
bool Trie::searchWord(string s){

   trieNode* current = this->root;

   while(current!=NULL){

      // Search for each char
      for(int i=0; i<s.length(); i++){
         trieNode* temp = current->findChild(s[i]);
         if(temp==NULL)
            return false;
         else
            current = temp;
      }

      // All found if last is a leaf then word exists
      if(current->getEnd()){
         return true;
       }
      else
         return false;
   }

   return false;
}

int main(){

   Trie* trie = new Trie();
   trie->addWord("Hello");
   if (trie->searchWord("Hello") )
      cout << "Found Hello" << endl;
   
   return 0;
}
