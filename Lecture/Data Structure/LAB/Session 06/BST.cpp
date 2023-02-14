#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Food
{
    char name[100];
    int price;
    struct Food *right;
    struct Food *left;
};

struct Food *createFood(const char *name, int price)
{
    struct Food *newFood = (Food*) malloc (sizeof(Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->left = newFood->right = NULL;
}

int main()
{

    return 0;
}