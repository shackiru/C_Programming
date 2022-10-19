#include <stdio.h>

int main()
{
	
    int num;

    scanf("%d", &num);
    printf("Hex : %x\n", num);
    printf("Otc : %o\n", num);

    int bin = num;
    int arr[100];
    int n = 0;

    while(bin > 0)
    {
        arr[n] = bin % 2;
        n++;
        bin /= 2;
    }

    printf("Bin : ");

    for(int i = n-1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}
