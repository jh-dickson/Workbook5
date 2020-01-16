#include <stdio.h>

int main()
{
    int i = 23456;
    char c = (char)i; //drops high order bits
    float f = 12.345;
    i = (int)f; //dropts the fractional part

    printf("Int i: %d\n", i);
    printf("Char c num: %d, char: %c\n", c, c);
}