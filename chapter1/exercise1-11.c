#include <stdio.h>

#define IN 1
#define OUT 0

/* count lines, words, and characters in input 
	Exercise 1-11. How would you test the word count program? What
	kind of input are most likely to uncover bugs if there are any? 

	Answer: Cases that we call edge cases are those that most likely to
	uncover bugs. For example, in this case, we can have empty string,
	string contains only blankspace/tab/newline, string starts or ends
	with them, string contains only one word, and etc. */

main(){
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT){
			state = IN;
			++nw;
		}
	}
}