#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int value;
    char name[100];
    Node * left;
    Node * right;
    int height;
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

int bf(Node * node)
{
    if(!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node * lR(Node * node)
{
    struct Node * cr = node->right;
    struct Node * crl = cr->left;

    cr->left = node;
    node->right = crl;

    node->height = calc(node);
    cr->height = calc(cr);

    return cr;
}

struct Node * rR(Node * node)
{
    struct Node * cl = node->left;
    struct Node * clr = cl->right;

    cl->right = node;
    node->left = clr;

    node->height = calc(node);
    cl->height = calc(cl);

    return cl;
}

struct Node * insertNode(Node * node, Node * temp)
{
    if(!node) return temp;
    else if(node->value < temp->value) node->left = insertNode(node->left, temp);
    else if(node->value > temp->value) node->right = insertNode(node->right, temp);

    node->height = calc(node);
    int b = bf(node);
    if(b > 1)
    {
        if(bf(node->left) < 0) 
        {
            node->left = lR(node->left);
            return rR(node);
        }
        else if(bf(node->right) > 0)
        {
            node->right = rR(node->right);
            return lR(node);
        }
    }
    return node;
}

struct Node * insertUsingString(Node * node, Node * temp)
{
    if(!node) return temp;
    else if(strcmp(temp->name, node->name) < 0) node->left = insertUsingString(node->left, temp);
    else if(strcmp(temp->name, node->name) > 0) node->right = insertUsingString(node->right, temp);

    node->height = calc(node);
    int b = bf(node);
    if(b > 1)
    {
        if(bf(node->left) < 0) node->left = lR(node->left);
        return rR(node);
    }
    else if(b < 01)
    {
        if(bf(node->right) > 0) node->right = rR(node->right);
        return lR(node);
    }
    return node;
}

struct Node * del(Node * node, int value)
{
    if(!node) return node;
    else if(value < node->value) node->left = del(node->left, value);
    else if(value > node->value) node->right = del(node->right, value);
    else
    {
        if(!node->left && !node->right)
        {
            free(node);
            node = NULL;
        }
        else if(!node->left)
        {
            struct Node * del = node;
            del = node->right;
            free(del);
            del = NULL;
        }
        else if(!node->right)
        {
            struct Node * del = node;
            del = node->left;
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
    int b = bf(node);
    if(b > 1)
    {
        if(bf(node->left) < 0) node->left = lR(node->left);
        return rR(node);
    }
    else if(b < -1)
    {
        if(bf(node->right) > 0) node->right = rR(node->right);
        return lR(node);
    }
    return node;
}

struct Node * delString(Node * node, char * name)
{
    if(!node) return node;
    else if(strcmp(name, node->name) < 0) node->left = delString(node->left, name);
    else if(strcmp(name, node->name) > 0) node->right = delString(node->right, name);
    else
    {
        if(!node->left && !node->right)
        {
            free(node);
            node = NULL;
        }
        else if(!node->left)
        {
            struct Node * del = node;
            del = node->right;
            free(del);
            del = NULL;
        }
        else if(!node->right)
        {
            struct Node * del = node;
            del = node->left;
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
            strcpy(node->name, iter->name);
            node->value = iter->value;
            node->left = delString(node->left, iter->name);
        }
    }

    if(!node) return node;
    int b =  bf(node);

    if(b > 1)
    {
        if(bf(node->left) < 0) node->left = lR(node->left);
        return rR(node);
    }
    else if(b < -1)
    {
        if(bf(node->right) > 0) node->right = rR(node->right);
        return lR(node);
    }
    return node;
}

struct Node * searchNode(Node * node, char * name)
{
    if(!node) return NULL;
    else if(strcmp(name, node->name) < 0) node->left = searchNode(node->left, name);
    else if(strcmp(name, node->name) > 0) node->right = searchNode(node->right, name);
    else return node;
 }

struct Node * delAll(Node * node)
{
    while(node)
    {
        node = delString(node, node->name);
    }
    return node;
}