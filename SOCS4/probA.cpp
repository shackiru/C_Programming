#include <stdio.h>
#include <string.h>

int main()
{
	int input, reverse, index, indexJ;
	char alphabet[1000];
	
	scanf("%d", &input);
	
	//Untuk menginput banyak
	for(index = 0; index < input; index++)
	{
		
		//untuk reverse alphabet
		scanf("%s", alphabet);
		reverse = strlen(alphabet);
		
		printf("Case %d: ", index + 1);
		for(indexJ = reverse - 1; indexJ >= 0; indexJ--)
		{
			printf("%d", alphabet[indexJ] % 2);
		}
		printf("\n");
	}
	
	return 0;
}
