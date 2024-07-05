#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char name[100];
    int value;
    char color[100];
    int height;
    Node * left;
    Node * right;
} * root = NULL;

int maroon = 0;
int pink = 0;
int navy = 0;
int lightblue = 0;
int white = 0;

struct Node * createNode(char * name, int value)
{
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    strcpy(newNode->color, "White");
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->height = 1;

    newNode->left = newNode->right = NULL;
    return newNode;
}

int max(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int getHeight(Node * node)
{
    if(!node)
    {
        return 0;
    }
    return node->height;
}

int calculate(Node * node)
{
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int balance(Node * node)
{
    if(!node)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Node * rLeft(Node * node)
{
    struct Node * cr = node->right;
    struct Node * crl = cr->left;

    cr->left = node;
    node->right = crl;

    node->height = calculate(node);
    cr->height = calculate(cr);

    return cr;
}

struct Node * rRight(Node * node)
{
    struct Node * cl = node->right;
    struct Node * clr = cl->right;

    cl->right = node;
    node->left = clr;

    node->height = calculate(node);
    cl->height = calculate(cl);

    return cl;
}

struct Node * insertNode(Node * node, Node *temp)
{
    if(!node) return temp;
    else if(node->value < temp->value) node->left = insertNode(node->left, temp);
    else if(node->value > temp->value) node->right = insertNode(node->right, temp);

    node->height = calculate(node);
    int b = balance(node);

    if(b > 1)
    {
        if(balance(node->left) < 0) node->left = rLeft(node->left);
        return rRight(node);
    }
    else if(b < -1)
    {
        if(balance(node->right) > 0) node->right = rRight(node->right);
        return rLeft(node);
    }

    return node;
}

struct Node * search(Node * node, char * name)
{
    if(!node) return NULL;
    else if(strcmp(name, node->name) < 0) return search(node->left, name);
    else if(strcmp(name, node->name) > 0) return search(node->right, name);
    else return node;
}

struct Node * deleteNode(Node * node, char * name)
{
    if(!node) return node;
    else if(strcmp(name, node->name) < 0) node->left = deleteNode(node->left, name);
    else if(strcmp(name, node->name) > 0) node->right = deleteNode(node->right, name);
    else
    {
        if(!node->left && !node->right)
        {
            free(node);
            node = NULL;
        }
        else if(!node->left)
        {
            struct Node * del = node->left;
            free(del);
            del = NULL;
        }
        else if(!node->right)
        {
            struct Node * del = node->right;
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
            node->left = deleteNode(node->left, iter->name);
        }
    }
    if(!node) return node;
    int b = balance(node);
    if(b > 1)
    {
        if(balance(node->left) < 0) node->left = rLeft(node->left);
        return rRight(node);
    }
    else if(b < -1)
    {
        if(balance(node->right) > 0) node->right = rRight(node->right);
        return rLeft(node);
    }
    return node;
}

void inOrder(Node * node)
{
    if(!node) return;
    inOrder(node->left);
    printf("%s %d %s", node->name, node->value, node->color);
    inOrder(node->right);
}

void preOrder(Node * node)
{
    if(!node) return;
    printf("%s %d %s", node->name, node->value, node->color);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node * node)
{
    postOrder(node->left);
    postOrder(node->right);
    printf("%s %d %s", node->name, node->value, node->color);
}

void searchChild(Node * node)
{
    if(!node) return;
    searchChild(node->left);
    searchChild(node->right);

    if(strcmp(node->color, "Maroon") == 0)
    {
        maroon++;
    }
    if(strcmp(node->color, "Pink") == 0)
    {
        pink++;
    } 
    if(strcmp(node->color, "Navy") == 0)
    {
        navy++;
    } 
    if(strcmp(node->color, "Light Blue") == 0)
    {
        lightblue++;
    }
    if(strcmp(node->color, "White") == 0)
    {
        white++;
    }
}

void coloring(Node * node)
{
    if(!node) return;
    int b = balance(node);
    

    if(b < 0)
    {
        strcpy(node->color, "");
    }
}