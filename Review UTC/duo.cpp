#include <stdio.h>

int main()
{
    int inputCase, numOfCase;
    int array[100005];

    scanf("%d", &inputCase);
    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d", &numOfCase);
        for(int i = 0; i < numOfCase; i++)
        {
            scanf("%d", &array[i]);
        }

        int count = 0;
        for(int i = 0; i < numOfCase;)
        {
            if(array[i] == array[i+1])
            {
                count++;
                i = i + 2;
            }
            else
            {
                i++;
            }
        }
        printf("Case #%d : %d\n", tc + 1, count);
    }

    return 0;
}
