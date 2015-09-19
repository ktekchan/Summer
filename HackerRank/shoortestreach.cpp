/*
 * Author: Khushboo Tekchandani
 * To find the distance to each node from a given node
 * Shortest distance.
 */

#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

class graph{
   private:
      int num_v;
      list<int> *adj;
   public:
      graph(int ver);
      void addEdge(int v1, int v2);
      void bft(int s);
};

graph::graph(int v){
   this->num_v = v;
   adj = new list<int>[v];
}

void graph::addEdge(int v1, int v2){
   adj[v1].push_back(v2);
   adj[v2].push_back(v1);
}

void graph::bft(int s){

   int src = s;

   bool *visited = new bool[num_v];
   int *dist = new int[num_v];
   int i;
   for(i=0; i<num_v; i++){
      visited[i] = false;
      dist[i] = -1;
   }
   dist[src] = 0;
   list<int> queue;
   list<int>::iterator it;

   int count = 0;
   visited[s] = true;
   queue.push_back(s);

   while(!queue.empty()){
      s = queue.front();
      queue.pop_front();
      for(it=adj[s].begin(); it!=adj[s].end(); it++){
         count = dist[s];
         if(!visited[*it]){
            visited[*it] = true;
            queue.push_back(*it);
            dist[*it] = dist[s]+1;
         }

      }
   }

   for(i=0; i<num_v; i++){
      if (src==i)
         continue;
      if(dist[i]<0)
         cout << "-1 ";
      else
         cout << 6*dist[i] << " ";
   }

   cout << endl;
}

void solution(int n, int m){
   graph g(n);
   int i;
   int v1, v2;
   int s;
   for(i=0; i<m; i++){
      cin >> v1;
      cin >> v2;
      g.addEdge(v1-1,v2-1);
   }

   cin >> s;
   g.bft(s-1);
}

int main(){
   int i,t,n,m,s;
   
   cin >> t;
   for(i=0; i<t; i++){
      cin >> n;
      cin >> m;
      solution(n,m);
   }
}
