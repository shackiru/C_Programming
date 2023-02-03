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
int lev = 0;

struct tnode * newNode(int x)
{
    struct tnode *temp = (struct tnode *) malloc (sizeof(struct tnode));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}

int isLeave(struct tnode *curr)
{
    if(curr->left == NULL || curr->right == NULL)
    {
        return 1;
    }
    return 0;
}

int rightMostChild(struct tnode * node)
{
    struct tnode *iter = node;
    while(iter->right)
    {
        iter = iter->right;
    }
    return iter->data;
}

int leftMostChild(struct tnode * node)
{
    struct tnode *iter = root;
    while(iter->left)
    {
        iter = iter->left;
    }
    return iter->data;
}

void getHeight(int curlev, struct tnode *curr)
{
    if(curlev > lev)
    {
        lev = curlev;
    }
    if(curr->left)
    {
        getHeight(curlev + 1, curr->left);
    }
    if(curr->right)
    {
        getHeight(curlev + 1, curr->right);
    }
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
    //root->left->parent = root;
    printf("%d \n", root->left->data);
    scanf("%d", &x);
    root->left = newNode(x);

    scanf("%d", &x);
    root->right->right = newNode(x);
    // printf("%d\n", rightMostChild(root));
    // printf("%d\n", leftMostChild(root));

    getHeight(0, root);
    printf("%d\n", lev);

    return 0;

}
