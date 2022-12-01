#include <stdio.h>

int main()	
{
	char array[10000];
	scanf("%[^\n]", array);
	
	for(int index = 0; array[index] != '\0'; index++)
	{
		if(array[index] >= 'a' && array[index] <= 'z')
		{
			array[index] = array[index] - 32;
		}
	}
	
	for(int indexJ = 0; array[indexJ] != '\0'; indexJ++)
	{
		if(array[indexJ] == 'I')
		{
			array[indexJ] = '1';
		}
		
		else if(array[indexJ] == 'R')
		{
			array[indexJ] = '2';
		}
		
		else if(array[indexJ] == 'E')
		{
			array[indexJ] = '3';
		}
		
		else if(array[indexJ] == 'A')
		{
			array[indexJ] = '4';
		}		
		
		else if(array[indexJ] == 'S')
		{
			array[indexJ] = '5';
		}		
		
		else if(array[indexJ] == 'G')
		{
			array[indexJ] = '6';
		}		
		
		else if(array[indexJ] == 'T')
		{
			array[indexJ] = '7';
		}
		
		else if(array[indexJ] == 'B')
		{
			array[indexJ] = '8';
		}
		
		else if(array[indexJ] == 'P')
		{
			array[indexJ] = '9';
		}
		
		else if(array[indexJ] == 'O')
		{
			array[indexJ] = '0';
		}
	}
	printf("%s\n", array);
	
	return 0;
}
