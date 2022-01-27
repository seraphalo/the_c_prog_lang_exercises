#include <stdio.h>

#define IN 1
#define OUT 0

/* Write a program that prints its input one word per line. */

int main(){
	int c, state;

	state = OUT;

	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;

		else{
			if(state == OUT){
				state = IN;
				printf("\n");
			}
			printf("%c", c);
		}
	}
	return 0;
}