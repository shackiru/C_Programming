#include <stdio.h>
#include <stdlib.h>

struct tNode
{
    int value;
    struct tNode *next;
    struct tNode *prev;
};

struct tNode *head = NULL;

int main()
{
    head = (struct tNode *) malloc (sizeof(struct tNode));
    head->value = 8;
    head->next = NULL;

    struct tNode *ptr = (struct tNode *) malloc (sizeof(struct tNode));
    ptr->value = 30;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;
    printf("%d\n", head->value);
    printf("%d\n", head->next->value);

    return 0;   
}