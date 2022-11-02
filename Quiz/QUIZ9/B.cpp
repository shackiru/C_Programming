#include "stdio.h"
#define ll long long int
ll arr[5000];

void quickSort(ll arr[], int left, int right)
{
    int i = left, j = right;
    ll temp;
    ll pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main()
{
    int inputcase;
    scanf("%d", &inputcase);

    int N;
    for (int i = 0; i < inputcase; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            scanf("%lld", &arr[j]);
        }

        quickSort(arr, 0, N - 1);
        ll max = 0;
        for (int j = 1; j < N / 2; j++)
        {
            if (j == 1)
            {
                max = arr[j] - arr[j - 1];
            }
            else
            {
                if (arr[j] - arr[j - 1] > max)
                    max = arr[j] - arr[j - 1];
            }
        }
        for (int j = N / 2 + 1; j < N; j++)
        {
            if (arr[j] - arr[j - 1] > max)
            {
                max = arr[j] - arr[j - 1];
            }
        }

        printf("Case #%d: %lld\n", i + 1, max);
    }

    return 0;
}