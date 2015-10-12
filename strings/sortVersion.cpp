/*
 * Khushboo Tekchandani
 * Given an array of versions, sort them
 * Idea: Custom comparator to compare versions
 *       versions split into arrays of numbers
 *       compare the two arrays
 * c++11
 */

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

array<int,4> tokenize(string version){

   array<int,4> tokenArray;
   sscanf (version.c_str(), "%d.%d.%d.%d", &tokenArray[0], &tokenArray[1], 
         &tokenArray[2], &tokenArray[3]);
   return tokenArray;
}

void sortVersions(vector<string> versions){
   
   sort(versions.begin(), versions.end(), [](string v1, string v2){
      return (tokenize(v1) < tokenize(v2));
   });

   int i;

   for(i=0; i<versions.size(); i++){
      cout << versions[i] << " ";
   }

   cout << endl;
}

int main(){
   
   string s[]   = {"1.2.1.3","12.1.2.4"};
   vector<string> versions(begin(s),end(s));

   sortVersions(versions);

   return 0;
}
