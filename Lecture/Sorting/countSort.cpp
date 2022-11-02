#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Counting(int arr[], int n, int k)
{
	int count[k+5];

    for(int i = 0; i <= k; i++)
    {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;    
    }

    int x = 0;
    for(int i = 0; i <= k; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            arr[x] = i;
            x++;
        }
    }
}

int main()
{
//    srand(time(0));
//    printf("%d\n", rand() % 101 + 100);

	int num[1005];
	for(int i = 0; i < 1000; i++)
	{
		num[i] = (rand() % 100) + 1;
		printf("%d ", num[i]);
	}
	printf("\n");
    Counting(num, 1000, 100);
    for(int i = 0; i < 1000; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
