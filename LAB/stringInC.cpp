#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char word[20] = "PPTI BCA";
	int len1 = strlen(word);
	printf("strlen : %d\n", len1);
	
	/* sensitive case compare*/
	char word2[20] = "PPA BCA";
	int len2 = strcmp(word, word2);
	printf("strcmp : %d\n", len2);
	
	/* insensitive case compare */
	int len3 = strcmpi(word, word2);
	printf("strcmpi : %d\n", len3);
	
	/* to copy another string */
	strcpy(word, word2);
	printf("%s\n", word);
	
	/* to connect with another string */
	char word3[20] = "PPTI";
	char word4[20] = "PPA";
	strcat(word3, word4);
	printf("%s\n", word4);
	
	/* to find similar string */
	char word5[20] = "PPTIBCA14";
	char word6[20] = "BCA";
	printf("%s\n", strstr(word5, word6));
	
	/* alphanumeric */
	int num1 = 0;
	for(int i = 0; i < strlen(word5); i++)
	{
		if(isalnum(word5[1]))
		{
			num1++;
		}
	}
	if(num1 == strlen(word5))
	{
		printf("Word is Alphanumeric\n");
	}
	else
	{
		printf("Word is is not Alphanumeric\n");
	}
	
	/* Alpha */
	int num2 = 0;
	for(int i = 0; i < strlen(word5); i++)
	{
		if(isalpha(word5[1]))
		{
			num2++;
		}
	}
	if(num1 == strlen(word5))
	{
		printf("Word is Alphabet\n");
	}
	else
	{
		printf("Word is not Alphabet\n");
	}
	
	/* Check capitalize alphabet*/
	char word7[20] = "Ppti BCA";
	int lower = 0;
	int upper = 0;
	for(int i = 0; i <strlen(word7); i++)
	{
		if(islower(word7[i]))
		{
			lower++;
		}
		if(isupper(word7[i]))
		{
			upper++;
		}
	}
	printf("Word 7 consists of %d Uppercase Chart. & %d Lowercase Char.\n", upper, lower);
	
//	char word8[20];
//	scanf("%[^\n]", word8);
//	for(int i = 0; i <strlen(word8); i++)
//	{
//		if(islower(word7[i]))
//		{
//			word8[i] = toupper(word8[i]);
//		}
//		if(isupper(word7[i]))
//		{
//			word8[i] = tolower(word8[i]);
//		}	
//	}
//	printf("%s\n", word8);
	
//	char input1[20];
//	scanf("%[^\n]", input1);
//	
//	char pattern1[20] = "Mr.";
//	char pattern2[20] = "Ms.";
//	int index = 0;
//	int match = 0;
	
//	for(int i = 0; i < strlen(input1); i++)
//	{
//		if(index == strlen(pattern1))
//		{
//			printf("True\n");
//			break;
//		}
//		
//		if(input1[i] == pattern1[index])
//		{
//			index++;
//		}
//	}

//	int result = strncmp(input1, "Mr.", 3);
//	int result2 = strncmp(input1, "Mrs.", 4);
//	
//	if(result == 0 || result2 == 0)
//	{
//		printf("True\n");
//	}
//	else
//	{
//		printf("False\n");
//	}

	/* Validasi 10 Huruf*/
//	char input[20];
//	do
//	{
//		printf("Input Name :");
//		scanf("%[^\n],", input);
//		getchar();
//	}
//		while(strlen(input) != 10);
//		printf("True\n");
		
	/*Validasi Dua Kata*/
	char input[20];		
	int spaceCounter = 0;
	do
	{
		printf("Input Name :");
		scanf("%[^\n],", input);
		getchar();
		
		for(int i = 1; i <strlen(input) - 1; i++)
		{
			if(input[i] == ' ')
			{
				spaceCounter++;
			}
		}
	}
	
	while(spaceCounter != 1);
	printf("True\n");


	char input2[20];
	char pattern[20] = "BCA";
	char *res;
	
	do
	{
		scanf("%[^\n]", input2);
		getchar();

		res = strstr(input2, pattern);
		if(res)
		{
			printf("Found: %s\n", res);
			break;
		}
		else
		{
			printf("False\n");
		}
	}
	while(strcmp(res,"") == 0);
	

//	int alphabet = 0;
//	int number = 0;
//	char input[20];
//	
//	do
//	{
//		scanf("%s", input);
//		getchar();
//		
//		for(int i = 0; i < strlen(input); i++)
//		{
//			if((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
//			{
//				alphabet++;
//			}
//			else if(input[i] >='0' && input[i] <='9')
//			{
//				number++;
//			}
//		}
//	}
//	while(!(alphabet >= 1 && number >= 1));

	return 0;
}
