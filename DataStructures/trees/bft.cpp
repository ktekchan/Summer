/*
 * Author: Khushboo Tekchandani
 * A simple implementation for breadth first traversal of a graph.
 * Includes helper functions.
 * Uses the 'list' STL for storing the graph as an adjacency list.
 */

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

class graph{
   private:
      int num_v;
      list<int> *adj;
   public:
      graph(int ver);
      void addEdge(int v1, int v2);
      void bft(int s);
      void dft(int s);
      void level(int s);
};

graph::graph(int v){
   this->num_v = v;
   adj = new list<int>[v];
}

void graph::addEdge(int v1, int v2){
   adj[v1].push_back(v2);
}

void graph::bft(int s){
   bool *visited = new bool[num_v];

   int i;
   for(i=0; i<num_v; i++){
      visited[i]=false;
   }

   list<int> queue;
   list<int>::iterator it;

   visited[s] = true;
   queue.push_back(s);

   while(!queue.empty()){  
      s = queue.front();
      cout << s << " ";
      queue.pop_front();

      for(it=adj[s].begin(); it!=adj[s].end(); it++){
            if(!visited[*it]){
               visited[*it] = true;
               queue.push_back(*it);
            }
      }
   } 
}

void graph::level(int s){
   bool *visited = new bool[num_v];

   int i;
   for(i=0; i<num_v; i++){
      visited[i] = 0;
   }

   list<int> queue;
   list<int>::iterator it;

   visited[s] = true;
   queue.push_back(s);
   int size;

   while(!queue.empty()){
      size = queue.size();
      cout << endl;
      for(i=0; i<size; i++){

         s = queue.front();
         cout << s << " ";
         queue.pop_front();

         for(it=adj[s].begin(); it!=adj[s].end(); it++){
            if(!visited[*it]){
               visited[*it] = true;
               queue.push_back(*it);
            }
         }
      }
  }
}

void graph::dft(int s){
   bool *visited = new bool[num_v];
   int i;
   for(i=0; i<num_v; i++){
      visited[i] = false;
   }
   list<int> stack;
   list<int>::iterator it;

   visited[s] = true;
   stack.push_back(s);
   
   while(!stack.empty()){
      s = stack.back();
      cout << s << " ";
      stack.pop_back();
      for(it=adj[s].begin(); it!=adj[s].end(); it++){
         if(!visited[*it]){
            visited[*it] = true;
            stack.push_back(*it);
         }
      }
   }

  
  
}

int main(){
   
   graph g(4);
   g.addEdge(0,1);
   g.addEdge(1,0);
   g.addEdge(0,2);
   g.addEdge(2,0);
   g.addEdge(2,3);

   g.bft(2);
   cout << endl;
   g.dft(2);
   cout << endl;
   g.level(0);
   cout << endl;

   return 0;
}
