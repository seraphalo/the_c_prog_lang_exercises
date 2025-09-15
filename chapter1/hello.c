/**
 * The very first C program.
 * The C standard the book uses is way too old for my compiler,
 * which is Apple clang version 17.0.0 (clang-1700.0.13.5), and
 * probably way too old for yours as well. Therefore the original
 * code in the book won't compile. See the error message below.
 * We have to add a return type, and a return statement if we like.
 * This is true for almost all the examples in the book.
 * 
 * error: type specifier missing, defaults to 'int'; 
 * ISO C99 and later do not support implicit int [-Wimplicit-int]
 */

#include <stdio.h>

int main()
{
	printf("hello, world\n");
	return 0;
}