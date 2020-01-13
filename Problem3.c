#include <stdio.h>
#include <math.h>

int main()
{
    int pages = 0;
    int sum = 0;
    while (sum <= 1578)
    {
        pages++;
        sum += log10(pages) + 1;
    }
    printf("Sum: %d\n", sum);
    printf("Pages: %d\n", pages);
}