#include <stdio.h>

int main()
{
    int inputCase;
    int num[1000];
    int max = 0;

    scanf("%d", &inputCase);
    for(int tc = 0; tc < inputCase; tc++)
    {
        max = 0;
        for(int i = 0; i < 5; i++)
        {
            scanf("%d", &num[i]);
            if(num[i] > max)
            {
                max = num[i];
            }
        }
        printf("Case #%d: %d %d %d %d %d\n", tc+1, max, max, max, max, max);;
    }

    return 0;
}