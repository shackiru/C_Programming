#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    char color[100];
    int height;
    Node * right;
    Node *left;
} * root = NULL;

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

int getHeight(Node * node)
{
    if(!node) return 0;
    return node->height;
}

int calc(Node * node)
{
    if(!node) return 0;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int balance(Node * node)
{
    if(!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node * lR(Node * node)
{
    struct Node * cr = node->left;
    struct Node * crl = cr->left;

    cr->left = node;
    node->right = crl;

    node->height = calc(node);
    cr->height = calc(cr);

    return cr;
}

struct Node * rR(Node * node)
{
    struct Node * cl = node->right;
    struct Node * clr = cl->right;

    cl->right = node;
    node->left = clr;

    node->height = calc(node);
    cl->height = calc(cl);

    return cl;
}

struct Node * insert(Node * node, Node * temp)
{
    if(!node) return temp;
    else if(node->value < temp->value) node->left = insert(node->left, temp);
    else if(node->value > temp->value) node->right = insert(node->right, temp);

    node->height = calc(node);
    int b = balance(node);

    if(b > 1)
    {
        if(balance(node->left) < 0) node->left = lR(node->left);
        return rR(node);
    }
    else if(b < -1)
    {
        if(balance(node->right) > 0) node->right = rR(node->right);
        return lR(node);
    }
    return node;
}

struct Node * search(Node * node, int value)
{
    if(!node) return NULL;
    else if(value < node->value) node->left = search(node->left, value);
    else if(value > node->value) node->right = search(node->right, value);
    else return node;
}

struct Node * del(Node * node, int value)
{
    if(!node) return node;
    else if(node->value < value) node->left = del(node->left, value);
    else if(node->value > value) node->right = del(node->right, value);
    else{
        if(!node->left && !node->right)
        {
            free(node);
            node = NULL;
        }
        else if(!node->left)
        {
            struct Node * del = del->left;
            free(del);
            del = NULL;
        }
        else if(!node->right)
        {
            struct Node * del = del->right;
            free(del);
            del = NULL;
        }
        else
        {
            struct Node * iter = node->left;
            while(iter->right)
            {
                iter = iter->right;
            }
            node->value = iter->value;
            node->left = del(node->left, iter->value);
        }
    }
    if(!node) return node;
    int b = balance(node);

    if(b > 1)
    {
        if(balance(node->left) < 0) node->left = lR(node->left);
        return rR(node);
    }
    else if(b < -1)
    {
        if(balance(node->right) > 0) node->right = rR(node->right);
        return lR(node);
    }

    return node;
}

int main()
{


    return 0;
}