#include <stdio.h>

int main()	
{
	char array[10000];
	scanf("%[^\n]", array);
	
	for(int index = 0; array[index] != '\0'; index++)
	{
		if(array[index] >= 'A' && array[index] <= 'Z')
		{
			array[index] = array[index] + 32;
		}
	}
	
	for(int indexJ = 0; array[indexJ] != '\0'; indexJ++)
	{
		if(array[indexJ] == '1')
		{
			array[indexJ] = 'i';
		}
		
		else if(array[indexJ] == '2')
		{
			array[indexJ] = 'r';
		}
		
		else if(array[indexJ] == '3')
		{
			array[indexJ] = 'e';
		}
		
		else if(array[indexJ] == '4')
		{
			array[indexJ] = 'a';
		}		
		
		else if(array[indexJ] == '5')
		{
			array[indexJ] = 's';
		}		
		
		else if(array[indexJ] == '6')
		{
			array[indexJ] = 'g';
		}		
		
		else if(array[indexJ] == '7')
		{
			array[indexJ] = 't';
		}
		
		else if(array[indexJ] == '8')
		{
			array[indexJ] = 'b';
		}
		
		else if(array[indexJ] == '9')
		{
			array[indexJ] = 'p';
		}
		
		else if(array[indexJ] == '0')
		{
			array[indexJ] = 'o';
		}
	}
	printf("%s\n", array);
	
	return 0;
}
