#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines. 
	Note: press ctrl + D to trigger an EOF. */

int main()
{
	int c, nb;
	while((c = getchar()) != EOF)
		if(c == ' ')
			printf("%s", "\\b");
		else if(c == '\t')
			printf("%s", "\\t");
		else if(c == '\n')
			printf("%s", "\\n");
		else
			printf("%c", c);
	
	return 0;
}