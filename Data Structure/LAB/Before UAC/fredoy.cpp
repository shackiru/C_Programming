#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[100];
    int value;
    int height;
    Node * left;
    Node * right;
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

int calculate(Node * node)
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

    node->height = calculate(node);
    cr->height = calculate(cr);

    return cr;   
}

struct Node * rR(Node * node)
{
    struct Node * cl = node->left;
    struct Node * clr = cl->right;

    cl->right = node;
    node->left = clr;

    node->height = calculate(node);
    cl->height = calculate(node);

    return cl;
}

struct Node * createNode(char * name, int value)
{
    struct Node * newNode = (Node *) malloc (sizeof(Node));
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node * insertion(Node * node, Node * temp)
{
    if(!node) return temp;
    else if(node->value < temp->value) node->left = insertion(node->left, temp);
    else if(node->value > temp->value) node->right = insertion(node->right, temp);

    node->height = calculate(node);
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

struct Node * search(Node * node, char *name)
{
    if(!node) return;
    else if(strcmp(node->name, name) < 0) node->left = search(node->left, name);
    else if(strcmp(node->name, name) > 0) node->right = search(node->right, name);
    else return node;
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
        if(bf(node) < 0) node->left = lR(node->left);
        return rR(node);
    }
    else if(b < -1)
    {
        if(bf(node) > 0) node->right = rR(node->right);
        return lR(node);
    }
    return node;
}

void createFredoy(Node * node)
{
    char name[100];
    int value;

    do
    {
        printf("name of fredoy: ");
        scanf("%s", name); getchar();
    } while (strlen(name) < 0);
    do
    {
        printf("value of fredoy: ");
        scanf("%d", &value);
    } while (value < 0);
    
    root = insertion(node, createNode(name, value));
}

void inOrder(Node * node)
{
    if(!node) return;
}