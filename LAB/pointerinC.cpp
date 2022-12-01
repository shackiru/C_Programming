#include <stdio.h>

int main()
{
	int number = 10;
	int *numberPointer;
	numberPointer = &number;
	number = 90;
	
	printf("Value of Number: %d\n", number);
	printf("Address of number : %d\n", &number);
	
	/*
		Referencing (Menunjuk Nilai Variable) -> Ampersand
		Deferencing (Mengambil Nilai dari Variable yang Ditunjuk) -> Asterisk
		
		niXeonMyOwnjustd01t.
	*/
	
	printf("\nValue of number pointer: %d\n", numberPointer);
	printf("Value obtained from number: %d\n", *numberPointer);
	printf("Value of number pointer: %d\n", &numberPointer);
	puts("");
	
	/* POINTER AND ARRAY */
	//int scores[10];
	int scores[10] = {90, 100, 77, 68, 65, 50};
	char alphabet[10] = {'A', 'B', 'C', 'D'};
	
	printf("%The 4th element of scores: %d\n", scores[4]);
	
	scores[4] = 99;
	
	printf("%The 2nd element of scores: %d\n", scores[1]);
	printf("%The 4th element of scores: %d\n", scores[4]);
	printf("%The 3rd element of alphabet: %c\n", alphabet[2]);
	
	printf("\nValue of Score: ");
	for(int index = 0; index < 6; index++)
	{	
		printf("%d ", scores[index]);
	}
	printf("\n");
	
	int years[20]  = {0};
	
	printf("Value of Years: ");
	for(int index = 0; index < 6; index++)
	{	
		printf("%d ", years[index]);
	}
	printf("\n\n");
	
	/* Sizeof */
	
	int num = 10;	
	int dayNumbers[] = {1, 2, 3, 4, 5, 6, 7};
	
	printf("%d\n", sizeof(number));
	printf("Size of day numbers: %d\n", 28 / sizeof(dayNumbers[1]));
	
	for(int index = 0; index < sizeof(dayNumbers) / sizeof(dayNumbers[1]); index++)
	{
		printf("%d ", dayNumbers[index]);
	}
	printf("\n\n");
	
	char nama[20] = {'A', 'l', 'i', 'c', 'i', 'a'};
	char name[20] = "Alicia";
	
	for(int index = 0; index < 6; index++)
	{
		printf("%c", name[index]);
	}
	printf("\n");
	
	char *namePointer = "Alicia";
	
	printf("%c\n", *namePointer);
	printf("%c\n", *(namePointer + 1));
	printf("%c\n", *(namePointer + 2));
	printf("%c\n", *(namePointer + 3));
	printf("%c\n", *(namePointer + 4));
	printf("%c\n", *(namePointer + 5));
	printf("\n");
	
	while(*namePointer != '\0')
	{
		printf("%c", *namePointer);
		namePointer++;
	}
	printf("\n");
	
	/* 
	
	2D Array 
	daray_type variable_name[ROW_SIZE][COLUMN SIZE]
	
	*/
	int angka[3][4] = 
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	
	for(int index = 0; index < 3; index++)
	{
		for(int indexJ = 0; indexJ < 4; indexJ++)
		{
			printf("%d ", angka[index][indexJ]);
		}
		printf("\n");
	}
	
	return 0;
}
