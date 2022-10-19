#include <stdio.h>
#include <string.h>

int main()
{
	int input, stringCount, indexCompare = 0;
	
	scanf("%d", &input);
	for(int index = 0; index < input; index++)
	{
		char palindrome[1000] = {0};
		char compare[1000] = {0};
		indexCompare = 0;
		
		scanf("%s", palindrome);
		stringCount = strlen(palindrome);
		
		for(int indexJ = (stringCount - 1); indexJ >= 0; indexJ--)
		{
			compare[indexCompare] = palindrome[indexJ];
			indexCompare++;
		}
		
//		for(int indexK = stringCount = 0; indexK < stringCount; indexK++)
//		{
//			printf("%c", compare[indexCompare]);
//		}

		
		if(strcmp(palindrome, compare) == 0)
		{
			printf("Case #%d: Yay, it's a palindrome\n", index + 1);
		}
		else
		{
			printf("Case #%d: Nah, it's not a palindrome\n", index + 1);
		}
	}
	
	return 0;
}
