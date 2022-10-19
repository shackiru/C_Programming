#include <stdio.h>

int main()
{
    char name[25];

    scanf("%[^\n]", name);
    printf("Happy Birthday to %s.\n", name);

    return 0;
}
