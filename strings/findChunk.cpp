/*
 * Khushboo Tekchandani
 * Number of chunks to make a palindrome
 */

#include <iostream>
#include <string>

using namespace std;

bool checkChunk(const char *str
int chunks(const char *str, int start, int end, int &count){

   if(start == end)
      return count;

   int size = 2;
   if(str[start]==start[end]){
      count += 2;
      return chunks(str, start+1, end-1, count);
   }

   else{
      if(checkChunk(str, start, end, size)){
         count += 2;
         return chunks(str, start+1, end-1, count);
      }

      else
         checkChunk(str, start, end, size+1);
   }


}

int main(){

   string str = "teammate";
   int count = 1;
   cout << chunks(str.c_str(), 0, str.length()-1, count);
   return 0;
}
