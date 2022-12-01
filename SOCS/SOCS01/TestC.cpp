#include <stdio.h>

int main()
{
	char stringOne[20];
	char stringTwo[20];
	char stringThree[20];
	
	scanf("%[a-z] %[a-z] %[a-z]", stringOne, stringTwo, stringThree);
	printf("%s %s %s\n", stringThree, stringTwo, stringOne);
	
	return 0;
}
