#include <stdio.h>
#include <string.h>

int main()
{
	char kata[10];// array of char
	char kata1[10] = "Agnes";
	char kata2[10] = {'J', 'o', 'e', 'l'};
	
	printf("Size : %lu\n", sizeof(kata1));
	printf("Strlen : %lu\n", strlen(kata1));
	
	printf("Size : %lu\n", sizeof(kata2));
	printf("Strlen : %lu\n", strlen(kata2));
	
	
	int listScore[50];
	int nilai[50] = { 1, 2, 3, 4, 5};
	int a, b, c, d, e, f, g;
	
	printf("%d\n", nilai[0]);
	printf("%c\n", kata1[0]);
	printf("%s\n", &kata1[2]);
	printf("%s\n", kata2);

	return 0;
}
