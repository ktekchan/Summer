/*
 * Author: Khushboo Tekchandani
 * Z algorithm for linear time patter searching
 * Construct Z array for pat$string and find the elements having the length
 * same as the pattern. Pattern exists from the the indices of such elements
 */

#include <iostream>
#include <string>

using namespace std;

void makeZArray(string str, int z[]){
   
   int len = str.length();
   int l,r,k; //for z window
   int i;
   
   // The z window which matches with the prefix
   l = 0;
   r = 0;

   for(i=1; i<len; ++i){
      
      //if i>r, then there is no matching
      //We need to calculate z[i] naively

      if(i>r){
         
            l=i;
            r=i;

            while(r<len && str[r-l] == str[r])
               r++;
            z[i] = r-l;
            r--;
      }

      else{
         
         // k=i-l; k corresponds to the number which matches int he [l,r]
         // interval
         k=i-l;

         //if z[k] is less than the remaining interval, z[i] will be equal to
         //z[k]
         
         if(z[k] < r-i+1)
            z[i] = z[k];

         else{
            
            l=i;
            while(r<len && str[r-l]==str[r])
               r++;
            z[i] = r-l;
            r--;
         
         }
      }

   }
}

void matchPattern(string str, string pat){
   
   string strPat = pat+"$"+str;
   int len = strPat.length();

   int z[len];
   makeZArray(strPat, z);

   int i;
   for(i=0; i<len; i++){
      if(z[i]==pat.length()){
         cout << "Pattern at index: " << i-pat.length()-1 << endl;
      }
   }
}

int main(){

   string str = "geeks for geeks";
   string pat = "geek";

   matchPattern(str, pat);
}
