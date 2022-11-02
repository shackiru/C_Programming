#include <stdio.h>
#include <string.h>

int main()
{
	int inputCase, stringArray;
	
	scanf("%d", &inputCase);
	
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		int counter[10000] = {0};
		char diamond[100000] = {0};
		
		scanf("%s", diamond);
		stringArray = strlen(diamond);
		
		for(int indexJ = 0; indexJ < stringArray; indexJ++)
		{
			counter[diamond[indexJ]]++;
		}
		
		int x = 0;
		for(int k = 0; k < 127; k++)
		{
			if(counter[k] != 0)
			{
				x++;
			}
		}
		if(x % 2 == 0)
		{
			printf("Case #%d: Breakable\n", testCase+1);
		}
		else
		{
			printf("Case #%d: Unbreakable\n", testCase+1);
		}
	}
	
	return 0;
}
