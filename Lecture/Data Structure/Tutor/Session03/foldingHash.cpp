#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

int main()
{
    int value = 5628;
    int key;
    long long int hashed;
    char buffer[50] = {};

    sprintf(buffer, "%d", value);
    char keyC[25] = {};
    int loop = 0;

    if(strlen(buffer) % 2 == 0)
    {
        loop = strlen(buffer) / 2;
    }
    else
    {
        loop = strlen(buffer) / 2 + 1;
    }
    printf("Loop: %d\n", loop);
    int sum = 0;
    int iter = 0;
    int temp = 0;

    while(iter < strlen(buffer))
    {
        if(iter % 2 == 0 && iter + 1 < strlen(buffer))
        {
            temp = temp + (buffer[iter] - '0') * 10;
        }
        else
        {
            temp = temp + (buffer[iter] - '0');
        }
    }

    return 0;
}
