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

char * convertToLowerCase(char * words)
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
    }
    return 0;
}

void printTree(struct Tree * curr)
{
    if(curr->left == 0)
    {
        printf("Data not found!\n");
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
        return newNode;
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
        printf("Data not found!\n");
    }
    if(strcmpi(name, curr->words) < 0)
    {
        curr->left = deleteNode(curr->left, name);
    }
    else if(strcmpi(name, curr->words) > 0)
    {
        curr->right = deleteNode(curr->right, name);
    }
    else
    {
        if(curr == NULL)
        {
            return NULL;
        }
        if(curr->left == NULL)
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

struct Tree * insertName(struct Tree * curr)
{
    char name[10];
    int check = 1;
    do
    {
        printf("input your name: ");
        scanf("%s", name); getchar();
        check = validateString(name);
    } while (check);
    curr = insertNode(curr, createNode(name));
    printf("Words added success!\n");

    return curr;
    
}

struct Tree * searchNode(struct Tree *curr, char * name)
{
    if(curr == NULL)
    {
        printf("Data not found!\n");
    }
    if(strcmpi(curr->words, name) < 0)
    {
        return searchNode(curr->left, name);
    }
    else if(strcmpi(curr->words, name) > 0)
    {
        return searchNode(curr->right, name);
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
        printf("Enter name to be searched: ");
        scanf("%s", name); getchar();
        check = validateString(name);
        if(check)
        {
            printf("Invalid search format!\n");
        }
    } while (check);

    if(searchNode(curr, name))
    {
        curr = deleteNode(curr, name);
        printf("Deleted\n");
    }
    else
    {
        printf("Data not found!\n");
    }
    return curr;
}

void menu(struct Tree * root)
{
    int ch = 0;
    do
    {
        system("cls");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Delete Node\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                root = insertName(root);
                break;
            }
            case 2:
            {
                root = deleteName(root);
                break;
            }
            case 3:
            {
                printTree(root);
                break;
            }
            case 4:
            {
                printf("Thanks\n");
                break;
            }
        }
    } while (ch != 4);
    
}

int main()
{
    struct Tree *root;
    menu(root);
    return 0;
}