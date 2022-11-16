#include <stdio.h>


int bubbleSort(int arr[], int size)
{
    int count = 0;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int testCase;
    int caseNum;
    int num[10005];
    int time;

    scanf("%d", &testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%d %d", &caseNum, &time);
        for(int i = 0; i < caseNum; i++)
        {
            scanf("%d", &num[i]);
        }
        int count = bubbleSort(num, caseNum);
        printf("Case #%d: %d\n", tc + 1, time * count);
    }
    return 0;
}