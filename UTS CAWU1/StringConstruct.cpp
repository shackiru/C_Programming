#include <stdio.h>
#include <string.h>

int main()
{
    int inputCase;
    char word[100005];

    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%s", word);
        getchar();

        int check[30] = {0};
        int len = strlen(word);

        for(int i = 0; i < len; i++)
        {
            check[word[i] - 'a']++;
        }

        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(check[i] > 0)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}