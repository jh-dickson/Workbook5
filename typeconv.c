#include <stdio.h>

int main()
{
    char c = 1;
    int i = 2;
    float f = 3.1415;
    double d = i * f; //i conv to float then i*f to double
    long g = (c*i)+i;

    printf("Char c %d\n", c);
    printf("Int i %d\n", i);
    printf("Float f %f\n", f);
    printf("Double d %f\n", d);
    printf("Long g %ld\n", g);
}