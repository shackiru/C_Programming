#include <stdio.h>
#include <math.h>

int main()
{
	int array [200005];
	int inputCase, numOfCase, caseValue;
	
	scanf("%d", &inputCase);
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		for(int i = 1; i <= 2e5; i++)
		{
			array[i] = 0;
		}
		
		scanf("%d", &numOfCase);
		
		for(int i = 0; i < numOfCase; i++)
		{
			scanf("%d", &caseValue);
			array[caseValue]++;
		}
		
		int max = 0;
		int maxValue = 0;
		int arrayMax[20005];
		for(int i = 1; i < 2e5; i++)
		{
			if(max < array[i])
			{
				max = array[i];
				maxValue = 0;
				arrayMax[maxValue++] = i;
			}
			else if(max == array[i])
			{
				arrayMax[maxValue++] = i;
			}
		}
		
		printf("Case #%d: %d\n", testCase + 1, max);
		for(int i = 0; i < maxValue; i++)
		{
			if(i == 0)
			{
				printf("%d", arrayMax[i]);
			}
			else
			{
				printf(" %d", arrayMax[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
