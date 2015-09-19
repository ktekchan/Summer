#include <stdio.h>
#include <string.h>

void reverse (char *input){

	int len = strlen(input);
	int i;
	char temp;

	for (i=0; i <= (len/2 - 1); i++){
		temp = input[i];
		input[i] = input [len-1-i];	
		input[len-1-i] = temp;
	}
	printf ("Reversed String: %s\n", input);
}

int main (){

	char input[255];
	printf ("Enter a string\n");
	scanf("%s", input);
	reverse(input);
	return 0;
}
