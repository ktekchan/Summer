/*
 * Sansa and the xor
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void sansa(vector<unsigned long long> v){

   unsigned long long result = 0;
   int i;
   cout << v.size() << endl;
   if(v.size()%2==0){
      cout << "0\n";
      return;
   }

   else{
      for(i=0; i<v.size(); i++){

         if(i%2!=0){
            result = result^v[i];
         }
      }
      cout << result << endl;
      return;
   }
}


int main() {
   /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

   int i,j,t,n;
   unsigned long long num;
   vector<unsigned long long> v;
   cin >> t;

   for(i=0; i<t; i++){

      cin >> n;
      v.clear();

      for(j=0; j<n; j++){
         cin >> num;
         v.push_back(num);   
      }

      sansa(v);
   }
   return 0;
}

