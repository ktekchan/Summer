/*
 * Khushboo Tekchandani
 * Find the median of two sorted arrays
 * Idea: Find the two medians separately and compare them.
 		 Doing this, you discard the parts of both the arrays that will
 		 not contain the median. When you are left with 4 elements, 
 		 compute the final median.
 */

#include <iostream>

using namespace std;

// median of a sorted array
int median(int ar[], int n){
	if(n%2 == 0)
		return (ar[n/2]+ar[n/2-1])/2;
	else
		return ar[n/2];
}

// median of two sorted arrays
int getMedian(int ar1[], int ar2[], int n){
	
	// invalid
	if(n<0)
		return -1;
	// only one element
	if(n==1)
		return (ar1[0]+ar2[0])/2;
	if(n==2)
		return (max(ar1[0],ar2[0]) + min(ar1[1],ar2[1]))/2;

	int med1;
	int med2;

	med1 = median(ar1,n);
	med2 = median(ar2,n);

	// if the two medians are equal
	if(med1==med2)
		return med1;

	if(med1<med2){
		if(n%2 == 0)
			return getMedian(ar1+n/2-1,ar2,n-n/2+1);
		else
			return getMedian(ar1+n/2,ar2,n-n/2);
	}

	if(med2>med1){
		if(n%2 == 0)
			return getMedian(ar1,ar2+n/2-1,n-n/2+1);
		else
			return getMedian(ar1,ar2+n/2,n-n/2);
	}


}

int main(){
	int ar1[] = {1,2,3,6};
	int ar2[] = {4,6,8,10};

	int n = sizeof(ar1)/sizeof(ar1[0]);
	cout << getMedian(ar1, ar2, n) << endl;

	return 0;
}