#include <stdio.h>

int count;
int fibonacci(int n)
{
	int fiboNum;
    if(n == 0)
    {
        fiboNum = 0;
    }  
    else if(n == 1)
    {
    	fiboNum = 1;
	}
	else
	{
		fiboNum  = fibonacci(n - 1) + fibonacci (n - 2);
	}
    count++;
    return fiboNum;
}

int main()
{
    int testCase;
    int countFibo;

    scanf("%d", &testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%d", &countFibo);

        int fiboCounted = 0;

        fiboCounted = fibonacci(countFibo);
        printf("Case #%d: %d\n", tc + 1, count);

        count = 0;
    }

    return 0;
}
