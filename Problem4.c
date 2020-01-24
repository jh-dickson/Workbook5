#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//based on Myrvold and Ruskey permuation ranking algorithm. see: http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.216.9916&rep=rep1&type=pdf
//generic c implementation here: https://rosettacode.org/wiki/Permutations/Rank_of_a_permutation#C:_Myrvold_and_Ruskey
//I've tried to adapt the implementation to best fit the GINRTU->TURING problem

void do_unrank(int rank, int iter, int* intword)
{
    //we need to break the recursion somehow...
    if (iter < 1)
    {
        return;
    }

    //these two blocks below are the crux of the above paper, which explains it much more thoroughly than i could...
    int div, rem, tmpint;
    div = rank / iter;
    rem = rank % iter;
    
    tmpint = intword[rem];
    intword[rem] = intword[iter-1];
    intword[iter-1] = tmpint;

    //recurse (is that a word?) until entire word is gone through
    do_unrank(div, iter-1, intword);
}

//send an array of the position of ints at specified rank to unrank func so we can (eventually) print
void get_perm(int rank, int *intword)
{
    int i;
    //this will always assign the same intword values, but the rank is what matters (passed to do_unrank)
    for (i = 0; i < 6; i++)
    {
        intword[i] = i;
    }
    do_unrank(rank, 6, intword);
}


int main()
{
    //turing acts as a "lookup table" for the char representation of int
    //g=0, i=1, n=2, r=3, t=4, u=5 -> we want 453120
    char turing[6] = {'G', 'I', 'N', 'R', 'T', 'U'};

    int intword[6];
    int iterations = 0;
    char ideal[7] = {"TURING"};
    char output[7] = {""};

    while(strcmp((char *)ideal, (char *)output) != 0)
    {
        printf("Iterations: %d -> ", iterations);
        get_perm(iterations, intword);

        //m&r unrank is reversed from how we want to add to the output...
        int j = 0;
        for (int i = 5; i >= 0; i--)
        {
            output[j] = turing[intword[i]];
            j++;
        }
        output[j] = '\0';
        printf("%s\n", (char *)output);
        iterations++;
    }
}