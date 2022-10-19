#include <stdio.h>

void printNumber(int n)
{
    if(n == 0)
    {
        return;
    }
    printf("%d ", n);
    printNumber(n - 1);
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
    	return 1;
	}

    return fibonacci(n - 1) + fibonacci (n - 2);
    
}

int factorial(int n)
{
	if(n >= 1)
	{
		return n * factorial(n - 1);
	}
	else
	{
		return 1;
	}
}

int main()
{
    int inputFibo = 10;
    int n = 5;
    for(int i = n; i > 0; i--)
    {
        printf("%d ", i);
    }
    printf("\n");

    printNumber(n);
	
	printf("\n");
    printf("%d\n", fibonacci(inputFibo));
    printf("Factorial Result : %d", factorial(5));

    return 0;
}
