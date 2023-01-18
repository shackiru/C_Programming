#include <stdio.h>
#include <string.h>

int main()
{
    int value = 25;
    int key;
    long long int hashed;
    char buffer[50];

    sprintf(buffer, "%lld", 25 * 25);
    printf("%s\n", buffer);

    char keyC[25];
    if(strlen(buffer) % 2 == 1)
    {
        int mid = strlen(buffer) / 2;
        strncat(keyC, &buffer[mid], 1);
    }
    else
    {

    }
    
    printf("%c", buffer[1]);

    return 0;
}