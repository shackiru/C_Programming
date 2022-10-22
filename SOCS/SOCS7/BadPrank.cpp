#include <stdio.h>
#include <stdlib.h>

void badPrank()
{
    int testCase;
    int amountCase;
    char string[1005];

    FILE *f = fopen("testdata.in", "r");

    while(fscanf(f, "%d", &testCase) != EOF)
    {
        for(int tc = 0; tc < testCase; tc++)
        {
            fscanf(f, "%d", &amountCase);

            for(int i = 0; i < amountCase; i++)
            {
                fscanf(f, "%[^\n]", string[amountCase]);
            }
        }
    }

}

int main()
{
    badPrank();

    return 0;
}