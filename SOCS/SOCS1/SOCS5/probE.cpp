#include <stdio.h>
#include <string.h>

int main()
{
	int inputCase;
	char word[1005] = {};
	int array[1005] = {};
	
	scanf("%d", &inputCase);
	
	for(int tc = 0; tc < inputCase; tc++)
	{
		scanf("%s", word);
		
		for(int i = 0; i < strlen(word); i++)
		{
			if(word[i] == 'A' || word[i] =='B' || word[i] == 'C' || word[i] == 'D')
			{
				array[i] = word[i] - 'A';
				word[i] = 'A';
			}
			
			else if(word[i] == 'E' || word[i] == 'F' || word[i] == 'G' || word[i] == 'H')
			{
				array[i] = word[i] - 'E';
				word[i] = 'E';
			}
			
			else if(word[i] == 'I' || word[i] == 'J' || word[i] == 'K' || word[i] == 'L' || word[i] == 'M' || word[i] == 'N')
			{
				array[i] = word[i] - 'I';
				word[i] = 'I';
			}
			
			else if(word[i] == 'O' || word[i] == 'P' || word[i] == 'Q' || word[i] == 'R' || word[i] == 'S' || word[i] == 'T')
			{
				array[i] = word[i] - 'O';
				word[i] = 'O';
			}
			
			else if(word[i] == 'U' || word[i] == 'V' || word[i] == 'W' || word[i] == 'X' || word[i] == 'Y' || word[i] == 'Z')
			{
				array[i] = word[i] - 'U';
				word[i] = 'U';	
			}
		}
		
		printf("Case #%d:\n", tc + 1);
		printf("%s\n", word);
		
		for(int i = 0; i < strlen(word); i++)
		{
			printf("%d", array[i]);
		}
		printf("\n");
	}
	return 0;
}
