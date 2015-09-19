#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

	char inputString [255];
	int len, i;
	bool unique = true;

	printf ("Enter String: \n");
	scanf ("%s", &inputString);
	
	len = strlen(inputString);

	for (i=0 ; i<len; i++){
		if (inputString[i] == inputString[i+1]){
			unique = false;
			break;
		}
	}

	if (unique)
		printf ("The entered string is unique!\n");
	else
		printf ("The entered string is not unique!\n");
	return 0;
}
