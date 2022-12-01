#include <stdio.h>

int main()
{
	int inputCase;
	int numOfCase;

	
	scanf("%d", &inputCase);
	for(int tc = 0; tc < inputCase; tc++)
	{
		
		scanf("%d", &numOfCase);
		
		int plus[100005];
		int minus[100005];
		
		for(int i = 0; i < numOfCase; i++)
		{
			scanf("%d", &plus[i]);
		}
		
		for(int i = 0; i < numOfCase; i++)
		{
			scanf("%d", &minus[i]);
		}
		
		int result[100005] = {};
		printf("Case #%d:", tc+1);
		for(int i = 0; i < numOfCase; i++)
		{
			result[i] = plus[i] - minus[i];
			printf(" %d", result[i]);
		}
		
		printf("\n");
		
	}
	
	return 0;
}
