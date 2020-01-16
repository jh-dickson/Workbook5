#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char word[7] = {'G', 'I', 'N', 'R', 'T', 'U'};
    //g=0, i=1, n=2, r=3, t=4, u=5 -> we want 453120
    int intword[6] = {0,1,2,3,4,5}; 
    int turing[6] = {4,5,3,1,2,0};
    int iterations = 0;

    while (memcmp(intword, turing, sizeof(intword)) != 0)
    {
        for (int i = 5; i >= 0; i--)
        {
            if (intword[i-1] < intword[i] && intword[i] == 5)
            {
                
            }
            iterations++;
        }
    }
    
}