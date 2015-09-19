#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT*/
	int len, test, i, j;
	int enter, exit;
	cin>>len>>test;
	int width[len];
	int min[test];

	for(i=0 ; i<len; i++){
		cin>>width[i];
	}

	for (i=0; i<test; i++){
		min[i] = 3;
		cin>>enter>>exit;
		for (j=enter; j<=exit; j++){
			if(width[j]<min[i]){
				min[i] = width[j];
				if (min[i]==1)
					break;
			}

		}
	}

	for (i=0; i<test; i++){
		cout << min[i]<<endl;
	}
	
    return 0;
}

