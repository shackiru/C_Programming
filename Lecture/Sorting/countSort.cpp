#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Counting(int arr[], int n)
{
	
}

int main()
{
//    srand(time(0));
//    printf("%d\n", rand() % 101 + 100);

	int num[1005];
	for(int i = 0; i < 1000; i++)
	{
		num[i] = (rand() % 100) + 1;
		printf("%d ", num[i]);
	}
	printf("\n");

    return 0;
}
