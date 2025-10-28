/*
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000		/* maximum input line size */
#define MAXOUTPUT 1024*1024

/* getline function already exists in the stdio.h*/
int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void copy_len(char to[], int to_offset, char from[], int from_offset, int len);
void reverse(char s[], int len);

/* print longest input line */
int main(int argc, char const *argv[])
{
	int len;			/* current line length */
	char line[MAXLINE];		/* current input line */


	while ((len = my_getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s\n", line);
	}

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

void reverse(char s[], int len) {
	int i = 0;
	int j = len - 1;
	char temp;
	while (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}


