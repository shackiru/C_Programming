#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char c[100];
    int num;
    Node *leftChild, *rightChild;
    int height;
};

Node * root = NULL;

Node * createNode (const char * c, int num)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    strcpy(newNode->c, c);
    newNode->num = num;
    newNode->height = 1;
    newNode->leftChild = newNode->rightChild = NULL;

    return newNode;
}

int getMax(int left, int right)
{
    if(left >= right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int getHeight(Node * node)
{
    if(node == NULL)
    {
        return 0;
    }
    int lch = getHeight(node->leftChild);
    int rch = getHeight(node->rightChild);

    return getMax(lch, rch) + 1;
}

int getBalance(Node * node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(node->leftChild) - getHeight(node->rightChild);
    }
}

Node * rightRotate(Node * node)
{
    Node * temp = node->leftChild;
    node->leftChild = node->rightChild;
    temp->rightChild = node;

    node->height = getHeight(node);
    temp->height = getHeight(temp);

    return temp;
}

Node * leftRotate(Node * node)
{
    Node * temp = node->rightChild;
    node->rightChild = node->leftChild;
    temp->leftChild = node;

    node->height = getHeight(node);
    temp->height = getHeight(temp);

    return temp;
}

Node * insertNode(Node * curr, char * c, int num)
{
    if(curr == NULL)
    {
        return createNode(C, num);
    }
    if(num < curr->num)
    {
        curr->leftChild = insertNode(curr->leftChild, c, num);
    }
    else if(num > curr->num)
    {
        curr->rightChild = insertNode(curr->rightChild, c, num);
    }

    curr->height =  getHeight(curr);
    int balance = getBalance(curr);

    if(balance > 1)
    {
        if(num > curr->rightChild->num)
        {
            curr->leftChild = leftRotate(curr->leftChild);
        }
    }
    else if(balance < -1)
        {
            if(num < curr->leftChild->num)
            {
                curr->rightChild = rightRotate(curr->rightChild);
            }
        }
    return curr;
}

void inOrder(Node * node)
{
    if(node == NULL)
    {
        return;
    }
    inOrder(node->leftChild);
    printf("%s %d\n", node->c, node->num);
    inOrder(node->rightChild);

    return;
}

Node * deleteNode(Node * node, char * c, int num)
{
    if(node == NULL)
    {
        return node;
    }
    else if(num < node->num)
    {
        node->leftChild = deleteNode(node->leftChild, c, num);
    }
    else if(num > node->num)
    {
        node->rightChild = deleteNode(node->rightChild, c, num);
    }
    else if(num == node->num && strcmp(c, node->c) == 0)
    {
        if(node->leftChild == NULL && node->rightChild == NULL)
        {
            node = NULL;
            free(node);
        }
        else if(node->leftChild == NULL)
        {
            struct Node * del = node;
            node = node->rightChild;

            del = NULL;
            free(del);
        }
        else if(node->rightChild == NULL)
        {
            struct Node * del = node;
            node = node->leftChild;

            del = NULL;
            free(del);
        }
        else
        {
            struct Node * iter = node->leftChild;
            while(iter->rightChild)
            {
                iter = iter->rightChild;
            }
            strcpy(node->c, iter->c);
            node->num = iter->num;

            node->leftChild = deleteNode(node->leftChild, c, num);
        }
    }

    int balance = getBalance(node);
    if(balance > 1)
    {
        if(getBalance(node->leftChild) < 0)
        {
            node->leftChild = leftRotate(node->leftChild);
            return rightRotate(node->rightChild);
        }
        else if(getBalance(node->rightChild) > 0)
        {
            node->rightChild = rightRotate(node->rightChild);
            return leftRotate(node->leftChild);
        }
    }

    return node;
}

void describeVal(Node * node)
{
    printf("value: %d\n", node->num);
    printf("keyword: %s\n", node->c);
}

int main()
{
    int n = 1;
    char string[50];
    char color[10] = "";
    int val;
    scanf("%d", &n);getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%s", string);getchar();
        if(strcmp(string, "INSERT") == 0)
        {
            scanf("%d", &val);
            insertNode(root, color, val);
        }
        else if(strcmp(string, "VIEW") == 0)
        {
            inOrder(root);
        }
        else if(strcmp(string, "DESCRIBE") == 0)
        {
            describeVal(root);
        }
    }
    return 0;
}
