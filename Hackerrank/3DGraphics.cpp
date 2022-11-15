#include <stdio.h>

int main()
{
    int a, b , c;
    scanf("%d %d %d", &a, &b, &c);

    for(int i = 0; i < a; i++)
    {
        printf("/");
    }	
    printf("\n");

    for(int j = 0; j < a; j++)
    {
        printf("\\");
    }
    printf("\n");

    for(int k = 0; k < c; k++)
    {
        printf("_");
    }
    printf("\n");
    return 0;
}
