/**
 * Count lines, words, and characters in input
 */

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;

	/* again, the line counter does not return the correct value
		when there's a single line without new-line char */
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}