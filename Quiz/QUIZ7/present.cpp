#include <stdio.h>

int main()
{
	int testCase;
	int amountCase;
	int count = 0;
	int present = 0;
	
	scanf("%d", &testCase);
	for(int tc = 0; tc < testCase; tc++)
	{
		int compare = 0;
		
		scanf("%d", &amountCase);
		for(int i = 0; i < amountCase; i++)
		{
			scanf("%d", &present);
			if(present > compare)
			{
				compare = present;
				count = 1;
			}
			else if(present == compare)
			{
				count++;
			}
		}
		printf("Case #%d: %d\n", tc + 1, count);
		count = 0;
	}
	return 0;
}
