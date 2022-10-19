#include <stdio.h>
#include <string.h>

int main()
{
	int inputCase;
	char array[1000];
	
	for(int testCase = 0; testCase < 3; testCase++)
	{
		scanf("%d", &inputCase);
		scanf("%s", array);
		printf("%c%c", array[inputCase - 1], array[0]);
		printf("\n");
	}
		
	return 0;
}
