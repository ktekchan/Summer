#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void sum(vector<long long> a){
   int i;
   long long sum = 0;
   for(i=0; i<a.size(); i++){
      sum +=a[i];
   }

   cout << sum << endl;
   return;
}

int main() {

   int n,i;
   vector<long long> a;
   long long in;

   cin >> n;
   for(i=0; i<n; i++){
      cin >> in;
      a.push_back(in);
   }

   sum(a);

   return 0;
}
