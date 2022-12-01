#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void badPrank()
{
    int testCase;
    int shift;
    char string[1005];

    FILE *f = fopen("testdata.in", "r");

    while(fscanf(f, "%d\n", &testCase) != EOF)
    {
        for(int tc = 0; tc < testCase; tc++)
        {
            fscanf(f, "%d\n", &shift);
            fscanf(f, "%[^\n]\n", string);

            for(int j = 0; j < strlen(string); j++)
            {
                if(string[j] == '0')
                {
                    string[j] = 'O';
                }
                else if(string[j] == '1')
                {
                    string[j] = 'I';
                }
                else if(string[j] == '3')
                {
                    string[j] = 'E';
                }
                else if(string[j] == '4')
                {
                    string[j] = 'A';
                }
                else if(string[j] == '5')
                {
                    string[j] = 'S';
                }
                else if(string[j] == '6')
                {
                    string[j] = 'G';
                }
                else if(string[j] == '7')
                {
                    string[j] = 'T';
                }
                else if(string[j] == '8')
                {
                    string[j] = 'B';
                }
            }
            for(int i = 0; i < strlen(string); i++)
            {
                if(string[i] != 32)
                {
                    string[i] -= shift;
                    if(string[i] < 65)
                    {
                        string[i] += 26;
                    }
                }
            }
            printf("Case #%d: %s\n", tc + 1, string);
        }
    }
}

int main()
{

    badPrank();

    return 0;
}
