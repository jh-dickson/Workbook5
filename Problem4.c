#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//based on Myrvold and Ruskey permuation ranking algorithm. see: http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.216.9916&rep=rep1&type=pdf
//generic c implementation here: https://rosettacode.org/wiki/Permutations/Rank_of_a_permutation#C:_Myrvold_and_Ruskey

void do_unrank(int rank, int* intword)
{
    int i = 6;
    printf("Starting unrank.\n");
    while (i > 1)
    {
        int div, rem, tmpint;
        div = rank / i;
        rem = rank % i;
        
        tmpint = intword[rem];
        intword[rem] = intword[i-1];
        intword[i-1] = tmpint;

        i--;
    }
}

int do_rank(int i, int *intword, int *invintword)
{
    printf("Starting rank - togo: %d\n", i);
    if (i <= 1)
    {
        return 0;
    }

    int prev, tmpint;
    prev = intword[i-1];

    //swap normal with inverse
    tmpint = intword[i-1];
    intword[i-1] = intword[invintword[i-1]];
    intword[invintword[i-1]] = tmpint;

    //swap inverse with inverse
    tmpint = invintword[prev];
    invintword[prev] = invintword[i-1];
    invintword[i-1] = tmpint;

    //keep going until i <= 1 
    return prev + 6 * do_rank(i - 1, intword, invintword);
}

//send an array of the position of ints at specified rank to unrank func so we can print
void get_perm(int rank, int *intword)
{
    printf("Starting get_perm.\n");
    int i;
    for (i = 0; i < 6; i++)
    {
        intword[i] = i;
    }
    do_unrank(rank, intword);
}

int get_rank(int *intword)
{
    printf("Starting get_rank\n");
    int i, ret, *tmpintword, *invintword;

    tmpintword = malloc(6 * sizeof(int));
    invintword = malloc(6 * sizeof(int));

    for (i = 0; i < 6; i++)
    {
        tmpintword[i] = intword[i];
        invintword[intword[i]] = i;
    }
    
    ret = do_rank(6, tmpintword, invintword);
    free(invintword);
    free(tmpintword);

    return ret;
}

int main()
{
    //g=0, i=1, n=2, r=3, t=4, u=5 -> we want 453120
    int intword[6]; 
    int turing[6] = {4,5,3,1,2,0};
    int iterations = 0;

    while (memcmp(intword, turing, sizeof(intword)) != 0)
    {
        get_perm(iterations, intword);
        iterations++;
        printf("Iterations: %d\n", iterations);
    }
    printf("Iterations: %d", iterations);
}