/*
 * Author: Khushboo Tekchandani
 * Cipher
 * Encryption - given a message, xor the message with it's right shifted value
 * Do this k-1 time, given k.
 * The problem requires to find the original message from the encoded message
 */

#include <iostream>
#include <string>

using namespace std;

void decode(string str, int n, int k){

   bool *encoded = new bool[n+k-1];
   bool *decoded = new bool[n];

   int i;

   for(i=0; i<(n+k-1); i++){
      encoded[i] = (str[i]=='1');
   }

   decoded[0] = encoded[0];
   bool x = encoded[0];

   int j = 1;
   bool temp;
   for(i=0; i<k-1; i++){
      temp = x^encoded[i+1];
      decoded[j++] = temp;
      x = x^temp;
   }

   for(i=0; i<n-k; i++){
      x = x^decoded[i];
      temp = x^encoded[i+k];
      decoded[j++] = temp;
      x = x^temp;
   }

   for(i=0; i<n; i++){
      cout << decoded[i];
   }
   cout << endl;
   return;

}

int main(){

   int n,k;
   string str;

   cin >> n;
   cin >> k;
   cin >> str;

   decode(str, n, k);

   return 0;
}
