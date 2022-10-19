#include <stdio.h>

int main()
{
    int inputCase;
    int numOfCase;
    int array[100005];

    scanf("%d", &inputCase);

    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d", &numOfCase);

        int sumR = 0;
        int sumL = 0;

        for(int i = 0; i < numOfCase; i++)
        {
            scanf("%d", &array[i]);
            sumR = sumR + array[i];
        }

        int flag = 0;
        for(int i = 0; i < numOfCase; i++)
        {
            sumR = sumR - array[i];
            if(sumR == sumL)
            {
                flag = 1;
                break;
            }
            sumL = sumL + array[i];
        }
        if(flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}