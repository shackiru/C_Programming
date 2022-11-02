#include <stdio.h>
#include <string.h>

int main()
{
    char word[100];

    scanf("%s", word);
    int len = strlen(word);

    for(int i = 1; i < len - 1; i++)
    {
        for(int j = 1; j < len - i - 1; j++)
        {
            for(int k = j; k <= j+i; k++)
            {
                printf("%c", word[j]);
            }
        }
        printf("\n");
    }
}