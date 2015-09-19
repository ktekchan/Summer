#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;

string sorted (string str){
	string temp = str;
	sort(temp.begin(), temp.end());
	return temp;	 
}

int main (){

	string str1, str2;
	cout << "Enter String 1:";
	cin >> str1;
	cout << "Enter String 2:";
	cin >> str2;
	string sorted1, sorted2;
	sorted1 = sorted(str1);
	sorted2 = sorted(str2);
	if (sorted1 == sorted2)
		cout << "The strings are a permutation \n";
	else
		cout << "The strings are not a permutation\n";
	return 0;
}
