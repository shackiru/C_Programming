#include <stdio.h>

int main()
{
    int meatPrice, vegPrice, eggPrice;

    scanf("%d %d %d", &meatPrice, &vegPrice, &eggPrice);

    if(meatPrice > vegPrice && meatPrice > eggPrice)
    {
        printf("Daging\n");
        if(vegPrice > eggPrice)
        {
            printf("Sayur\nTelur\n");
        }
        else
        {
            printf("Telur\nSayur\n");
        }
    }

    else if(eggPrice > vegPrice && eggPrice > meatPrice)
    {
        printf("Telur\n");
        if(meatPrice > vegPrice)
        {
            printf("Daging\nSayur\n");
        }
        else
        {
            printf("Sayur\nDaging\n");
        }
    }
    else
    {
        printf("Sayur\n");
        if(eggPrice > meatPrice)
        {
            printf("Telur\nDaging\n");
        }
        else
        {
            printf("Daging\nTelur");
        }
    }

    return 0;
}