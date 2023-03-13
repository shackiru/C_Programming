#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVL -> self balancing BST

struct Food
{
    char name[100];
    int price;
    Food *leftChild, *rightChild;
    int height;
};

Food * createFood(const char *name, int price)
{
    Food *newFood = (Food*) malloc (sizeof(Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->height = 1;
    newFood->leftChild = newFood->rightChild = NULL;

    return newFood;
}

Food * 

int main()
{
    return 0;
}