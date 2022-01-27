#include <stdio.h>

/* Write a program to copy its input to its output, replacing each tab
	by \t, each backspace by \b, and each backslash by \\. */

int main()
{
	int c, nb;
	while((c = getchar()) != EOF)
		if(c == 8)
			printf("%s", "\\b");
		else if(c == '\t')
			printf("%s", "\\t");
		else if(c == '\\')
			printf("%s", "\\\\");
		else
			printf("%c", c);
	
	return 0;
}