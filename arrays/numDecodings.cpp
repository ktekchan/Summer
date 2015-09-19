/*
 * Khushboo Tekchandani
 * Count the number of decodings of a number
 * 1 represents 'a', 2 'b' and so on
 * Idea: Dynamic Programming. Count the previous number of decodings
 */

 #include <iostream>
 #include <string>

 using namespace std;

 int countDecodings(string str){
 	int n = str.length();
 	int count[n+1];
 	count[0] = 1;
 	count[1] = 1;

 	int i;
 	for(i=2; i<=n; i++){
 		count[i] = 0;
 		if(str[i-1]>'0')
 			count[i] = count[i-1];

 		if(str[i-2]<'2'|| (str[i-2]=='2' && str[i-1]<'7'))
 			count[i] += count[i-2];
 	}

 	return count[n];
 }

 int main(){
 	string digits = "1234";
 	cout << countDecodings(digits) << endl;
 	return 0;
 }	