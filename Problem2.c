#include <stdio.h>

int main()
{
    int n, endN, sum;
    printf("Enter N: ");
    scanf("%d", &n);
    endN = (2*n)-1;
    printf("Calculating sum for %d x %d, with final value %d\n", n, n, endN);

    //calc sum of line then add to sum
    int start = 1, end = n;
    sum = 0;
    for (int i = 0; i < n ; i++)
    {
        for (int j = start; j <= end; j++)
        {
            sum += start;
        }
        start++;
        end++;
    }
    printf("Sum: %d\n", sum);
}