#include <stdio.h>

int main()
{
	int input;
	int max = 0;
	int array[200000] = {0};
	int arrayB[200000] = {0};
	int d = 0;
	
	for(int i = 0; i < 8; i++)
	{
		scanf("%d", &input);
		array[input]++;
	}
	
//	for(int i = 0; i < 8; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	puts("");
	
	for(int i = 0; i < 8; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
		puts("");
	}
//	printf("%d", max);
	
//	for(int i = 0; i < 8; i++){
//		printf("%d ", array[i]);
//	}
//	puts("");
	
	for(int i = 0; i < 8; i++)
	{
		if(array[i] == max)
		{
			arrayB[d] = i;
			d++;
		}
	}
	
	for(int i = 0; i < d; i++)
	{
		printf("%d ", arrayB[i]);
		if(i != d -1)
		{
			printf(" "); 
		}
	}
	
	return 0;
}
