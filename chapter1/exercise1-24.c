/**
 * Write a program to check a C program for rudimentary syntax errors
 * like unbalanced parentheses, brackets and braces.
 * Don't forget about quotes, both single and double, escape sequences,
 * and comments. (This program is hard if you do it in full generality.)
 * This program does NOT check // style comments.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXCHAR 10000

int is_valid_escape(char c) {
    const char *valid = "abfnrtv0\\\'\"?";
    int i;
    for (i = 0; valid[i] != '\0'; i++) {
        if (valid[i] == c)
            return 1;
    }
    return 0;
}


int push(char stack[], int* sp, char c) {
	if (*sp >= MAXCHAR) {
		printf("Error: stack overflow\n");
		return -1;
	}
	stack[(*sp)++] = c;
	return *sp;
}

char pop(char stack[], int* sp) {
	if (*sp <= 0) {
		printf("Error: stack underflow\n");
		return '\0';
	}
	return stack[--(*sp)];
}

int checkProgram() {
	enum State { NORMAL, IN_STRING, IN_CHAR, IN_COMMENT };

	char stack[MAXCHAR];
	int sp = 0;		// stack pointer

	int state = NORMAL;
	char c;
	char prev = '\0';
	while ((c = getchar()) != EOF) {
		switch (state) {
		case NORMAL: {
			if (prev == '/' && c == '*')
				state = IN_COMMENT;
			else if (prev != '\\' && c == '"') {
				state = IN_STRING;
				// push(stack, sp, c);
			} else if (prev != '\\' && c == '\'') {
				state = IN_CHAR;
				// push(stack, sp, c);
			} else if (c == '(' || c == '[' || c == '{')
				push(stack, &sp, c);
			else if (c == ')') {
				if (sp == 0 || pop(stack, &sp) != '(')
					return 2;		// unbalanced parentheses
			}
			else if (c == ']') {
				if (sp == 0 || pop(stack, &sp) != '[')
					return 3;		// unbalanced brackets
			}
			else if (c == '}') {
				if (sp == 0 || pop(stack, &sp) != '{')
					return 4;		// unbalanced braces
			}
			break;
		}
		case IN_STRING: {
			if (prev == '\\' && !is_valid_escape(c))
				return 1;		// invalid escape
			// resolve the case "\\"
			else if (prev == '\\' && c == '\\')
				c = '\0';
			if (prev != '\\' && c == '"')
				state = NORMAL;
			break;
		}
		case IN_CHAR: {
			if (prev == '\\' && !is_valid_escape(c))
				return 1;		// invalid escape
			// resolve the case '\\'
			else if (prev == '\\' && c == '\\')
				c = '\0';
			if (prev != '\\' && c == '\'')
				state = NORMAL;
			break;
		}
		case IN_COMMENT: {
			if (prev == '*' && c == '/')
				state = NORMAL;
			break;
		}
		}
		prev = c;
	}
	if (sp != 0 || state != NORMAL) {
		// if (sp != 0) {
		// 	printf("%c\n", stack[sp-1]);
		// }
		return 5;		// unbalanced
	}

	return 0;
}



int main(int argc, char const *argv[])
{
	int result = checkProgram();
	if (result == 0)
		printf("\nvalid program\n");
	else
		printf("\nerror: %d\n", result);
	return 0;
}