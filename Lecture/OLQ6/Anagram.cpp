#include <stdio.h>
#include <string.h>

int main()
{
    int inputCase;
    int numOfCase;
    char stringWord[10005];

    scanf("%d", &inputCase);
    getchar();

    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%s", stringWord);
        getchar();

        int len = strlen(stringWord);

        if(len % 2 == 1)
        {
            printf("-1\n");
        }
        else
        {
            int f1[30], f2[30];
            for(int i = 0; i < 30; i++)
            {
                f1[i] = 0;
                f2[i] = 0;
            }

            for(int j = 0; j < len; j++)
            {
                if(j < len / 2)
                {
                    f1[stringWord[j] - 'a']++;
                }
                else
                {
                    f2[stringWord[j] - 'a']++;
                }
            }
            int count = 0;
            for(int j = 0; j < 26; j++)
            {
                if(f1[j] < f2[j])
                {
                    count = count + f1[j];
                }
                else
                {
                    count = count + f2[j];
                }
            }
            printf("%d\n", (len/2) - count);
        }
    }
    return 0;
}
