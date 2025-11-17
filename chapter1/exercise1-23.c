/**
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constatns properly.
 * C comments do not test.
 * This program does NOT check // style comments.
 */

#include <stdio.h>

#define MAXCHAR 10000

int readProgram(char s[], int lim) {
	enum State { NORMAL, IN_STRING, IN_COMMENT };

	int state = NORMAL;
	int i = 0;
	char c;
	char prev = '\0';
	while ((c = getchar()) != EOF) {
		switch (state) {
		case NORMAL: {
			if (prev == '/' && c == '*')
				state = IN_COMMENT;
			else if (prev != '\\' && c == '"') {
				state = IN_STRING;
				if (prev != '\0')
					s[i++] = prev;
			} else {
				if (prev != '\0')
					s[i++] = prev;
			}
			break;
		}
		case IN_STRING: {
			if (prev != '\\' && c == '"')
				state = NORMAL;

			if (prev != '\0')
				s[i++] = prev;
			break;

		}
		case IN_COMMENT: {
			if (prev == '*' && c == '/') {
				state = NORMAL;
				c = '\0';
			}
			break;
		}
		}

		prev = c;
	}
	s[i++] = prev;
	s[i] = '\0';

	return i;
}




int main(int argc, char const *argv[])
{
	char program[MAXCHAR];
	readProgram(program, MAXCHAR);
	// printf("%s\n", "done");
	printf("%s\n", program);

	return 0;
}
