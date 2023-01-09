#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct node
{
    int val;
    struct node * next;
};

struct node * stack = NULL;
int countEl;

struct node * createNode(int val)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void push(int val)
{
    countEl++;
    if(stack == NULL)
    {
        stack = createNode(val);
    }
    else
    {
        struct node * temp = createNode(val);
        temp->next = stack;
        stack = temp;
    }
}

struct node * pop()
{
    if(!stack)
    {
        struct node * temp = NULL;
        return temp;
    }
    //get top of stack
    struct node * delNode = stack;

    // copy value of stack
    struct node * temp = createNode(delNode->val);

    // delete top stack
    stack = delNode->next;
    free(delNode);

    //return top stack
    return temp;
}

struct node * top()
{
    struct node * temp = stack;
    return temp;
}

void printStack()
{
    struct node * iter = stack;
    while(iter)
    {
        printf("%d ", iter->val);
        iter = iter->next;
    }
    printf("\n");
}

bool isFull()
{
    struct node * iter = stack;
    int value = 0;
    while(iter != NULL)
    {
        iter = iter->next;
        value++;
    }

    printf("%d\n", value);
    if (countEl == MAX)
    {
        return true;
    }

    return false;
}

int main()
{
    push(10);
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    push(5);
    printStack();
    
    struct node * topDat = top();
    printf("top data: %d\n", topDat->val);

    struct node * popped = pop();
    printf("pop data: %d\n", popped->val);

    popped = pop();
    printStack();
    if(popped)
    {
        printf("popped data: %d\n", popped->val);
    }

    popped = pop();
    if(popped)
    {
        printf("popped data: %d\n", popped->val);
    }
    printStack();
    push(17);
    push(17);
    printf("%d\n", isFull());
    printStack();

    return 0;
}
