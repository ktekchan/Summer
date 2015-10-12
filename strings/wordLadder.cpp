/*
 * Khushboo Tekchandani
 * Given two words (start and end), and a dictionary, find the length of
 * shortest transformation sequence from start to end, such that only one letter
 * can be changed at a time and each intermediate word must exist in the
 * dictionary.
 *
 * Idea: To use a BFS changing one letter at a time.
 * BFS because we want the shortest
 *
 */

#include <iostream>
#include <set>
#include <string>
#include <queue>

using namespace std;

struct wordNode{
   string word;
   int steps;

   wordNode(string w, int num) : word(w), steps(num){}
};

int findSteps(string start, string end, set<string> dict){

   queue<wordNode*> lq;
   wordNode *begin = new wordNode(start,1);

   // For BFS
   lq.push(begin);

   dict.insert(end);

   while(!lq.empty()){

      wordNode *top = lq.front();
      lq.pop();
      string word = top->word;

      if(word.compare(end)==0)
         return top->steps;

      char *wordArr = (char*)word.c_str();
      int i;
      char ch;

      for(i=0; i<word.length(); i++){
      
         char temp = wordArr[i];

         // Change every letter of each word to check if that changed word
         // exists in the dictionary or not
         for(ch='a';ch<='z';ch++){
            if(wordArr[i]!=ch){
               wordArr[i] = ch;
            }

            string newWord(wordArr);
            if(dict.find(newWord)!=dict.end()){
               wordNode *add = new wordNode(newWord, top->steps+1);
               lq.push(add);
               dict.erase(dict.find(newWord));
            }

            wordArr[i] = temp;
         }
      }
   }

   return 0;
}

int main(){

   string start = "hit";
   string end = "cog";
   set<string> dict;
   dict.insert("hot");
   dict.insert("dot");
   dict.insert("dog");
   dict.insert("lot");
   dict.insert("log");
   dict.insert("cot");
   dict.insert("bot");
   dict.insert("bog");

   cout << findSteps(start, end, dict) << endl;

   return 0;

}
