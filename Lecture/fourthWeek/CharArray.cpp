#include <stdio.h>
#include <conio.h>

int main()
{
	//	gets
	//	char sentence[20];
	//	gets(sentence);
	//	
	//	printf("%s\n", sentence);

	//getch
	//printf("Entered character is %c\n", getch());
	
	int a = 10;
	int b = 25;
	int result = 0;
	float resultTwo = 0;
	
	//Arithmetic Operator
	
	//result = a + b;
	//result = a - b;
	//result = a * b;
	//result = a / b;
	//result = b % a;
	
	//Typecasting -> Template
	//resultTwo = (float) a / b;
	
	//	printf("Result : %d\n", a--);
	//	printf("A = %d\n", a);
	
	// Copy satu line = CTRL + E, Delete satu line = CTRL + D
	//	printf("Result : %d\n", result);
	//	printf("Result : %f\n", resultTwo);
	
	//	Assignment Operator
	//	int x = 10;
	//	int y = 0;
	//	int score = 5;
	//	score += a; //score = score + a;
	//	
	//	printf("%d\n", score);
	
	//Relational Operator
	//	int num1 = 5;
	//	int num2 = 10;
	//	True -> 1 | False -> 0
	//	printf("%d", a < b);
	
	//Conditional Operator a.k.a Ternary Operator
	
	//	b = a > 4 ? 1 : 7;
	//	printf("%d\n", b);
	
	// Logical Operator
	//	int logic1 = -9;
	//	int logic2 = 5;
	//	
	//	if	(logic1 > 4 && logic1 == -9)
	//	{
	//		printf("Logic One Greater than 4\n");
	//	}
	//	else
	//	{
	//		printf("False");
	//	}
	
	/* 
	*************************** Pointer Operator ***************************
	
	Pointer -> Variable yang valuenya adalah alamat dari Value lain
	(&) -> Return address dari sebuah variable
	Deferencing operator (*) -> Akses value dari Alamat yang disimpan pointer
	*/
	
	int j = -9;
	int *ptrJ;
	ptrJ = &j;
	
	printf("Addres of ptrJ : %d\n", &ptrJ);	
	printf("Addres of J :  %d\n", &j);
	printf("Value of ptrJ :  %d\n", ptrJ);
	printf("Value of J :  %d\n", j);
	printf("Value of J(ptrJ) : %d\n", *ptrJ);
			
	return 0;
}
