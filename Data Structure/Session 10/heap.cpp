#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int heap[105];
int x = 1;

void upheap()
{

}

void downheap()
{

}

int pop()
{

}

void insert(int val)
{
    heap[x] = val;

    //upheap
    while(heap[x/2] > heap[x])
    {
        //swap
        int temp = heap[x];
        heap[x] = heap[x/2];
        heap[x/2] = temp;
    }
    x++;
}

int main()
{

    return 0;
}