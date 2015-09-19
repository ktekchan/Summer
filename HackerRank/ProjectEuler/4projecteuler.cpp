/*-----------------------------------------------------------------------------
 * Author Khushboo Tekchandani
 * Project Euler problem 4
 * Largest palindrome number problem
 -----------------------------------------------------------------------------*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

/* Calculates the number of digits in a number*/
int digits(long long n){
   
      int i = 0;
      while(n){
         n /= 10;
         i++;
      }

      return i;
}

/* Finds whether a number is a palindrome or not*/
int isPalindrome(long long n){

      stringstream ss;
      ss << n;
      string str;
      str = ss.str();
      int len = str.length();
      int ret=1;

      int i;
      for(i=0; i<len/2; i++){
         if(str[i] != str[len-1-i]){
            ret = 0;
            break;
         }
      }

      return ret;
}

/* Creates an initial repository of all 6 digit palindromes that are a product
 * of 3 digit numbers */

vector<long long> palindromes(){
   int i,j;
   long long prod;
   stringstream ss;
   vector<long long> palins;

   int len;

   for(i=100; i<=999; i++){
      for(j=i+1; j<999; j++){
            prod = i*j;
            len = digits(prod);
            if (isPalindrome(prod) && prod>=101101 && len==6){
               palins.push_back(prod);
            }
      }
   }

   sort(palins.begin(), palins.end());
   return palins;
}

/* Finds the largest palindrome smaller than the input */
long long largestPalindrome(long long n, vector<long long> palindromes){

   int i;
   long long ret;
   for (i=0; i<palindromes.size(); i++){
      if(palindromes[i]==n){
         ret = n;
         break;
      }
      else if(palindromes[i]>n){
         ret = palindromes[i-1];
         break;
      }
   }

   return ret;
}

/* Main function */
int main(){

   int t, i;
   long long n;
   vector<long long> out;
   vector<long long> palins;
   cin >> t;

   palins = palindromes();

   for (int i=0; i<t; i++){
      cin >> n;
      out.push_back(largestPalindrome(n, palins));
   }

   for (i=0; i<t; i++){
      cout << out[i] << endl;
   }

   return 0;
}
