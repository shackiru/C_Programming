#include <stdio.h>

int main()
{
	int inputCase, num;
	
	scanf("%d", &inputCase);
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		scanf("%d", &num);
		int factor = 0;
		
		for(int i = 1; i <= num; i++)
		{
			if(num % i == 0)
			{
				factor++;
			}
		}
		if(factor == 2)
		{
			printf("Case #%d: %d is Prime\n", testCase + 1, num);
		}
		else
		{
			printf("Case #%d: %d is not Prime\n", testCase + 1, num);	
		}
	}
	return 0;
}
