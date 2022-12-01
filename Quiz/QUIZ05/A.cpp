#include <stdio.h>

int main()
{
	int inputCase, numOfCase;
	
	scanf("%d", &inputCase);
	
	for(int tc = 1; tc <= inputCase; tc++)
	{
		scanf("%d", &numOfCase);
		printf("Case #%d:\n", tc);
		for(int i = 1; i <= numOfCase; i++)
		{
			if(i % 15 == 0)
			{
				printf("%d ", i);
				printf("Lili\n");
			}
			else if(i % 3 == 0)
			{
				printf("%d ", i);
				printf("Jojo\n");
			}
			else if(i % 5 == 0)
			{
				printf("%d ", i);
				printf("Jojo\n");
			}
			else
			{
				printf("%d ", i);
				printf("Lili\n");	
			}

		}
	}
	
	return 0;
}
