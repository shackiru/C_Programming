#include <stdio.h>
#include <string.h>

int main()
{
	int inputCase, reverse;

	scanf("%d", &inputCase);
	for(int testCase = 0; testCase < inputCase; testCase++)
	{
		char array[1000] = {0};
		char array2[1000] = {0};
		scanf("%s", array);
		reverse = strlen(array);
		
		int counter = 0;
		for(int i = reverse - 1; i >= 0; i--)
		{
			if(array[i] >= 64 && array[i] <= 90)
			{
				array[i] = array[i] + 32;
			}
			else
			{
				array[i] = array[i] - 32;
			}
			array2[counter] = array[i];
			counter++;
		}
	printf("Case #%d: %s\n", testCase+1, array2);
	}
	return 0;
}
