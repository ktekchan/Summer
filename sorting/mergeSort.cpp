/*
 * Khushboo Tekchandani
 * Merge sort
 * Divide and conquer
 */

 #include <iostream>

 using namespace std;

 void merge(int arr[], int l, int m, int r){

 	int size1 = m-l+1;
 	int size2 = r-m;

 	int i,j,k;
 	int left[size1];
 	int right[size2];

 	// Copying into two separate arrays
 	for(i=0; i<size1; i++)
 		left[i] = arr[l+i];
 	for(j=0; j<size2; j++)
 		right[j] = arr[m+1+j];

 	// Merging them back together
 	i=0;
 	j=0;
 	k=0;
 	while(i<size1 && j<size2){
 		if(left[i]<=right[j]){
 			arr[k] = left[i];
 			i++;
 			k++;
 		}

 		else{
 			arr[k] = right[j];
 			j++;
 			k++;
 		}
 	}

 	// Remaining elements
 	while(i<size1){
 		arr[k] = left[i];
 		k++;
 		i++;
 	}

 	while(j<size2){
 		arr[k] = right[j];
 		j++;
 		k++;
 	}

 	return;
 }

 void mergeSort(int arr[], int l, int r){

 	int m = l+(r-l)/2;
 	if(l<r){
 		mergeSort(arr,l,m);
 		mergeSort(arr,m+1,r);
 		merge(arr,l,m,r);
 	}

 	return;
 }

 int main(){

 	int arr[] = {12, 11, 13, 5, 6, 7};
 	int n = sizeof(arr)/sizeof(arr[0]);

 	int l = 0;
 	int r = n-1;
 	mergeSort(arr,l,r);

 	for(int i=0; i<n; i++){
 		cout << arr[i] << " ";
  	}

  	cout << endl;

  	return 0;
 }