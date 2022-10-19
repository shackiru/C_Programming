#include <stdio.h>

int main()
{
	int input;
	int input2;
	int num[10000];
	int value[10000];
	int a, c;
	
	scanf("%d", &input);
	
	for(int i = 1; i <= input; i++)
	{
		scanf("%d", &num[i]);
	}
	
	scanf("%d", &input2);
	for(int i = 1; i <= input2; i++)
	{
		scanf("%d %d", &a, &c);
		num[a] = c;
		printf("Case #%d: ", i);
		for(int j = 1; j <= input; j++)
		{
			if(j != input)
			{
				printf("%d ", num[j]);
			}
			else
			{
				printf("%d", num[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
