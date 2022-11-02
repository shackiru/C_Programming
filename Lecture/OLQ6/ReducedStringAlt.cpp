#include <stdio.h>
#include <string.h>

int main()
{
    char word[105];

    scanf("%s", word);
    int checker = 0;
    int len = strlen(word);

    do
    {
        checker = 0;
        char temp[105];
        int j = 0;

        for(int i = 0; i < len; i++)
        {
            if(word[i] == word[i+1])
            {
                i++;
                checker = 1;
            }
            else
            {
                temp[j] = word[i];
                j++;
            }
        
        }
            for(int i = 0; i < j; i++)
            {
                word[i] = temp[i];
            }
            word[j] = 0;
    }
    
    while(checker == 1);

    if(len == 0)
    {
        printf("Empty String\n");
    }
    else
    {
        printf("%s\n", word);
    }
    

    return 0;
}