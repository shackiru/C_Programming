#include <stdio.h>
#include <string.h>

int main()
{
    char word[105];
    scanf("%s", word);

    int len = strlen(word);
    int n = 0;

    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(word[i] == word[j])
            {
                word[i] = 0;
                word[j] = 0;

                n = n + 2;
            }
        }
            
    }

    for(int i = 0; i < len; i++)
    {
        if(word[i] != 0)
        {
            printf("%c\n", word[i]);
        }
    }

    if(n == len)
    {
        printf("Empty String\n");
    }

    return 0;
}