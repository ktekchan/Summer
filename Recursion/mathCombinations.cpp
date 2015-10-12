/*
 * Khushboo Tekchandani
 * Find all possible combinations of a mathematical expression
 * Idea: Iterate over entire expression, and at each step calculate all possible
 *       l and r values. Recurse at the next step.
 */

#include <iostream>
#include <vector>

using namespace std;

int evaluate (int operand1, int operand2, char op){

  switch (op){
 
     case '+':
        return operand1+operand2;
        break;
     case '-':
        return operand1-operand2;
        break;
     case '*':
        return operand1*operand2;
        break;
     default:
        return 0;
  }
}

vector<int> evaluateAll (string expression, int start, int end){

   vector<int> res;

   //Indicates only one character, which would be an operand
   if(start==end){
      res.push_back(expression[start]-'0');
      return res;
   }

   // This indicates only three characters of the type 'operand1 operator operand2'
   if(start==(end-2)){
      res.push_back(evaluate(expression[start]-'0',expression[start+2]-'0',expression[start+1]));
      return res;
   }

   int i=start+1;
   for(i; i<=end; i=i+2){
   
      vector<int> left = evaluateAll(expression, start, i-1);
      vector<int>right = evaluateAll(expression, i+1, end);

      for(int j=0; j<left.size(); j++){
      
         for(int k=0; k<right.size(); k++){
         
            res.push_back(evaluate(left[j],right[k],expression[i]));
         }
      }
   }

   return res;
}

int main(){

   string str = "1*2+3*4";
   vector<int> out = evaluateAll(str,0,str.length()-1);

   int i;
   for(i=0; i<out.size(); i++)
   cout << out[i] << endl;

   return 0;
}
