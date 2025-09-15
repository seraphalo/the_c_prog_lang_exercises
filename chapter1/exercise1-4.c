/**
 * Print Celsisu-Fahrenheit table for 
 * celsius = -20, -10, 0, ..., 150; floating-point version
 */

#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    celsius = lower;
    printf("cels\tfahr\n");
    while(celsius <= upper){
        fahr = (9.0/5.0) * celsius + 32;
        printf("%4.0f %7.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
