#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food
{
    int id;
    char name[105];
    int price;
    int height;
    Food *left, *right;
};

Food * createFood(int id, char * name, int price)
{
    Food *food = (Food*) malloc (sizeof(Food));
    food->id = id;
    strcpy(food->name, name);
    food->price = price;
    food->height = 1;
    food->left = food->right = NULL;

    return food;
}

int main()
{
    return 0;
}