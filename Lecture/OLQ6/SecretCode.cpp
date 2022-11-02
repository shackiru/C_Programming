#include <stdio.h>
#include <string.h>

int main()
{
	int inputCase;
	char word[1005];
	
	scanf("%d", &inputCase);
	getchar();
	
	for(int tc = 0; tc < inputCase; tc++)
	{
		scanf("%s", word);
		getchar();
		
		printf("Case %d: ", tc + 1);
//		int len = strlen(word);
		
		for(int i = strlen(word) - 1; i >= 0; i--)
		{
			printf("%d", word[i] % 2);	
		}	
		printf("\n");
	}
	
	return 0;
}
