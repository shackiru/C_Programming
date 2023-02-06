#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
    int val;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *root = 0;

struct tnode *newNode(int val)
{
    struct tnode *temp = (struct tnode *) malloc (sizeof(struct tnode));
    temp->val = val;
    temp->left = temp->right = NULL;
}

void insertNode(struct tnode *curr, int x)
{
    if(root == NULL)
    {
        root = newNode(x);
    }
    else
    {
        if(x < curr->val && curr->left == NULL)
        {   
        // jika x lebih kecil dari curr val dan curr adalah leaf, insert

        }
        else if(x > curr->val && curr->right == NULL)
        {
        // jika x lebih besar dari curr val dan curr adalah leaf, insert

        }
        else if(x < curr->val)
        {
        // jika x lebih kecil dari curr val, ke kiri

        }
        else if(x > curr->val)
        {
        // jika x lebih besar dari curr val, ke kanan

        }
    }
}

void infix(struct tnode *curr)
{
    if(curr->left != NULL)
    {
        infix(curr->left);
    }
    printf("%d ", curr->val);
    if(curr->right != NULL)
    {
        infix(curr->right);
    }
}

int main()
{
    int x;
    scanf("%d", &x);
    insertNode(root , 5);
    insertNode(root , 3);
    insertNode(root , 18);
    insertNode(root , 2);
    insertNode(root , 4);
    infix(root);

    return 0;
}