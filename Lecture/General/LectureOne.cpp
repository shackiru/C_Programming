#include <stdio.h>

int main()
{
	/*
	 selection and loop
	 condition operator
	 <  >  <=  >=  ==  !=  
	 
	 !   (not operator)
	 ||  (or operator)
	 &&  (and operator)
	 
	 arithmatic operator
	 + (plus)  
	 - (minus) 
	 * (multiply)
	 / (divide)  
	 % (modulus)
	 
	 bitwise operator
	 |  (or)
	 &  (and)
	 ^  (xor)
	 << (shift left)
	 >> (shift right)
	 
	 untuk selection menggunakan dua condition yaitu
	 if, else 		-> lebih general, bisa untuk range
	 switch, case 	-> lebih spesifik, untuk cek satu persatu
	 
	 */
	 
//	printf("%d\n", 1 || 1 && 0);
//	printf("%d\n", 10 <= 5);

// ********************** if else **********************
	int number;
	
	printf("Masukkan nilai Anda : ", number);
	scanf("%d", &number);
//	if (number <= 5)
//	{
//		printf("Lebih kecil dan sama dengan 5\n");
//	}
//	else if(number > 7)
//	{
//		printf("Lebih dari 7\n");
//	}
//	else
//	{
//		printf("Lebih kecil dan sama dengan 7 dan lebih besar dari 5\n");
//	}

	if (9 <= number && number <= 10)
	{
		printf("A\n");
	}
	else if(7 <= number && number <= 8)
	{
		printf("B\n");
	}
		else if(5 <= number && number <= 6)
	{
		printf("C\n");
	}
		else if (0 <= number && number <= 4)
	{
		printf("D\n");
	}
	else
	{
		printf("Input yang benar");
	}
	
	int num;
	
	scanf("%d", &num);
	
	if(num % 2 == 0)
	{
		printf("Angka %d adalah angka genap\n", num);
	}
	else
	{
		printf("Angka %d adalah angka ganjil\n", num);
	}

	return 0;
}
