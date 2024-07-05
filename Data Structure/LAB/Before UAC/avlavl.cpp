#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int value;
    char color[100];
    int height;
    struct Node * left;
    struct Node * right;
}*root = NULL;

int pink = 0;
int yellow = 0;
int white = 0;

struct Node * createNode(int value)
{
    struct Node * newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->value = value;
    strcpy(newNode->color, "White");
    newNode->height = 1;

    newNode->left = newNode->right = NULL;
    return newNode;
}

int getMax(int a, int b)
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

int getHeight(struct Node * node)
{
    if(!node)
    {
        return 0;
    }
    return node->height;
}

int calculate(struct Node * node)
{
    return getMax(getHeight(node->left), getHeight(node->right)) + 1;
}

int balance(struct Node * node)
{
    if(!node)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Node * rLeft(struct Node * node)
{
    struct Node * cr = node->right;
    struct Node * crl = cr->left;

    cr->left = node;
    node->right = crl;

    node->height = calculate(node);
    cr->height = calculate(cr);

    return cr;
}

struct Node * rRight(struct Node * node)
{
    struct Node * cl = node->left;
    struct Node * clr = cl->right;

    cl->right = node;
    node->left = clr;

    node->height = calculate(node);
    cl->height = calculate(cl);

    return cl;
}

struct Node * insertNode(Node * node, Node * temp)
{
    if(!node) return temp;

    else if(temp->value > node->value) node->left = insertNode(node->left, temp);
    else if(temp->value < node->value) node->right = insertNode(node->right, temp);

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

void coloring(struct Node * node)
{
    if(!node) return;

    int b = balance(node);
    if(b < 0)
    {
        strcpy(node->color, "Pink");
    }
    else if(b > 0)
    {
        strcpy(node->color, "Yellow");
    }
    else
    {
        strcpy(node->color, "White");
    }

    coloring(node->left);
    coloring(node->right);
}

void inOrder(Node * node)
{
    if(!node) return;

    inOrder(node->left);
    printf("Number: %d || Color: %s || Height: %d ||\n", node->value, node->color, node->height);
    inOrder(node->right);
}

struct Node * search(Node * node, int num)
{
    if(!node) return NULL;
    else if(num < node->value) return search(node->left, num);
    else if(num > node->value) return search(node->right, num);
    else return node;
}

struct Node * deletee(Node * node, int val)
{
    if(!node) return node;
    else if(val > node->value) node->left = deletee(node->left, val);
    else if(val < node->value) node->right = deletee(node->right, val);

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
            del = node->left;

            free(del);
            del = NULL;
        }
        else if(!node->right)
        {
            struct Node * del = node;
            del = node->right;

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
            node->left = deletee(node->left, iter->value);
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

void searchChild(Node * node)
{
    if(!node) return;

    searchChild(node->left);
    searchChild(node->right);

    if(strcmp(node->color, "Pink") == 0)
    {
        pink++;
    }
    if(strcmp(node->color, "Yellow") == 0)
    {
        yellow++;
    }
    if(strcmp(node->color, "White") == 0)
    {
        white++;
    }
}

void describe(int n)
{
    pink = yellow = white = 0;
    struct Node * temp = search(root, n);
    searchChild(temp->left);
    searchChild(temp->right);

    printf("Value: %d\n Keyword: %s\n", temp->value, temp->color);
    printf("Number of Pink Children: %d\n", pink);
    printf("Number of Yellow Children: %d\n", yellow);
    printf("Number of White Children: %d\n", white);
}

void insert(int n)
{
    root = insertNode(root, createNode(n));
    coloring(root);
}

void del(int n)
{
    root = deletee(root, n);
    coloring(root);
    inOrder(root);
}

int main()
{
//    int n;
//    char com[100];
//    int val;
//
//    scanf("%d", &n);
//    for(int i = 0; i  < n; i++)
//    {
//        scanf("%s", &com); getchar();
//        if(strcmp(com, "INSERT") == 0)
//        {
//            scanf("%d", &val);
//            insert(val);
//        }
//        else if(strcmp(com, "DESCRIBE") == 0)
//        {
//            scanf("%d", &val);
//            describe(val);
//        }
//        else if(strcmp(com, "DELETE") == 0)
//        {
//            scanf("%d", &val);
//            del(val);
//        }
//        else if(strcmp(com, "VIEW") == 0)
//        {
//            inOrder(root);
//        }
//    }

	root = insertNode(root, createNode(10));
	root = insertNode(root, createNode(11));
	inOrder(root);

    return 0;
}
    