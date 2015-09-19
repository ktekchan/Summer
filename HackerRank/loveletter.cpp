#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
          
   int test, i, j, len;
   string str;

   cin >> test;
   int count[test];

   for (i=0; i<test; i++){
      cin >> str;
      len = str.length();
      len;
      count[i] = 0;

      for (j=0; j<len/2; j++){
         
         if (str[j] == str[len-1-j]);
         else{
            
            if ((int)str[j] < (int)str[len-1-j]){
               count[i] += (int)str[len-1-j] - (int)str[j];
               str[len-1-j] = str[j];
            }

            else{
               count[i] += (int)str[j] - (int)str[len-1-j];
               str[j] = str[len-1-j];
            }
         }

      }
   }

   for (i=0; i<test; i++)
      cout << count[i] << endl;
   return 0;
}

