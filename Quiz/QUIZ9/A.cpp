#include <stdio.h>

int binarySearch(long long int *arr, int left, int right, int sample, int find)
{
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(arr[mid] == find)
		{
			return mid;
		}
		else if(arr[mid] < find)
		{
			if((mid + 1 <= sample) && (arr[mid + 1] > find))
			{
				return mid;
			}
			else if (mid + 1 > find)
            {
                return mid;
            }
            left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	
	long long int sample;
	long long int temp [testCase + 1] = {};
	
	for(int tc = 1; tc <= testCase; tc++)
	{
		scanf("%lld", &sample);
		temp[tc] = temp[tc - 1] + sample;
	}
	
	int testSample;
	long long int findSample;
	
	scanf("%d", &testSample);
	for(int i = 1; i <= testSample; i++)
	{
		scanf("%lld", &findSample);
		int result = binarySearch(temp, 1, sample, testCase, findSample);	
		printf("Case #%d: %d\n", i, result);
	}
}
