#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
using std::stringstream;
using std::string;
using std::cout;

int main(){
	string input;
	int length;

	getline(cin, input);
	cin >> length;

	stringstream ss(input);

	int i;
	int space_count = 0;
	for (i=0; i<length; i++){
		if (input[i] == ' ')
			space_count++;
	}

	int final_len = space_count * 2 + length;

	for (i=length-1; i>=0; i--){
		if(input[i] == ' '){
			input[final_len-1] = '0';
			input[final_len-2] = '2';
			input[final_len-3] = '%';
			final_len = final_len - 3;
		}
		else{
			input[final_len-1] = input[i];
			final_len = final_len-1;
		}
		
	}

	cout << input << endl;
	return 0;
}
