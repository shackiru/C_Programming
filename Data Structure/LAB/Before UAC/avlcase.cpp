#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct Property
{
    char id[6];
    int N;
    int length;
    char type[20];

    Property *left, *right;
    int height;
};

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

int getHeight(Property * curr)
{
    if(curr == NULL)
    {
        return 0;
    }
}

int getBalance(Property * curr)
{
    if(curr == NULL)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

int calculate(Property * curr)
{
    if(curr == NULL)
    {
        return 0;
    }
    return getMax(getHeight(curr->left), getHeight(curr->right) + 1);
}

Property * rightRotate(Property * curr)
{
    Property * cL = curr->left;
    Property * cLR = cL->right;

    cL->right = curr;
    curr->left = cLR;

    curr->height = calculate(curr);
    cL->height = calculate(cL);

    return cL;
}

Property * leftRotate(Property * curr)
{
    Property * newParent = curr->right;
    Property * newParentSub = newParent->left;

    newParent->left = curr;
    curr->right = newParentSub;

    curr->height = calculate(curr);
    newParent->height = calculate(newParent);

    return newParent;
}

Property *createProperty(char *id, int N, int length, char * type)
{
    Property *newNode = (Property *) malloc (sizeof(Property));
    newNode->N = N;
    newNode->length = length;
    strcpy(newNode->id, id);
    strcpy(newNode->type, type);

    newNode->height = 1;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Property *insertProperty(Property * curr, Property * node)
{
    if(curr == NULL)
    {
        return node;
    }
    else if(strcmp(node->id, curr->id) < 0)
    {
        curr->left = insertProperty(curr->left, node);
    }
    else if(strcmp(node->id, curr->id) > 0)
    {
        curr->right = insertProperty(curr->right, node);
    }

    curr->height = calculate(curr);
    int balFactor = getBalance(curr);

    if(balFactor > 1)
    {
        if(strcmp(node->id, curr->left->id) > 0)
        {
            curr->left = leftRotate(curr->left);
        }
            return rightRotate(curr);
    }
    else if(balFactor < -1)
    {
        if(strcmp(node->id, curr->right->id) < 0)
        {
            curr->right = rightRotate(curr->right);
        }
            return leftRotate(curr);
    }
    return curr;
}

void printHeader()
{
    char headID[10] = "ID";
    char headSize[10] = "N";
    char headLength[10] = "Length";
    char headType[10] = "Type";
    char headEmpty[10] = "";

    printf("=================================================\n");
    printf("||%7s||%6s||%6s||%-20s||\n", headID, headSize, headLength, headType);
    printf("||=======||======||======||====================||\n");
}

void printFooter()
{
    printf("=================================================\n");
}

void preOrder(Property * curr)
{
        if(curr == NULL)
    {
        return;
    }
    printf("||%7s||%6d||%6d||%-20s||\n", curr->id, curr->N, curr->length, curr->type);
    preOrder(curr->left);
    preOrder(curr->right);
}

void inOrder(Property * curr)
{
    if(curr == NULL)
    {
        return;
    }
    inOrder(curr->left);
    printf("||%7s||%6d||%6d||%-20s||\n", curr->id, curr->N, curr->length, curr->type);
    inOrder(curr->right);
}

void postOrder(Property * curr)
{
        if(curr == NULL)
    {
        return;
    }
    postOrder(curr->left);
    postOrder(curr->right);
    printf("||%7s||%6d||%6d||%-20s||\n", curr->id, curr->N, curr->length, curr->type);  
}

Property * deleteProperty (Property * curr, char *id)
{
    if(curr == NULL)
    {
        return curr;
    }
    else if(strcmp(id, curr->id) < 0)
    {
        curr->left = deleteProperty(curr->left, id);
    }
    else if(strcmp(id, curr->id) > 0)
    {
        curr->right = deleteProperty(curr->right, id);
    }
    else
    {
        if(curr->right == NULL && curr->left == NULL)
        {
            curr = NULL;
            free(curr);
        }
        else if(curr->left == NULL)
        {
            Property * temp = curr;
            curr = curr->right;
            free(temp);
            temp = NULL;
        }
        else if(curr->right == NULL)
        {
            Property * temp = curr;
            curr = curr->left;
            free(temp);
            temp = NULL;
        }
        else
        {
            Property * iter = curr->left;
            while(iter->right)
            {
                iter = iter->right;
            }

            strcpy(curr->id, iter->id);
            strcpy(curr->type, iter->type);
            curr->length = iter->length;
            curr->N = iter->N;

            curr->left = deleteProperty(curr->left, iter->id);
        }

            if(curr == NULL)
            {
                return curr;
            }
            curr->height = calculate(curr);
            int balFac = getBalance(curr);
            if(balFac > 1)
            {
                if(getBalance(curr->left) < 0)
                {
                    curr->left = leftRotate(curr->left);
                }
                return rightRotate(curr);
            }
            else if(balFac < -1)
            {
                if(getBalance(curr->right) > 0)
                {
                    curr->right = rightRotate(curr->right);
                }
                return leftRotate(curr);
            }
    }
}

Property * searchProperty(Property * curr, char * id)
{
    if(curr == NULL)
    {
        return NULL;
    }
    if(strcmp(curr->id, id) > 0)
    {
        return searchProperty(curr->left, id);
    }
    if(strcmp(curr->id, id) < 0)
    {
        return searchProperty(curr->right, id);
    }
    return curr;
}

Property * deleteAll(Property * curr)
{
        while(curr)
        {
            curr = deleteProperty(curr, curr->id);
        }
        return curr;
}

int main()
{
    Property * root = NULL;
    root = insertProperty(root, createProperty("TX003", 5, 10, "rural"));
    root = insertProperty(root, createProperty("TX002", 9, 7, "capital"));
    root = insertProperty(root, createProperty("TX005", 6, 5, "rural"));
    root = insertProperty(root, createProperty("TX001", 7, 1, "metro"));
    root = insertProperty(root, createProperty("TX004", 4, 3, "metro"));
    root = insertProperty(root, createProperty("TX006", 100, 200, "metro"));

    printf("Before delete: \n");
    printHeader();
    inOrder(root);
    printFooter();
    
    printf("\n");

    root = deleteProperty(root, "TX006");
    printf("After deletion:\n");
    printHeader();
    inOrder(root);
    printFooter();

    printf("\n");

    printf("Delete all:\n");
    root = deleteAll(root);
    inOrder(root);
    printf("Empty\n");

    return 0;
}
