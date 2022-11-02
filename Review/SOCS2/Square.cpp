#include <stdio.h>

int main()
{
    int inputCase;

    scanf("%d", &inputCase);

    for(int tc = 0; tc < inputCase; tc++)
    {
        for(int i = 0; i < inputCase; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}
