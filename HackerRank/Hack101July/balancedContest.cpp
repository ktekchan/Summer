/*
 * Author: Khushboo Tekchandani
 * Beauty and difficulty, both in increasing order
 */
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int balanced(map<int,int> hash, vector<int>sortedDiff){
   
   map<int,int>::iterator it;
   it = hash.begin();
   int i,key;
   for(i=0; i<hash.size(); i++){
      key = it->first;
      if(hash.at(key)!=sortedDiff[i]){
         return 0;
      }

      if(i>0 && sortedDiff[i-1]==sortedDiff[i]){
         return 0;
      }
      it++;
   }

   return 1;
}

int main(){

   int beauty, diff;
   vector<int> sortedDiff;
   int i;

   map<int,int> hash;

   for(i=0; i<5; i++){
      cin >> beauty;
      cin >> diff;

      //Check if beauty is strictly increasing or not
      //Beauty values must not repeat
      if(hash.find(beauty)!=hash.end()){
         cout << 0 << endl;
         return 0;
      }

      hash.insert(pair<int,int>(beauty,diff));
      sortedDiff.push_back(diff);
   }

   sort(sortedDiff.begin(), sortedDiff.end());
   cout << balanced(hash,sortedDiff) << endl;
   return 0;
}
