#include<stdio.h>
#include<string.h>

void reverse(char *input){

	char output [255];
	int len = strlen(input);
	int i;
	
	for(i=len-1; i >= 0; i--){
		output[i]= input[len-1-i];
	}

	printf ("The reverse string is %s. \n", output);

}

int main(){

	char inputString[255];
	printf("Enter a string: \n");
	scanf ("%s", inputString);

	reverse(inputString);

	return 0;
}
