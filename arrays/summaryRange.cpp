/*
 * Khushboo Tekchandani
 * Find the summary of ranges in a sorted array
 *
 * Go over the array and keep checking
 */

#include <iostream>
#include <vector>

using namespace std;

vector <string> ranges(vector<int> arr){
   
   int start = arr[0];
   int end = arr[0];

   vector<string> result;

   if(arr.size()==0)
      return result;

   int i;
   for(i=1; i<arr.size(); i++){  
      
      if(arr[i] == arr[i-1]+1){
         end = arr[i];
      }
      else{

         if(start==end){
            string add = to_string(start);
            result.push_back(add);
         }
         else{
            string add1 = to_string(start)+"->"+to_string(end);
            result.push_back(add1);
         }
         start = arr[i];
         end = arr[i];
      }

      if(i==arr.size()-1){
 
         string add2;
         if(start==end)
            add2 = to_string(start);
         else
            add2 = to_string(start)+"->"+to_string(end);
         result.push_back(add2);
      }


   }

   return result;
}

int main(){

   vector<int> arr;
   vector<string> result;
   arr.push_back(0);
   arr.push_back(1);
   arr.push_back(2);
   arr.push_back(4);
   arr.push_back(5);
   arr.push_back(7);

   result = ranges(arr);

   int i;
   for(i=0; i<result.size(); i++)
      cout << result[i] << endl;

   return 0;
}
