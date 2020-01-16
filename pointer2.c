#include <stdio.h>

int main()
{
    int y = 2;
    int z = 3;
    int* p = &y;
    int* q = &z;
    (*q)++;
    *p = *p + *q;
    q = q + 1;
    printf("Y is %i\n",y);
}