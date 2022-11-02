#include <stdio.h>

int main()
{
    int inputCase;
    int sum1, sum2;

    scanf("%d", &inputCase);
    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d %d", &sum1, &sum2);
    }

	for(int tc = 0; tc < inputCase; tc++)
	{
		printf("%d\n", (sum1/sum2) << sum2);
	}
	
    return 0;
}
