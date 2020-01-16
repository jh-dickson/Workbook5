#include <stdio.h>

int main()
{
    float f = 3.14;
    unsigned char *p = (unsigned char*) &f;
    printf("The representation of float %f is ", f);
    for (int i = 0; i < sizeof(float); p++)
    {
        printf("%i", *p);
        i++;
    }
    printf("\n");
}