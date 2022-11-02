#include <stdio.h>

int main()
{
	int inputCase, numOfCase;
	int array[100005];
	
	scanf("%d", &inputCase);
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		scanf("%d", &numOfCase);
		
		int max1, max2;
		for(int i = 0; i < numOfCase; i++)
		{
			scanf("%d", &array[i]);
		}
		max1 = 0;
		for(int i = 0; i < numOfCase; i++)
		{
			if(array[max1] < array[i])
			{
				max1 = i;
			}
		}
		
		int temp = array[max1];
		array[max1] = array[0];
		array[0] = temp;
		
		max2 = 1;
		for(int i = 1; i < numOfCase; i++)
		{
			if(array[max2] < array[i])
			{
				max2 = i;
			}
		}
		printf("Case #%d: %d\n", testCase + 1, array[0] + array[max2]);
	}
		
	return 0;
}
