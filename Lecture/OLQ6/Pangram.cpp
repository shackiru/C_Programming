#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1005];

    gets(sentence);
    int len = strlen(sentence);
    int f[30] = {};

    for(int i = 0; i < len; i++)
    {
        if('A' <= sentence[i] && sentence[i] <= 'Z')
        {
            sentence[i] = sentence[i] + 32;
        }
        if('a' <= sentence[i] && sentence[i] <= 'z')
        {
            f[sentence[i] - 'a' ] = 1;
        }
    }    

    int count = 0;
    for(int i = 0; i < 26; i++)
    {
        count = count + f[i];
    }

    if(count == 26)
    {
        printf("Pangram\n");
    }
    else
    {
        printf("Not Pangram\n");
    }

    return 0;
}