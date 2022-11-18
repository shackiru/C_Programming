#include <stdio.h>

int bubbleSort(int arr[], int size)
{
    int count = 0;
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
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
    int numCase;
    int price;
    int num[10005];

    scanf("%d",& testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%d %d", &numCase, &price);
        for(int i = 0; i < numCase; i++)
        {
            scanf("%d", &num[i]);
        }
        int count = bubbleSort(num, numCase);
        printf("Case #%d: %d\n", tc + 1, price * count);
    }

    return 0;
}