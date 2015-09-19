/*
 * Khushboo Tekchandani
 * Bubble sort
 * In each pass, swap elements if they are not sorted
 * (last i elements will get sorted in each pass)
 */

 #include <iostream>

 using namespace  std;
 
 void bubble(int arr[], int n){

 	int i,j;

 	for(i=0; i<n-1; i++){
 		for(j=0; j<n-i-1; j++){
 			if(arr[j]>arr[j+1])
 				swap(arr[j],arr[j+1]);
 		}
 	}
 }

 int main(){

 	int arr[] = {4, 34, 25, 12, 22, 11, 90};
 	int n = sizeof(arr)/sizeof(arr[0]);

 	bubble(arr,n);

 	int i;
 	for (i=0; i<n; i++)
 		cout << arr[i] << " ";

 	cout << endl;
 	
 	return 0;
 }