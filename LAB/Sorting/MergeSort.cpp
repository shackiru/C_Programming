#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;
	
	int leftArr[sizeLeft];
	int rightArr[sizeRight];
	
	for(int i = 0; i < sizeLeft; i++)
	{
		leftArr[i] = arr[left + i];
	}
	
	for(int j = 0; j < sizeRight; j++)
	{
		rightArr[j] = arr[mid + j + 1];
	}
	
	int indexLeft = 0;
	int indexRight = 0;
	int indexArray = left;
	
	while(indexLeft < sizeLeft && indexRight < sizeRight)
	{
		if(leftArr[indexLeft] <= rightArr[indexRight])
		{
			arr[indexArray] = leftArr[indexLeft];
			indexLeft++;
		}
		else
		{
			arr[indexArray] = rightArr[indexRight];
			indexRight++;
		}
		indexArray++;
	}
	
	while(indexLeft < sizeLeft)
	{
		arr[indexArray] = leftArr[indexLeft];
		indexLeft++;
		indexArray++;
	}
	
	while (indexRight < sizeRight)
	{
		arr[indexArray] = rightArr[indexRight];
		indexRight++;
		indexArray++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if(left >= right)
	{
		return;
	}
	
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int arr[] = {1, 7, 2, 9, 3, 5, 8};
	int size = (sizeof(arr) / sizeof(arr[0]));
	mergeSort(arr, 0, size - 1);
	display(arr, size);
	
	return 0;
}
