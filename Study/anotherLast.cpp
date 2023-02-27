#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Tree
{
    char words[10];
    struct Tree * left;
    struct Tree * right;
};

struct Tree * createNode(char * name)
{
    struct Tree * temp = (struct Tree *) malloc (sizeof(struct Tree));
    temp->left = temp->right = NULL;
    return temp;
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
        printf("data not found\n");
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
            curr->left = deleteNode(curr->right, iter->words);
        }
        else
        {
            struct Tree * iter = curr->left;
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

int main()
{
    struct Tree * root = NULL;
    return 0;
}