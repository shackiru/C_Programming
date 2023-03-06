#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

int main()
{
    int value = 25;
    int key;
    long long int hashed;
    char buffer[50] = {};

    sprintf(buffer, "%lld", 99 * 99);
    printf("%s\n", buffer);

    char keyC[25] = {};
    if(strlen(buffer) % 2 == 1)
    {
        int mid = strlen(buffer) / 2;
        strncat(keyC, &buffer[mid], 1);
    }
    else
    {
        int mid = strlen(buffer) / 2 - 1;
        strncat(keyC, &buffer[mid], 1);
        strncat(keyC, &buffer[mid + 1], 1);
    }
    char *strBuff;
    printf("%s\n", keyC);

    // strtol solutin
    //hashed = strtol(keyC, &strBuff, 10);

    sscanf(keyC, "%lld", &hashed);
    printf("%lld\n", hashed + 1);

    //division
    hashed = hashed % SIZE;

    return 0;
}
