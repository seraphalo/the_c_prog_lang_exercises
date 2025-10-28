/**
 * Write a program to determin the ranges of char, short, int and long
 * variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you
 * compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(int argc, char const *argv[])
{
	printf("ranges in standard headers:\n");
	printf("\t%-15s [%d, %d]\n", "char:", CHAR_MIN, CHAR_MAX);
	printf("\t%-15s [%d, %d]\n", "signed char:", SCHAR_MIN, SCHAR_MAX);
	printf("\t%-15s [0, %u]\n\n", "unsigned char:", UCHAR_MAX);

	printf("\t%-15s [%d, %d]\n", "short:", SHRT_MIN, SHRT_MAX);
	printf("\t%-15s [0, %u]\n\n", "unsigned short:", USHRT_MAX);

	printf("\t%-15s [%d, %d]\n", "int:", INT_MIN, INT_MAX);
	printf("\t%-15s [0, %u]\n\n", "unsigned int:", UINT_MAX);

	printf("\t%-15s [%ld, %ld]\n", "long:", LONG_MIN, LONG_MAX);
	printf("\t%-15s [0, %lu]\n\n", "unsigned long:", ULONG_MAX);

	printf("ranges by direct computation:\n");
	// only sign bit set 1
	char char_min = (char)(1 << 7);
	// all bits 1 except sign bit
	char char_max = ~char_min;
	printf("\t%-15s [%d, %d]\n", "signed char:", char_min, char_max);
	// all bits set to 1
	unsigned char uchar_max = ~0;
	printf("\t%-15s [0, %u]\n\n", "unsigned char:", uchar_max);

	short short_min = (short)(1 << (sizeof(short) * 8 - 1));
	short short_max = ~short_min;
	printf("\t%-15s [%d, %d]\n", "short:", short_min, short_max);
	unsigned short ushort_max = ~0;
	printf("\t%-15s [0, %u]\n\n", "unsigned short:", ushort_max);

	int int_min = (int)(1 << (sizeof(int) * 8 - 1));
	int int_max = ~int_min;
	printf("\t%-15s [%d, %d]\n", "int:", int_min, int_max);
	unsigned uint_max = ~0;
	printf("\t%-15s [0, %u]\n\n", "unsigned int:", uint_max);


	long long_min = (long)(1L << (sizeof(long) * 8 - 1));
	long long_max = ~long_min;
	printf("\t%-15s [%ld, %ld]\n", "long:", long_min, long_max);
	unsigned long ulong_max = ~0LU;
	printf("\t%-15s [0, %lu]\n\n", "unsigned long:", ulong_max);


	return 0;
}