/**
 * Count lines in input
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, nl;
	nl = 0;
	/* well, if you type a single line without hitting newline,
		the answer will not be correct */
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
	return 0;
}