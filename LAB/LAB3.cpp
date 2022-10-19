#include <stdio.h>

int main()
{
	/*
	If
	If(conditions)
	{
		statement
	}
	*/
	
	/* if */
//	char initial = 'A';
//	int score = 70;
//	
//	if((score > 70 || score == 70) && initial != ' ')
//	{
//		printf("kamu hebat\n");
//	}
	
//	printf("Program Stopped\n");

	/*
	If-else
	If(conditions)
	{
		statement
	}
	else
	{
		statement
	}
	*/
	
	/*If else*/
	
//	int value = 90;
//	
//	if(value >= 70)
//	{
//		printf("Score : %d. Great job, you passed\n", value);
//	}
//	else
//	{
//		printf("Score : %d. Sorry, you didn't pass\n", value);
//	}
	
	/*
	If-else if
	If(conditions)
	{
		statement
	}
	else if
	{
		statement
	}
	else
	{
		statement
	}
	*/
	
	/* If else-if */
	
//	char grade = 'A';
//	
//	if(grade == 'A' || grade == 'a')
//	{
//		printf("Grade A.\n");
//	}
//	else if(grade == 'B' || grade == 'b')
//	{
//		printf("Grade B.\n");
//	}
//	else if(grade == 'C' || grade == 'c')
//	{
//		printf("Grade C.\n");
//	}
//	else
//	{
//		printf("You Failed.\n");
//	}

	/*Nested If*/
	
//	int menu = 1; //if menu 1 = do comparison, else = exit
//	
//	if(menu == 1)
//	{
//		int firstNumber = 10;
//		int secondNumber = 20;
//		
//		if(firstNumber > secondNumber)
//		{
//			printf("First number is greater than second number\n");
//		}
//		else
//		{
//			printf("First number is less than second number\n");
//		}
//	}
//	else
//	{
//		printf("Exit\n");
//	}

	/*
	Switch case
	
	switch(expression)
	{
		case value_1:
			statement;
			break;
		case value_2:
			statement;
			break;
		case value_3:
			statement;
			break;
		default:
			statement;
			break;
	}
	*/

//	int dayNumber = 1;
//	
//	switch(dayNumber)
//	{
//		case 1:
//			printf("Monday\n");
//			break;
//		case 2:
//			printf("Tuesday\n");
//			break;
//		default:
//			printf("incorrect day number");
//			break;
//	}

//	char rank = 'A';
//	char name[10] = "Ana";
//	
//	switch(rank)
//	{
//		case 'A':
//			printf("Grade A\n");
//			break;
//		case 'B':
//			printf("Grade B\n");
//			break;
//	}

//	bool lampSwitch = 0;
//	
//	switch(lampSwitch)
//	{
//		case true:
//			printf("Lamp is on\n");
//			break;
//		case false:
//			printf("Lamp is off\n");
//			break;
//	}

	/*
	Ternary Operator : 
	<result> = <condition> ? <value_if_true> : <value_if_false>
	*/
	
	int firstNumber = 10;
	int secondNumber = 100;
	int thirdNumber = 30;
	
	int maximalNumber = firstNumber > secondNumber ? firstNumber : 
						(secondNumber > thirdNumber ? secondNumber : thirdNumber);
						
	printf("%d\n", maximalNumber);

	return 0;
}
