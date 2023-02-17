#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct pakFikri
{
    char name[8];
    struct pakFikri *left;
    struct pakFikri *right;
};

pakFikri *root = NULL;

struct pakFikri *createName(const char *name)
{
    struct pakFikri *newName = (pakFikri*) malloc(sizeof(pakFikri));
    strcpy(newName->name, name);
    newName->left = newName->right = NULL;
    return newName;
}

struct pakFikri *insertName(struct pakFikri *parent, struct pakFikri *newName)
{
    if(parent == NULL)
    {
        return newName;
    }
    else if(strcmp(newName->name, parent->name) < 0)
    {
        parent->left = insertName(parent->left, newName);
    }
    else if(strcmp(newName->name, parent->name) > 0)
    {
        parent->right = insertName(parent->right, newName);
    }
    return parent;
}

struct pakFikri * deleteName(struct pakFikri *curr, const char *name)
{
    struct pakFikri *temp;
    if(curr == NULL)
    {
        printf("Data not found...\nQ");
        return NULL;
    }
    if(strcmp(name, curr->name) < 0)
    {
        curr->left = deleteName(curr->left, name);
    }
    else if(strcmp(name, curr->name) > 0)
    {
        curr->right = deleteName(curr->right, name);
    }
    else
    {
        if(curr->left == NULL && curr->right == NULL)
        {
            free(curr);
            curr = NULL;
        }
        else if(curr->left == NULL)
        {
            temp = curr->right;
            strcpy(root->name, name);
            curr->right = deleteName(curr->right, curr->name);
        }
        else if(curr->right == NULL)
        {
            temp = curr->left;
            strcpy(root->name, name);
            curr->left = deleteName(curr->left, curr->name);
        }
    }
    return curr;    
}

void addName()
{
    char name[8];
    do
    {
        printf("Input your name [0 - 8 characters]: ");
        scanf("%s", name);
        getchar();
    } 
    while (strlen(name) < 0 || strlen(name) > 8);
    root = insertName(root, createName(name));
}

void delName()
{
    char name[8];
    do
    {
        printf("Enter name [0 - 8 characters]: ");
        scanf("%s", name);

    } 
    while (strlen(name) < 0 || strlen(name) > 8);
    root = deleteName(root, name);
}

void inOrder(struct pakFikri *curr)
{
    if(curr == NULL)
    {
        return;
    }
    inOrder(curr->left);
    printf("%s\n", curr->name);
    inOrder(curr->right);
    return;
}

void displayMenu()
{
    int sel = 0;
    do
    {
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Display InOrder\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &sel);

        switch(sel)
        {
            case 1:
            {
                addName();
                break;
            }
            case 2:
            {
                delName();
                break;
            }
            case 3:
            {
                inOrder(root);
                break;
            }
        }
    } 
    while (true);
    
}

int main()
{
    root = insertName(root, createName("fiikkrii"));
    root = insertName(root, createName("hassanii"));
    displayMenu();
    return 0;
}