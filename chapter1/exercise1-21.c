/**
 * Write a program entab that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab. When either a tab or a single
 * blank would suffice to reach a tab stop, which should be given preference?
 */

/**
 * Test cases with TABSTOP = 4:
 * 	abc d 			->		abc\td
 * 	ab  c			->		ab\td
 * 	ab cd			->		ab cd
 * 	ab  c  d		->		ab\tc  d
 * 	ab cde  fgh ij klm  n	->		ab cde\tfgh\tij klm\tn
 */

#include <stdio.h>

#define MAXLINE 1000		/* maximum input line size */
#define TABSTOP 4

int getEntabbedLine(char s[], int lim);

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];
	while ((len = getEntabbedLine(line, MAXLINE) > 0))
		printf("%s\n", line);
	return 0;
}

int getEntabbedLine(char s[], int lim) {
	int c;
	int input_i = 0;
	int output_i = 0;
	int looking = 0;
	int start_input_i = 0;
	while (output_i < lim - 1 && (c = getchar()) != EOF) {
		if (c == ' ') {
			if (!looking) {
				// remembering the spaces start pos
				start_input_i = input_i;
				looking = 1;
			}
			if (input_i % TABSTOP == TABSTOP - 1) {
				// printf("entabbing at input_i = %d\n", input_i);
				// printf("changing output_i = %d to a tab\n", output_i);
				s[output_i] = '\t';
				output_i++;
				// restart the counting
				looking = 0;
			}


		} else {
			if (looking) {
				// no conversion
				looking = 0;
				for (int i = start_input_i; i < input_i; i++) {
					s[output_i] = ' ';
					output_i++;
				}
			}
			s[output_i] = c;
			output_i++;
			if (c == '\n')
				break;
		}
		input_i++;
	}
	s[output_i] = '\0';
	return output_i;
}