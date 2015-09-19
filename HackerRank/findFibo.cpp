/*
 * Author: Khushboo Tekchandani
 * Finding nth fibonacci number given first and second fibonacci number
 * This solution uses matrix exponentiation
 * Matrix exponentiation take O(log(n)) time and is better as compared to
 * Dynamic programming or recursion, which take O(n) and O(2^n) time 
 * respectively
 */

#include <iostream>

using namespace std;

typedef long long Matrix[2][2];

// Matrix multiplication for 2x2 matrices
void matMult(Matrix a, Matrix b){

   int i,j;
   Matrix c;
  
   for(i=0; i<2; i++){
      for(j=0; j<2; j++){
         c[i][j] = (a[0][j] * b[i][0])+
            (a[1][j] * b[i][1]);
      }
   }

   for(i=0; i<2; i++){
      for(j=0; j<2; j++)
         a[i][j] = c[i][j];
   }
}

// Matrix exponentiation
void matPow(Matrix m, int p){
   
   if(p==1)
      return;
   int i;
   for(i=2; i<=p; i++){
      matMult(m,m);
   }
   return;
}



long long findFibo(long long a, long long b,long long n){
   
   Matrix m = {{a+b+b,a+b},{b,a}};

   if(n==0)
      return a;
   if(n==1)
      return b;

   matPow(m,n-1);

   return m[0][0];
}

int main(){

   int i,t;
   long long n;
   long long a, b;
   
   cin >> t;

   for(i=0; i<t; i++){
      
      cin >> n;
      cin >> a;
      cin >> b;
      cout << findFibo(a,b,n) << endl;
   }

   return 0;

}
