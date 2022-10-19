#include <stdio.h>
int main()
{
	char word1[20];
	char word2[20];
	char word3[20];
	char word4[20];
	char word5[20];
	char word6[20];
	
	scanf("%s %s %s", word1, word2, word3);
	scanf("%s %s %s", word4, word5, word6);
	printf("%sszs %sszs %sszs\n", word1, word2, word3);
	printf("%sszs %sszs %sszs\n", word4, word5, word6);
	
	return 0;
}
