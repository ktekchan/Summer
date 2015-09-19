/*
 * Author: Khushboo Tekchandani
 * Evaluate Reverse polish notation
 */

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

void reversePolish(string str){

   stack<int> s;
   string operators = "+-*/";

   int i = 0;
   while(str[i]){

      if(operators.find(str[i])==-1){
         int num;
         num = (int)str[i] - '0';
         s.push(num);
      }

      else{
         int index = operators.find(str[i]);
         int op1 = s.top();
         s.pop();
         int op2 = s.top();
         s.pop();

         switch(index){
         case 0:
            s.push(op1+op2);
            break;
         case 1:
            s.push(op1-op2);
            break;
         case 2:
            s.push(op1*op2);
            break;
         case 3:
            s.push(op1/op2);
            break;
         }
      }
      
      i++;
   }

   int out = s.top();
   cout << out << endl;
}

int main(){

   string str = "21+3*";

   reversePolish(str);
   return 0;

}
