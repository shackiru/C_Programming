#include <stdio.h>

int main()
{
    int inputCase;
    int jojo, lili, bibi;
    int person;

    int total = 0;
    int average = 0;

    scanf("%d", &inputCase);
    scanf("%d %d %d", &jojo, &lili, &bibi);

    for(int i = 0; i < inputCase; i++);
    {
        scanf("%d", &person);
        total = total + person;
    }
    average = (total + jojo + lili + bibi) / (inputCase + 3);

    if(jojo >= average)
    {
        printf("Jojo Lolos\n");
    }
    else
    {
        printf("Jojo tidak lolos\n");
    }

    if(lili >= average)
    {
        printf("Lili Lolos\n");
    }

    else
    {
        printf("lili tidak lolos\n");
    }

    if(bibi >= average)
    {
        printf("Bibi Lolos\n");
    }
    else
    {
        printf("Bibi tidak lolos\n");
    }

    return 0;
}