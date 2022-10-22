#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sumOfLeaves(int *array, int size, int sum, int index)
{
    if(index == size)
    {
        printf("%d\n", sum);
        return;
    }
    if(2 * index == size)
    {
        printf("%d\n", sum + array[2 * index]);
        return;
    }
    if(2 * index > size)
    {
        printf("%d\n", sum);
        return;
    }

    sumOfLeaves(array, size, 2 * index, sum + array[2 * index]);
    sumOfLeaves(array, size, (2 * index) + 1, sum + array[(2 * index) + 1]);
}

void sum()
{
    int testCase;
    int amountCase;

    scanf("%d", &testCase);
    getchar();

    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%d", &amountCase);
        getchar();

        int array[amountCase + 1];

        for(int i = 0; i < amountCase; i++)
        {
            scanf("%d", &array[i]);
        }

        printf("Case #%d :\n", tc + 1);
        sumOfLeaves(array, amountCase, 1, array[1]);
    }
}

int main()
{
    sum();

    return 0;
}
