#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch(int numbers[], int left, int right, int find)
{
	if(left <= right)
    {
		int mid = left  + ((right - left) / 2 );
		
		if(find == numbers[mid])
        {
			return mid;
		}

		if(find < numbers[mid])
        {
			return binarySearch(numbers, left, mid - 1, find);
		}
        else
        {
			return binarySearch(numbers, mid + 1, right, find);
		}
	}
	return -1;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	
	for(int j = low; j < high; j++)
    {
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap (&arr[i+1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
    {
		int pivot = partition(arr, low, high);

		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

int main()
{
    int testCase;
    scanf("%d", &testCase);

    int num[200005];
    for(int i = 0; i < testCase; i++)
    {
        scanf("%d", &num[i]);
    }

    quickSort(num, 0, testCase - 1);

    int findNumber;
    scanf("%d", &findNumber);

    int find;
    for(int i = 0; i < findNumber; i++)
    {
        scanf("%d", &find);
        if(find > num[testCase - 1] || find < num[0])
        {
            printf("-1\n");
            continue;
        }

        int where = binarySearch(num, 0, testCase - 1, find);
        if(where == -1)
        {
            printf("-1\n");
        }
        else
        {
            if(num[where] != find)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", where + 1);
            }
        }
    }
    return 0;
}

