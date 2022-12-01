#include <stdio.h>

void fibonacci(int n, char stringA, char stringB)
{
    int fiboNum;
    if(n == 0)
    {
        printf("%c", stringA);
        return;
    }
    else if(n == 1)
    {
        printf("%c", stringB);
        return;
    }
    else 
    {
        fibonacci(n - 1, stringA, stringB);
        fibonacci(n - 2, stringA, stringB);
    }
}

int main()
{
    int testCase;
    int n;
    char stringA, stringB;

    scanf("%d", &testCase);
    for(int tc = 0; tc < testCase; tc++)
    {
        scanf("%d %c %c", &n, &stringA, &stringB);
        getchar();

        printf("Case #%d: ", tc + 1);
        fibonacci(n, stringA, stringB);
        printf("\n");
    }

    return 0;
}