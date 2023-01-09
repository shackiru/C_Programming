#include <stdio.h>
#include <stdlib.h>

struct Food
{
    int price;
    struct Food * next;
}*head = NULL, *tail = NULL;

struct Food *createFood(int price)
{
    struct Food *food = (struct Food*) malloc (sizeof(struct Food));
    food->price = price;
    food->next = NULL;
}

int main()
{
    int arr[100] = {1, 2, 3};

    struct Food * food = createFood(23000);
    printf("%d", food->price);

    return 0;
}