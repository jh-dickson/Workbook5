#include <stdio.h>

int main()
{
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    n = 2*n -1;
    int sum1 = (n*(n-1))/2;
    sum1 = sum1 * 10;

    printf("Sum: %d", sum1);
}