/*
 * Uncompress a string and the find the count of an alphabet
 * between two given indices
 */
#include <iostream>
#include <string>

using namespace std;

string uncompress(string str){

}

int main(){

   string str;
   string uncompressed;
   int i,q;
   int l,r;

   cin >> str;
   cin >> q;
   uncompressed = uncompress(str);
   for(i=0; i<q; i++){
      cin >> l >> r;
      count(uncompressed,l,r);
   }

   return 0;
}
