#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alphabetConverter()
{
    int testCase;
    FILE *f = fopen("testdata.in", "r");

    while(fscanf(f, "%d", &testCase) != EOF)
    {
        for(int tc = 0; tc < testCase; tc++)
        {
            char array[105];
            int num;
            int check[26] = {};
            int word[26] = {};

            fscanf(f,"%s\n%d\n", array, &num);

            for(int j = 0; j < strlen(array); j++)
            {
                word[array[j] - 65]++;
            }

            for(int k = 0; k < num; k++)
            {
                char a, b;
                fscanf(f, "%c %c\n", &a, &b);

                if(!check[a-65])
                {
                    word[b - 65] += word[a - 65];
                    word[a - 65] = 0;
                    check[a - 65]++;
                }
            }

            for(int i = 0; i < 26; i++)
            {
                if(word[i])
                {
                    printf("%c %d\n", i + 65, word[i]);
                }
            }
        }
    }
    fclose(f);
}

int main()
{
	alphabetConverter();
	
	return 0;
}
