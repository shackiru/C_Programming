#include <stdio.h>

int main()
{
	int input, index, indexJ, inputString = 0;
	char alphabet[1000];
	
	scanf("%d", &input);
	
	//Looping banyak input
	for(index = 0; index < input; index++)
	{
		// Fungsinya untuk memasukkan banyak char of array (string)
		inputString = 0;
		scanf("%s", alphabet);
		for(indexJ = 0; alphabet[indexJ] != '\0'; indexJ++)
		{
			inputString++;
		}
		
		printf("Case %d: ", index + 1);
		
		// Untuk ngecek jika input string - 1 lebih besar daripada index J maka print -
		for(indexJ = 0; indexJ < inputString; indexJ++)
		{
			printf("%d", alphabet[indexJ]);
			if(indexJ < inputString - 1)
			{
				printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
