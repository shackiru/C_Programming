#include <stdio.h>
#define ll long long int

void quickSort(ll *arr, int left, int right)
{
	int sizeLeft = left;
	int sizeRight = right;
	
	ll temp;
	ll pivot = arr[(left + right) / 2];
	
	while(sizeLeft <= sizeRight)
	{
		while(arr[sizeLeft] < pivot)
		{
			sizeLeft++;
		}
		while(arr[sizeRight] > pivot)
		{
			sizeRight--;
		}
		if(sizeLeft <= sizeRight)
		{
			temp = arr[sizeLeft];
			arr[sizeLeft] = arr[sizeRight];
			arr[sizeRight] = temp;
			
			sizeLeft++;
			sizeRight--;
		}
	}
	if(left < sizeRight)
	{
		quickSort(arr, left, sizeRight);
	}
	if(right > sizeLeft)
	{
		quickSort(arr, sizeLeft, right);
	}
}

int main()
{
	ll arr[5005];
	int testCase;
	scanf("%d", &testCase);
	
	int caseAmount;
	for(int tc = 0; tc < testCase; tc++)
	{
		scanf("%d", &caseAmount);
		for(int i = 0; i < caseAmount; i++)
		{
			scanf("%lld", &arr[i]);
		}
		
		quickSort(arr, 0, caseAmount - 1);
		ll max = 0;
		
		for(int j = 1; j < caseAmount / 2; j++)
		{
			if (j == 1)
            {
                max = arr[j] - arr[j - 1];
            }
            else
            {
				if(arr[j] - arr[j - 1] > max)
				{
					max = arr[j] - arr[j - 1];
				}
			}
		}
		for (int j = caseAmount / 2 + 1; j < caseAmount; j++)
        {
            if (arr[j] - arr[j - 1] > max)
            {
                max = arr[j] - arr[j - 1];
            }
        }
		printf("Case #%d: %lld\n", tc + 1, max);
	}
	return 0;
}
