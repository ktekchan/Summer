/*
 * Author: Khushboo Tekchandani
 * Longest Common Subsequence, DP
 * find the length of LCS
 * Also, find the length of the shortest supersequence containing both strings
 * Print the so found super-sequence
 */

#include <iostream>
#include <string>

using namespace std;

int max(int a, int b){

   if(a>b)
      return a;
   else
      return b;
}

string lcs(string str1, string str2){

   int len1 = str1.size();
   int len2 = str2.size();

   //Matrix to save the count of the common characters
   int L[len1+1][len2+1];
   int i,j;

   for(i=0; i<=len1; i++){
      for(j=0; j<=len2; j++){

         if(i==0 || j==0)
            L[i][j] = 0;

         else if(str1[i-1]==str2[j-1])
            L[i][j] = 1 + L[i-1][j-1];

         else
            L[i][j] = max(L[i-1][j],L[i][j-1]);
      }
   }

   //Lenght the of the longest common subsequence
   int lenLcs = L[len1][len2];
   char lcs[lenLcs+1];

   lcs[lenLcs] = '\0';

   //Length of the shortest common super-sequence containing both strings
   int lenSup = len1+len2-lenLcs;
   char ssub[lenSup+1];
   ssub[lenSup] = '\0';

   i = str1.size();
   j = str2.size();

   //Building lcs and scs from the L matrix created above
   while(i>0 && j >0){

      //scs will also contains lcs
      if(str1[i-1]==str2[j-1]){
         lcs[lenLcs-1] = str1[i-1];
         ssub[lenSup-1] = str1[i-1];
         i--;
         j--;
         lenLcs--;
         lenSup--;
      }

      //adding those elements that are not part of the lcs to scs
      else if(L[i-1][j] > L[i][j-1]){
         ssub[lenSup-1] = str1[i-1];
         i--;
         lenSup--;
      }

      else{
         ssub[lenSup-1] = str2[j-1];
         j--;
         lenSup--;
      }

   }

   //Remaining elements after either i or j becomes 0
   if(i>0 || j>0){
   
      while(i>0){
         ssub[lenSup-1] = str1[i-1];
         i--;
         lenSup--;
      }

      while(j>0){
         ssub[lenSup-1] = str2[j-1];
         j--;
         lenSup--;
      }
   }

   cout << ssub << endl;
   return lcs;

}

int shortestSuperSeq(string str1, string str2, string lsub){

   int ret;
   int len1 = str1.size();
   int len2 = str2.size();
   int len = lsub.size();

   ret = len1+len2-len;

   return ret;
}

int main(){

   string str1, str2;
   str1 = "aggtab";
   str2 = "gxtxayb";

   string str3 = lcs(str1,str2);
   cout << lcs(str1,str2) << endl;
  // cout << shortestSuperSeq(str1,str2,str3) << endl;

   return 0;
}
