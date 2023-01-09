#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int stack[MAX];
int topIdx;

void push(int val)
{
    //insert to ARRAY
    stack[topIdx++] = val;

    //increase topIDX
}

int pop()
{
    int val = stack[topIdx];
    stack[topIdx] = 0;
    topIdx--;
    if(topIdx == -1)
    {
        return -1;
    }
    return val;
}

int top()
{
    return stack[topIdx];
}

void printStack()
{
    for(int i = 0; i < topIdx; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    topIdx = 0;
    push(10);
    push(5);
    printStack();
    pop();
    printStack();

    return 0;
}
