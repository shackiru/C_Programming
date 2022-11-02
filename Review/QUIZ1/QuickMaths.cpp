#include <stdio.h>

int main()
{
    int sum;
    int count;
    
    scanf("%d", &sum);

	count = sum + sum;
	
    printf("%d plus %d is %d\n", sum, sum, count);
    printf("minus one is %d\n", count - 1);

    return 0;
}
