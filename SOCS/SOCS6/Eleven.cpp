#include <stdio.h>
#include <string.h>

int main()
{
	int testCase;
	
	scanf("%d", &testCase);
	getchar();
	
	for(int tc = 0; tc < testCase; tc++)
	{
		char string[1000005];
		
		scanf("%s", string);
		getchar();
		
		int convert = strlen(string);
		int r = 0;
		
		for(int i = 0; i  < convert; i++)
		{
			if(i % 2 == 0)
			{
				r = r + (string[i] - '0');
			}
			else
			{
				r = r - (string[i] - '0');
			}
		}
		
		if(r % 11 == 0)
		{
			printf("Case #%d: Yeah\n", tc + 1);
		}
		else
		{
			printf("Case #%d: Nah\n", tc + 1);
		}
	}
	
	return 0;
}
