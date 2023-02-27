#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Tree
{
    char words[10];
    struct Tree * left;
    struct Tree * right;
};

char * checkIsLower(char * words)
{
    for(int i = 0; i < strlen(words); i++)
    {
        if(isupper(words[i]))
        {
            words[i] = tolower(words[i]);
        }
    }
    return words;
}

struct Tree * createNode(char * words)
{
    struct Tree * temp = (struct Tree *) malloc (sizeof(struct Tree));
    temp->left = temp->right = NULL;
    return temp;
}

int validateString(char * words)
{
    if(strlen(words) != 8)
    {
        return 1;
    }
    for(int i = 0; i < strlen(words); i++)
    {
        if(isalpha(words[i]) == 0)
        {
            return 1;
        }
        return 0;
    }
}

void printTree(struct Tree * curr)
{
    if(curr->left == 0)
    {
        printf("data not found!\n");
    }
    if(curr->left)
    {
        printTree(curr->left);
    }
    printf("%s\n", curr->words);
    if(curr->right)
    {
        printTree(curr->right);
    }
}

struct Tree * insertNode(struct Tree * newNode, struct Tree * curr)
{
    if(curr == NULL)
    {
        return curr;
    }
    if(strcmpi(newNode->words, curr->words) < 0)
    {
        curr->left = insertNode(curr->left, newNode);
    }
    else if(strcmpi(newNode->words, curr->words) > 0)
    {
        curr->right = insertNode(curr->right, newNode);
    }
    return curr;
}

struct Tree * deleteNode(struct Tree * curr, char * name)
{
    if(curr == NULL)
    {
        printf("data not found!\n");
    }
    if(strcmpi(curr->words, name) < 0)
    {
        curr->left = deleteNode(curr->left, name);
    }
    else if(strcmpi(curr->words, name) > 0)
    {
        curr->right = deleteNode(curr->right, name);
    }
    else
    {
        if(curr == NULL)
        {
            return NULL;
        }
        else if(curr->left == NULL)
        {
            struct Tree * iter = curr->right;
            strcpy(curr->words, iter->words);
            curr->right = deleteNode(curr->right, iter->words);
        }
        else if(curr->right == NULL)
        {
            struct Tree * iter = curr->left;
            strcpy(curr->words, iter->words);
            curr->left = deleteNode(curr->left, iter->words);
        }
        else
        {
            struct Tree *iter = curr->left;
            while(iter->right)
            {
                iter = iter->right;
            }
            strcpy(curr->words, iter->words);
            curr->left = deleteNode(curr->left, iter->words);
        }
    }
    return curr;
}

struct Tree * newName(struct Tree * curr)
{
    char name[10];
    int check = 1;
    do
    {
        printf("Enter  your name: ");
        scanf("%s", name);
        check = validateString(name);
    } while (check);
    curr = insertNode(curr, createNode(name));
    printf("success");
    return curr;
}

struct Tree * searchName(struct Tree * curr, char * name)
{
    if(curr == NULL)
    {
        printf("no data!");
    }
    if(strcmpi(curr->words, name) < 0)
    {
        return searchName(curr->left, name);
    }
    else if(strcmpi(curr->words, name) > 0)
    {
        return searchName(curr->right, name);
    }
    else
    {
        return curr;
    }
    return NULL;
}

struct Tree * deleteName(struct Tree * curr)
{
    char name[10];
    int check = 1;
    do
    {
        printf("Enter your name: ");
        scanf("%s", name);
        check = validateString(name);
    } while (check);
    if(searchName(curr, name))
    {
        curr = deleteNode(curr, name);
        printf("delete success\n");
    }
    else
    {
        printf("there is no data");
    }
}

struct Tree * updateName(struct Tree * curr, char * name)
{
    if(curr == NULL)
    {
        return NULL;
    }
    if(strcmpi(name, curr->words) < 0)
    {
        curr->left = updateName(curr->left, name);
    }
    else if(strcmpi(name, curr->words) > 0)
    {
        curr->right = updateName(curr->right, name);
    }
    return curr;
}

int calculateTree(struct Tree * curr)
{
    if(curr == NULL)
    {
        printf("no data\n");
    }
    int leftChild = calculateTree(curr->left) + 1;
    int rightChild = calculateTree(curr->right) + 1;
    if(leftChild >= rightChild)
    {
        return leftChild;
    }
    else
    {
        return rightChild;
    }
    return 0;
}

void menu(struct Tree * root)
{
    
}

int main()
{
    return 0;
}