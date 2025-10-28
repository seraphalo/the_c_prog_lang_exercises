/**
 * Write a program to remove trailling blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000		/* maximum input line size */
#define MAXOUTPUT 1024*1024

/* getline function already exists in the stdio.h*/
int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void copy_len(char to[], int to_offset, char from[], int from_offset, int len);

/* print longest input line */
int main(int argc, char const *argv[])
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */
	char output[MAXOUTPUT];
	int output_len = 0;

	while ((len = my_getline(line, MAXLINE)) > 0 ) {
		// ignore blank lines
		if (line[0] == '\n')
			continue;
		// remember if the line ends with a newline char
		char last = line[len - 1] == '\n' ? '\n' : '\0';
		int i = len - 1;
		// filling with null chars
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
			line[i] = '\0';
			i--;
		}
		len = i + 1;
		// add the newline char back if necessary
		if (last == '\n') {
			line[len] = last;
			len++;
		}
		if (output_len + len < MAXOUTPUT) {
			copy_len(output, output_len, line, 0, len);
			output_len += len;
		}
	}
	output[output_len] = '\0';
	printf("%s\n", output);
	return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim) {
	int c,i;

	for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

void copy_len(char to[], int to_offset, char from[], int from_offset, int len) {
	for (int i = 0; i < len; i++)
		to[to_offset + i] = from[from_offset + i];
}