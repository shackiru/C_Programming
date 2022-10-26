#include <stdio.h>

long long Trees(int *arr, int size)
{
	if (size == 0)
	{
		return arr[0];
	}
	else
	{
		return arr[size] + Trees(arr, size - 1);
	}
}

int main()
{
	int input, i, j; scanf("%d", &input);
	
	for (i = 1; i <= input; i++)
	{
		int size; scanf("%d", &size);
		int values[size];
		for (j = 0; j < size; j++) scanf("%d", &values[j]);
		printf("Case #%d: %lld\n", i, Trees(values, size - 1));
	}
	
	return 0;
}
