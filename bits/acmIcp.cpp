/*
 * Khushboo Tekchandani
 * Find the maximum number of teams that can know the maximum number of
 * topic. 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void acm(vector<string> in, int m){
   int i, j, k;
   int topicCountCurrent;
   int topicCountMax = 0;
   int teamCount = 0;

   for(i=0; i<in.size(); i++){
      for(j=i+1; j<in.size(); j++){
         topicCountCurrent = 0;
         for(k=0; k<m; k++){
            if(in[i][k]=='1'||in[j][k]=='1'){
               topicCountCurrent++;
            }
         }
         if(topicCountCurrent > topicCountMax){
            topicCountMax = topicCountCurrent;
            teamCount=1;
         }

         else if(topicCountCurrent == topicCountMax){
            teamCount++;
         }
      }
   }

   cout << topicCountMax << endl;
   cout << teamCount << endl;
}

int main(){

   int n,m;
   vector<string> in;

   cin >> n;
   cin >> m;

   int i;
   for(i=0; i<n; i++){
      
      string str = new char[m];
      cin >> str;
      in.push_back(str);
   }

   acm(in, m);
}
