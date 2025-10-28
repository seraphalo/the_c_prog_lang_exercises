/**
 * Write a program detab that replaces tabs in the input with the proper
 * number of tabs and blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define MAXLINE 1000		/* maximum input line size */
#define TABSTOP 4

int getDetabbedLine(char s[], int lim);

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];
	while ((len = getDetabbedLine(line, MAXLINE) > 0))
		printf("%s\n", line);
	return 0;
}

int getDetabbedLine(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i) {
		if (c == '\t') {
			// not the most elegant way but...
			int k = TABSTOP - (i % TABSTOP);
			for (int j = 0; j < k; j++) {
				s[i] = ' ';
				i++;
			}
			i--;
		} else if (c == '\n') {
			s[i] = c;
			i++;
			break;
		} else
			s[i] = c;
	}
	s[i] = '\0';
	return i;
}