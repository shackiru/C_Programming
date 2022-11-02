#include <stdio.h>

int main()
{
    char word[] = "17:58:30AM";

    int hour, minute, second;
    char dn; // dn = day or night  

    sscanf(word, "%d:%d:%d:%cM", &hour, &minute, &second, &dn);

    printf("%02d:%02d:%02d ", hour, minute, second);

    if(dn == 'a')
    {
        printf("Pagi\n");
    }
    else
    {
        printf("Siang\n");
    }

    char result[100];
    sprintf(result, "%02d:%02d:%02d ", hour, minute, second);
    printf("%s\n", result);

    return 0;
}
