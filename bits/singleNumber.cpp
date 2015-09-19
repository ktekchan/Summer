/*
 * Find the only single digit from a number that has all other 
 * digits appearing twice
 */

#include <iostream>
#include <vector>

using namespace std;

void single(int num){

   vector<int> v;
   vector<int>::iterator it;
   int i,rem;

   while(num){
      rem = num/10;
      v.push_back(num);
      num = num/10;
   }

   for(i=0;i<v.size(); i++){
      cout << v[i];
   }

   cout << endl;

   int x = 0;
   for(it=v.begin(); it!=v.end(); it++){
      x = x^v[*it];
   }

   cout << x << endl;
   return;
}

int main(){
   
   int num;
   cin >> num;

   single(num);

   return 0;
}
