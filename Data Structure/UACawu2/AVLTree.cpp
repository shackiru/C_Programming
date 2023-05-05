#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data
{
    char name[100];
    int num;
    Data *leftChild, *rightChild;
    int height;
};

Data * createData(const char *name, int num)
{
    Data * newData = (Data *) malloc (sizeof(Data));
    strcpy(newData->name, name);
    newData->num = num;
    newData->height = 1;
    newData->leftChild = newData->rightChild = NULL;

    return newData;
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

int getHeight(Data * node)
{
    if(node == NULL)
    {
        return 0;
    }
    int leftChildHeight = getHeight(node->leftChild);
    int rightChildHeight = getHeight(node->rightChild);

    return getMax(leftChildHeight, rightChildHeight) + 1;
}

int getBalance(Data * node)
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

Data * rightRotate(Data * node)
{
    Data * newParent = node->leftChild;
    node->leftChild = newParent->rightChild;
    newParent->rightChild = node;

    node->height = getHeight(node);
    newParent->height = getHeight(newParent);

    return newParent;
}

Data * leftRotate(Data * node)
{
    Data * newParent = node->rightChild;
    node->rightChild = newParent->leftChild;
    newParent->leftChild = node;

    node->height = getHeight(node);
    newParent->height = getHeight(newParent);

    return newParent;
}

int main()
{

    return 0;
}