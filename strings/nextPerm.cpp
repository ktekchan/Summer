/*
 * Author: Khushboo Tekchandani
 * Bigger is greater
 * To find the next lexicographically bigger string
 */

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

void nextPerm(string str){

   int len = str.size();

   if(len==0 || len==1){
      cout << "no answer\n";
      return;
   }

   vector<int> arr;
   int i,val;

   //Fill array with alphabet index of the string
   for(i=0; i<len; i++){
      val = (int)str[i] -'a';
      arr.push_back(val);
   }

   //Non-increasing suffix
   i = len-1;

   while(i>0 && arr[i-1]>=arr[i])
      i--;

   //It is the lexicographically greatest permutation already 
   if(i==0){
      cout << "no answer\n";
      return;
   }

   //Successor to pivot
   int j = len-1;

   while(arr[j]<=arr[i-1])
      j--;

   //Swap i and j
   int temp = arr[i-1];
   arr[i-1] = arr[j];
   arr[j] = temp;

   //Sort the suffix
   j = len-1;
   sort(arr.begin()+i, arr.end());

   //Create the output string
   char *perm = new (nothrow) char[len+1];
   assert(perm!=NULL);

   for(i=0; i<len; i++){
      perm[i] = (char)(arr[i]+'a');
   }

   perm[len] = '\0';
   cout << perm << endl;

   return;

}

int main(){

   int i, t;

   cin >> t;

   string str;

   for(i=0; i<t; i++){
      cin >> str;
      nextPerm(str);
   }

   return 0;
}
