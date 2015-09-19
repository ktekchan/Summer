#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
using std::string;
using std::stringstream;
using std::cout;

vector<int> parseInts(string str) {
 
    stringstream ss(str); // Insert the string into a stream
    char ch;

    vector<int> integers;
    vector<string> tokens;   
    int x;
    while (ss){
	ss >> x;
	ss >>  ch;
	integers.push_back(x);
    }

    return integers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
