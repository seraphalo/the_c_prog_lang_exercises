/**
 * Copy input to ouput; 2ed version.
 */
#include <stdio.h>

int main()
{
	int c;
	while((c = getchar()) != EOF)
		putchar(c);
	return 0;
}