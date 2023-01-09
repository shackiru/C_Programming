#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node * next;
};

struct node * stack = NULL;

struct node * createNode(int val)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void push(int val)
{
    if(stack == NULL)
    {
        stack = createNode(val);
    }
    else
    {
        struct node * temp = createNode(val);

    }
}

struct node * pop()
{
    //get top of stack
    struct node * delNode = stack;

    // copy value of stack
    struct node * temp = delNode;

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

int main()
{
    push(10);
    push(5);
    printStack();
    struct node * topDat = top();
    printf("top data: %d\n", topDat->val);
    struct node * popped = pop();
    printStack();

    return 0;
}