#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines. 
	Note: press ctrl + D to trigger an EOF. */

int main()
{
	int c, nb;
	while((c = getchar()) != EOF)
		if(c == ' ' || c == '\t' || c == '\n')
			++nb;
	printf("%d\n", nb);
	return 0;
}