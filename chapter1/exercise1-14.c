/**
 * Write a program to print a histogram of the frequencies of 
 * different characters in its input.
 * 
 * Didn't bother to handle invisible chars.
 */
	

#include <stdio.h>

// let's only consider chars in the ASCII table
#define MAX_N_CHARS 128

int main(int argc, char const *argv[])
{
	int c;
	int highest = 0;
	int frequencies[MAX_N_CHARS];

	// initialize
	for (int i = 0; i < MAX_N_CHARS; ++i)
		frequencies[i] = 0;

	while ((c = getchar()) != EOF) {
		++frequencies[c];
		highest = frequencies[c] > highest ? frequencies[c] : highest;
	}

	// print the result
	for (int ch = 0; ch < MAX_N_CHARS; ++ch) {
		if (frequencies[ch] > 0 && ch != ' ' && ch != '\t' && ch != '\n')
			printf("%c: %d\n", ch, frequencies[ch]);
	}

	// horizontal histogram
	printf("\nprinting the horizontal histogram\n");
	for (int ch = 0; ch < MAX_N_CHARS; ++ch) {
		int freq = frequencies[ch];
		// ignore all chars that didn't appear and also the blank space chars
		if (freq == 0 || ch == ' ' || ch == '\t' || ch == '\n')
			continue;

		printf("  ");
		for (int i = 0; i < freq; ++i)
			printf("_");
		printf(".\n%c ", ch);
		for (int i = 0; i < freq; ++i)
			printf("_");
		printf("|\n");
	}

	// vertical histogram
	printf("\nprinting the vertical histogram\n");
	int height = highest + 1;
	for (int h = height; h >= 0; --h) {
		if (h > 0)
			printf(" ");
		else
			printf("_");
		for (int ch = 0; ch < MAX_N_CHARS; ++ch) {
			int freq = frequencies[ch];
			// ignore all chars that didn't appear and also the blank space chars
			if (freq == 0 || ch == ' ' || ch == '\t' || ch == '\n')
				continue;
			
			if (freq == h)
				printf("__");
			else if (freq > h)
				printf("||");
			else
				printf("  ");

			if (h >0)
				printf(" ");
			else
				printf("_");
		}
		printf("\n");
	}

	// print the labels for the vertical histogram
	printf(" ");
	for (int ch = 0; ch < MAX_N_CHARS; ++ch) {
		int freq = frequencies[ch];
		if (freq == 0 || ch == ' ' || ch == '\t' || ch == '\n')
			continue;
		printf("%c  ", ch);
	}
	printf("\n");



	return 0;
}