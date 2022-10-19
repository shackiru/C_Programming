#include <stdio.h>
#include <string.h>

int main()
{
	int input, reverse, index, indexJ;
	char alphabet[1000];
	
	scanf("%d", &input);
	for(index = 0; index < input; index++)
	{
		scanf("%s", alphabet);
		reverse = strlen(alphabet);
		
		printf("Case #%d : ", index + 1);
		for(indexJ = reverse - 1; indexJ >= 0; indexJ--)
		{
			printf("%c", alphabet[indexJ]);
		}
		printf("\n");
	}
	
	return 0;
}
