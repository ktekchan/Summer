#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

static void validstring(char *str, int len){

 
   int i;
   int count = 0;
   int occur = 0;
   int arr[26]={0};

   for(i=0; i<len; i++){
      arr[str[i]-'a']++;
   }

   for (i=0; i<26; i++){
      if (arr[i]>0 && occur == 0){
           occur = arr[i];
      }

      else if(arr[i]>0 && occur != 0){
         count = count + abs(arr[i]-occur);
         if (count > 1){
            cout << "NO" << endl;
            return;
         }
      }
   }

   cout << "YES" << endl;
   return;
}
int main() {

   string str;
   cin >> str;
   int len = str.length();

   char *in;
   in = (char *)malloc(sizeof(char)*len);

   in[len]=0;
   memcpy(in,str.c_str(),len);
   validstring(in, len);
   return 0;
}

