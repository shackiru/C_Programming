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

int isLeave(int x)
{
    int pos = searchNode(x);
    if(tree[2 * pos + 1] == -1 && tree[2 * pos + 2] == -1)
    {
        return 1;
    }
    return 0;
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
                tree[2 *pos + 1] = x;
            }
            else
            {
                //right child
                tree[2 * pos + 2] = x;
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
    int check = isLeave(x);
    printf("%d", check);

    return 0;    
}