#include <stdio.h>
#include <stdlib.h>

int main()
{
    int userNum = 0, totalNugs = 0, box20 = 0, box9 = 0, box6 = 0, box4 = 0;
    printf("Input a nugget number: ");
    scanf("%d", &userNum);

    while (totalNugs != userNum)
    {
        int diff = userNum - totalNugs;
        if ((diff - 20) >= 0)
        {
            totalNugs += 20;
            box20++;
        }
        else if ((diff - 9) >= 0)
        {
            totalNugs += 9;
            box9++;
        }
        else if ((diff - 6) >= 0)
        {
            totalNugs += 6;
            box6++;
        }
        else if ((diff - 4) >= 0)
        {
            totalNugs += 4;
            box4++;
        }
        else
        {
            printf("Couldn't work it out! This is the best soln:\n");
            printf("20pc Boxes: %d\n", box20);
            printf("9pc Boxes: %d\n", box9);
            printf("6pc Boxes: %d\n", box6);
            printf("4pc Boxes: %d\n", box4);
            exit(0);
        }
    }
    
    printf("Here's the soln:\n");
    printf("20pc Boxes: %d\n", box20);
    printf("9pc Boxes: %d\n", box9);
    printf("6pc Boxes: %d\n", box6);
    printf("4pc Boxes: %d\n", box4);
    return 0;
}