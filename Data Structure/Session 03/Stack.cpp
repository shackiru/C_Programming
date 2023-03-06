#include <stdio.h>
#include <stdlib.h>
#define MAX 1

int stack[MAX];
int topIdx;

void push(int val)
{
    if(topIdx == MAX - 1)
    {
        return;
    }
    
    //increase topIDX
    topIdx++;

    //insert to ARRAY
    stack[topIdx] = val;

}

int pop()
{
    if(topIdx == -1)
    {
        return -1;
    }
    int val = stack[topIdx];
    stack[topIdx] = 0;
    topIdx--;
    return val;
}

int top()
{
    return stack[topIdx];
}

void printStack()
{
    for(int i = 0; i <= topIdx; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    topIdx = -1;
    int val;
    push(10);
    push(5);
    printStack();
    val = pop();
    printf("pop = %d\n", val);
    val = pop();
    printf("pop = %d\n", val);
    printStack();

    return 0;
}
