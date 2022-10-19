#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[1000001];

	
	scanf("%[^\n]", sentence);
	
	int temp[200];		
	int vocal = 0;
	int consonant = 0;
	
	for(int index = 0; index < strlen(sentence); index++)
	{
		// untuk pengecekan huruf vokal
		if(sentence[index] == 'a' || sentence[index] == 'i' || sentence[index] == 'u'|| sentence[index] == 'e' || sentence[index] == 'o')
		{
			if(temp[sentence[index]] == 0)
			{
				vocal++;
				temp[sentence[index]] = 1;
			}
		}
		
		// untuk pengecekan huruf konsonan
		else if(sentence[index] != 32)
		{
			if(temp[sentence[index]] == 0)
			{
			consonant++;
			temp[sentence[index]] = 1;	
			}
		}
	}
	printf("Vocal: %d\n", vocal);
    printf("Consonant: %d\n", consonant);
	
	return 0;
}
