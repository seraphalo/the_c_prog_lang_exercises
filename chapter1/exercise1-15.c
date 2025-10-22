/**
 * Rewrite the temperature conversion program of Section 1.2
 * to use a function for conversion.
 */

#include <stdio.h>

#define LOWER 0 		/* lower limit of table */
#define UPPER 300		/* upper limit */
#define STEP 20			/* step size */


float fahr2Cels(int);


int main()
{
	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahr2Cels(fahr));
	return 0;
}

float fahr2Cels(int fahr) {
	return (5.0/9.0) * (fahr - 32);
}

