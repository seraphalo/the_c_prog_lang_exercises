/**
 * Write a program to print a histogram of the lengths of words in its input.
 */

#include <stdio.h>

#define MAX_N_WORDS 256
#define IN 1
#define OUT 0

int main(int argc, char const *argv[]) {

	int lengths[MAX_N_WORDS];
	int state = OUT;
	int c;
	int n_words = 0;
	int cur_length = 0;
	int max_length = 0;

	// 1. gather the lengths of words in input
	while ((c = getchar()) != EOF) {

		if (n_words >= MAX_N_WORDS) {
			printf("The number of words in input has reached the maximum of %d\n", MAX_N_WORDS);
			break;
		}

		// word splitters, note that punctuations are part of words
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				state = OUT;
				lengths[n_words] = cur_length;
				max_length = cur_length > max_length ? cur_length : max_length;
				cur_length = 0;
				++n_words;
			}
		} else {
			state = IN;
			++cur_length;
		}
	}

	// take care of the edge case where no blank before EOF
	if (state == IN) {
		lengths[n_words] = cur_length;
		max_length = cur_length > max_length ? cur_length : max_length;
		++n_words;
	}

	// print the result
	// printf("\nlengths of %d words: ", n_words);
	// for (int i = 0; i < n_words; ++i)
	// {
	// 	printf(" %d", lengths[i]);
	// }
	// printf("\n");


	// 2. print a horizonal histogram
	printf("\nprinting the horizontal histogram\n");
	for (int i = 0; i < n_words; ++i) {
		int len = lengths[i];
		for (int j = 0; j < len; ++j)
			printf("_");
		printf(".\n");

		for (int j = 0; j < len; ++j)
			printf("_");
		printf("|\n");
	}

	// 3. print a vertical histogram
	printf("\nprinting the vertical histogram\n");
	int height = max_length + 1;
	for (int h = height; h >= 0; --h) {
		if (h > 0)
			printf(" ");
		else
			printf("_");

		for (int i = 0; i < n_words; ++i) {
			int len = lengths[i];
			if (len == h)
				printf("__");
			else if (len > h)
				printf("||");
			else
				printf("  ");
			
			if (h > 0)
				printf(" ");
			else
				printf("_");
		}
		printf("\n");
	}

	return 0;
}