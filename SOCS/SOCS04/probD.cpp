#include <stdio.h>

int main()
{
	int inputCase, inputArray, reverse;
	
	scanf("%d %d", &inputArray, &inputCase);
		
	char array[inputArray] = {0};
	
	scanf("%s", array);
	
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		scanf("%d", &reverse);
		if(array[reverse] >= 64 && array[reverse] <= 90)
		{
			array[reverse] = array[reverse] + 32;
		}
		else
		{
			array[reverse] = array[reverse] - 32;
		}
	}
	printf("%s\n", array);
	return 0;
}
