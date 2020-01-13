#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int startArr[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
int endArr[4][4] = {{12,10,11,9}, {16,14,5,13}, {8,6,7,15}, {4,3,2,1}};

void swRow(int rowStart, int rowEnd)
{
    int tmpRow[4];
    for (int i = 0; i < 4; i++)
    {
        tmpRow[i] = startArr[rowStart][i];
        startArr[rowStart][i] = startArr[rowEnd][i];
        startArr[rowEnd][i] = tmpRow[i];  
    }
}

void swCol(int colStart, int colEnd)
{
    int tmpCol[4];
    for (int i = 0; i < 4; i++)
    {
        tmpCol[i] = startArr[i][colStart];
        startArr[i][colStart] = startArr[i][colEnd];
        startArr[i][colEnd] = tmpCol[i];  
    }
}

int main()
{
    int try = 1;
    while(memcmp(startArr, endArr, sizeof(startArr)) != 0)
    {
        srand(time(NULL));
        int r1 = rand() % 4;
        int r2 = rand() % 4;
        int r3 = rand() % 1000;
        if ((r3 % 2) == 0)
        {
            swCol(r1, r2);
        }
        else
        {
            swRow(r1, r2);
        }
        
        if (try % 1000000 == 0)
        {
            printf("\nTry: %d\n", try);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    printf("%d, ", startArr[i][j]);
                } 
            }
        }
        try++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d, ", startArr[i][j]);
        } 
    }
    
}