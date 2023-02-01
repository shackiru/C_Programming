#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 12

int tree[MAXSIZE];


void initTree()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        tree[i] = -1;
    }
}
int searchNode(int x)
{
    int i;
    for(i = 0; i < MAXSIZE; i++)
    {
        if(tree[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void insert(int  x, int p, char child)
{
    if(tree[0] == -1)
    {
        tree[0] = x;
    }
    else
    {
        int pos = searchNode(p);
        if(pos != -1)
        {
            // not root
            if(child == '1')
            {
                // left child
                tree[pos + 1] = x;
            }
            else
            {
                //right child
                tree[pos + 2] = x;
            }
        }
    }
}

void printTree()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        if(tree[i] != -1)
        {
            printf("%d ", tree[i]);
        }
        else
        {
            printf("- ");
        }
    }
    printf("\n");
}

int main()
{
    //root
    int x;
    initTree();
    scanf("%d", &x);
    insert(x, -1, 'p');
    printTree();
    scanf("%d", &x);
    insert(x, 3, 'l');
    printTree();


    return 0;    
}