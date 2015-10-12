/*
 * Khushboo Tekchandani
 * Convert roman numerals into decimal representation
 * For this example, convert up to 50
 * Idea: start from right
 *       if the character on the left is less than the current, then 
 *       subtract else add
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

void convert(string roman){
   
   int i;
   int num = 0;
   
   map<char,int> romanMap;
   romanMap['i'] = 1;
   romanMap['v'] = 5;
   romanMap['x'] = 10;
   romanMap['l'] = 50;

   num = num+romanMap[roman[roman.length()-1]];

   for(i=roman.length()-2; i>=0; i--){
      if(romanMap[roman[i]]<romanMap[roman[i+1]])
         num = num-romanMap[roman[i]];
      else
         num = num+romanMap[roman[i]];
   }

   cout << num << endl;

}

int main(){

   string roman = "i";
   convert(roman);

   return 0;
}
