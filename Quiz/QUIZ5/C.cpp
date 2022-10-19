#include <stdio.h>

int main()
{
	int inputCase, min;
	int sum1 = 0;
	int sum2 = 0;
	int array[105] = {};
	int counter;
	
	scanf("%d", &inputCase);
	
	for(int tc = 0; tc < inputCase; tc++)
	{
		scanf("%d", &array[tc]);
	}
	
	sum1 = 0;
	sum2 = 0;
	counter = 0;
	min = 100000;
	
	for(int i = 0; i < inputCase; i++)
	{
		if(array[i] % 2 == 0)
		{
			sum1 = sum1 + array[i];
		}		
		else if(array[i] % 2 != 0)
		{
			sum2 = sum2 + array[i];
			if(array[i] < min)
			{
				min = array[i];
			}
		}
		counter++;
	}
	
	if(counter % 2 == 0)
	{
		printf("%d\n", sum1);
	}
	else if(counter % 2 != 0)
	{
		printf("%d\n", sum2);
	}

	return 0;
}

