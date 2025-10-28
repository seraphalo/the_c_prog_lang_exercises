/**
 * Write a program to "fold" long input lines into two or more shorter lines 
 * after the last non-blank character that occurs before the n-th column of input.
 * Make sure your program does something intelligent with very long lies,
 * and if there are no blanks or tabs before the specified column.
 */


#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000		/* maximum input line size */
#define MAX_N_COLUMNS 20

int getAndBreakLine(char line[], int lim);



int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];
	while ((len = getAndBreakLine(line, MAXLINE) > 0))
		printf("%s\n", line);
	return 0;
}


int getAndBreakLine(char line[], int lim) {
	int c;
	int col = 0;			/* in the column coordinate system, range: [0, MAX_N_COLUMNS] */
	int output_i = 0;			/* in the output coordinate system */
	int last_blank_idx = -1;	/* in the output coordinate system */

	while (output_i < lim - 1 && (c = getchar()) != EOF) {
		if (c == '\n')
			break;
		if (c == ' ' || c == '\t')
			last_blank_idx = output_i;
		if (col == MAX_N_COLUMNS) {
			// no blanks or tabs before
			if (last_blank_idx == -1) {
				// force break at column n
				line[col] = '\n';
				col = 0;
				output_i++;
			} else {
				// replace the previous blank with a newline
				line[last_blank_idx] = '\n';
				col = output_i - last_blank_idx - 1;
				last_blank_idx = -1;
			}
		}
		line[output_i] = c;
		col++;
		output_i++;
	}
	line[output_i] = '\0';
	return output_i;
}