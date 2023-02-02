#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
    struct tnode *parent;
}*root = NULL;

struct tnode * newNode(int x)
{
    struct tnode *temp = (struct tnode *) malloc (sizeof(struct tnode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}

int main()
{
    int x;
    scanf("%d", &x);
    if(root == NULL)
    {
        root = newNode(x);
    }
    printf("%d \n", root->data);

    scanf("%d", &x);
    root->left = newNode(x);
    root->left->parent = root;
    printf("%d", root->left);

    return 0;

}