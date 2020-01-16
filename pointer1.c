#include <stdio.h>

int main()
{
    char x, y;
    int i;
    short s;

    printf("x is allocated at %p\n", &x);
    printf("i is allocated at %p\n", &i);
    printf("s is allocated at %p\n", &s);
    printf("y is allocated at %p\n", &y);
}