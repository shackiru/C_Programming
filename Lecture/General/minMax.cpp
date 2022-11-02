#include<stdio.h>

int main()
{
	
	int input;
	int array[1005];
	int min, max;
	
	//3299 1591 287 7590 9034 3646 2440 1228 2937 8692
	
	scanf("%d", &input);
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &array[i]);
	}
	
	min = 2<<20;
	max = -min;
	
	for(int i = 0; i < input; i++)
	{
		if(min > array[i])
		{
			min = array[i];
		}
		if(max < array[i])
		{
			max = array[i];
		}
	}
	
	int max2 = -min;
	for(int i = 0; i < input; i++)
	{
		if(max2 < array[i] && array[i] < max)
		{
			max2 = array[i];
		}
	}
	
	int total = 0;
	
	for(int i = 0; i < input; i++)
	{
		total = array[i] + total;
	}

	printf("min = %d | max = %d | max2= %d\n", min, max, max2);
	printf("avg = %d\n", total/input);
	
	return 0;
}
