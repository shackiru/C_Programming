#include <stdio.h>

int main()
{
	int score;
	
	scanf("%d", &score);
	if(0 <= score && score <= 10)
	{
		if(score>=9)
		{
			printf("A\n");
		}
		else if(score>=7)
		{
			printf("B\n");
		}
		else if(score>=5)
		{
			printf("C\n");
		}
		else
		{
			printf("D\n");
		}
	}
}
