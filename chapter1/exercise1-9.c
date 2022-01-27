#include <stdio.h>

/* Write a program to copy its input to its output, replacint each string of
	one or more blanks by a single blank. 
	Not sure I have understand this correctly...
	Also if-statement is introduced after this exercise, so this may not be the
	best solution. 
	Anyway, here I'm replacing any consecutive blanks with a single blank. */

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