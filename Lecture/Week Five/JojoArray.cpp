#include <stdio.h>

int main()
{
	int inputCase, numOfCase;
	long long int sum;
	int array[2005];
	
	scanf("%d", &inputCase);
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		scanf("%d", &numOfCase);	
		sum = 0;
		for(int i = 0; i < numOfCase; i++)
		{
			scanf("%d", &array[i]);
			sum = sum + array[i];
		}
		
		int count = 0;
		for(int i = 0; i < numOfCase; i++)
		{
			if(array[i] > sum)
			{
				count++;
			}
		}
		printf("Case #%d: %lld\n%d\n", testCase + 1, sum, count);
	}			
	return 0;
}
