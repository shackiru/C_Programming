#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(long long int *arr, int left, int right)
{
	int pivot = arr[right];
	int index = left - 1;
}

void quickSort(long long int *arr, int left, int right)
{
	if(left < right)
	{

	}
}

int binarySearch(long long int *arr, int left, int right, long long int find, int sample)
{
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if((long long)arr[mid] < find)
		{
			if((mid + 1 < sample) && ((long long)arr[mid + 1] > find))
			{
				return mid;
			}
			else if ((long long)mid + 1 > find)
            {
                return mid;
            }
            left = mid + 1;
		}
		else if((long long)arr[mid] == find)
		{
			return mid;
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
		int result = binarySearch(temp, 1, sample, findSample, testCase);	
		printf("Case #%d: %d\n", i, result);
	}
}

