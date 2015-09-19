/*
 * Khushboo Tekchandani
 * Find if there are repeating elements in an array at k distance
 * Idea: Maintain a map of the first k elements and from then on keep comparing
 *		 each element. If at any index there is no match, break
 */

 #include <iostream>
 #include <map>
 #include <set>

 using namespace std;

 void checkRepeat(int arr[], int size, int k){
 	set<int> elems;

 	int i;
 	for(i=0; i<size; i++){

 		if(elems.find(arr[i])!=elems.end()){
 			cout << "true\n";
 			return;
 		}

 		else
 			elems.insert(arr[i]);

 		if(i>=k)
 			elems.erase(arr[i-k]);
 	}

 	cout << "false\n";
 	return;

 }

 int main(){
 	int arr[] = {1, 2, 3, 4, 4};
 	int size = sizeof(arr)/sizeof(arr[0]);
 	int k = 3;

 	checkRepeat(arr,size,k);

 	return 0;
 }