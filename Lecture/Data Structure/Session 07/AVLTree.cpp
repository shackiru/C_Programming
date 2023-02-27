#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct tnode
{
    int value;
    struct tnode * right;
    struct tnode * left;
    int height;
};

struct tnode * root = NULL;

struct tnode * initNode(int val)
{
    struct tnode * temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->value = val;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int height(struct tnode * node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a: b;
}

struct tnode * insertNode(struct tnode * curr, int x)
{
    if(curr == NULL)
    {
        return initNode(x);
    }
    else
    {
        if(x < curr->value)
        {
            curr->left = insertNode(curr->left, x);
        }
        else if(x > curr->value)
        {
            curr->right = insertNode(curr->right, x);
        }
    }
    return curr;
}

int main()
{
    return 0;
}