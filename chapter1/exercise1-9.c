/**
 * Write a program to copy its input to its output, replacing each string 
 * of one or more blanks by a single blank. 
 * Not sure I have understand the question correctly...
 * Anyway, here I'm replacing any consecutive blanks with a single blank.
 */

#include <stdio.h>

int main(){
	char c;
	int inBlank = 0;
	while((c = getchar()) != EOF){
		if (c == ' '){
			if(inBlank == 0){
				inBlank = 1;
				printf("%c", c);
			}
		}
		else{
			if(inBlank == 1)
				inBlank = 0;
			printf("%c", c);
		}

	}
	return 0;
}