#include <stdio.h>

int main()
{
	int input, stringCount, index, indexJ;
	char alphabet[1000];
	
	scanf("%d", &input);
	for(index = 0; index < input; index++)
	{
		stringCount = 0;
		scanf("%s", alphabet);
		for(indexJ = 0; alphabet[indexJ] != '\0'; indexJ++)
		{
			stringCount++;
		}
		printf("Case %d:", index + 1);
		for(indexJ = 0; indexJ < stringCount; indexJ++)
		{
			printf("%d", alphabet[indexJ]);
			if(indexJ <	stringCount - 1)
			{
				printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
