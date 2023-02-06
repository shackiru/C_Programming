#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    char c;
    struct tnode *left;
    struct tnode *right;
};

struct tnode * newNode(char c)
{
    struct tnode *temp =(struct tnode *) malloc (sizeof(struct tnode));
    temp->c = c;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    printf("check");
    return 0;
}