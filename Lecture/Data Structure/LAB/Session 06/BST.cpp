#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Food
{
    char name[100];
    int price;
    struct Food *right;
    struct Food *left;
};

struct Food *createFood(const char *name, int price)
{
    struct Food *newFood = (Food*) malloc (sizeof(Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->left = newFood->right = NULL;
    return newFood;
}

struct Food *insertFood(struct Food *parent, struct Food *newFood)
{
    // if there is no parent, so the new data will become the parent
    if(parent == NULL)
    {
        return newFood;
    }
    if(strcmp(newFood->name, parent->name) < 0)
    {
        parent->left = insertFood(parent->left, newFood);
    }
    else if(strcmp(newFood->name, parent->name) > 0)
    {
        parent->right = insertFood(parent->right, newFood);
    }
    return parent;
}

//pre order, in order, post order = pre (awal), in(tengah), post (akhir)
void preOrder(struct Food *curr)
{
    if(curr == NULL)
    {
        return;
    }
    printf("%s - %d\n", curr->name, curr->price);
    preOrder(curr->left);
    preOrder(curr->right);

	return;
}

void inOrder(struct Food *curr)
{
    if(curr == NULL)
    {
        return;
    }
    inOrder(curr->left);
    printf("%s - %d\n", curr->name, curr->price);
    inOrder(curr->right);
    return;
}

void postOrder(struct Food *curr)
{
    if(curr == NULL)
    {
        return;
    }
    postOrder(curr->left);
    postOrder(curr->right);
    printf("%s - %d\n", curr->name, curr->price);

    return;
}

struct Food *findPredecessor(struct Food *parent)
{
    struct Food* predecessor = parent->left;
    while(predecessor && predecessor->right)
    {
        predecessor = predecessor->right;
    }
    return predecessor;
}
struct Food *findSuccessor(struct Food *parent)
{
    struct Food *successor = parent->right;
    while(successor && successor->left)
    {
        successor = successor->left;
    }
    return successor;
}

struct Food* deleteFood(struct Food *parent, const char *name)
{
    if(parent == NULL)
    {
        return NULL;
    }
    else if(strcmp(name, parent->name) < 0)
    {
        parent->left = deleteFood(parent->left, name);
    }
    else if(strcmp(name, parent->name) > 0)
    {
        parent->right = deleteFood(parent->right, name);
    }
    else
    {
        if(parent->left == NULL && parent->right == NULL)
        {
            free(parent);
            parent = NULL;
        }
        else if(parent->left == NULL)
        {
            struct Food *newParent = parent->right;
            strcpy(parent->name, newParent->name);
            parent->price = newParent->price;
            parent->right = deleteFood(parent->right, newParent->name);
        }
        else if(parent->right == NULL)
        {
            struct Food *newParent = parent->left;
            strcpy(parent->name, newParent->name);
            parent->price = newParent->price;
            parent->left = deleteFood(parent->left, newParent->name);
        }
        else
        {
            struct Food *newParent = findSuccessor(parent);
            strcpy(parent->name, newParent->name);
            parent->price = newParent->price;
            parent->right = deleteFood(parent->right, newParent->name);
            
            //predecessor
            /*struct Food *newParent = findPredecessor(parent);
            strcpy(parent->name, newParent->name);
            parent->price = newParent->price;
            parent->left = deleteFood(parent->left, newParent-> name);*/
        }
    }
    return parent;
}

struct Food *deleteAllFood(struct Food *curr)
{
    while(curr)
    {
        curr = deleteFood(curr, curr->name);
    }
    return curr;
}

struct Food *searchFood(struct Food *curr, const char *name)
{
    if(curr == NULL)
    {
        return NULL;
    }
    if(strcmp(name, curr->name) < 0)
    {
        return searchFood(curr->left, name);
    }
    else if(strcmp(name, curr->name) > 0)
    {
        return searchFood(curr->right, name);
    }
    else
    {
        return curr;
    }
    return NULL;
}
struct Food *updateFood(struct Food *curr, const char *name, int newPrice)
{
    if(curr ==NULL )
    {
        return NULL;
    }
    else if(strcmp(name, curr->name) < 0)
    {
        curr->left = updateFood(curr->left, name, newPrice);
    }
    else if(strcmp(name, curr->name) > 0)
    {
        curr->right = updateFood(curr->right, name, newPrice);
    }
    else
    {
        curr->price = newPrice;
    }
    return curr;
}

int calculateHeight(struct Food *curr)
{
    if(curr == NULL)
    {
        return 0;
    }
    else
    {
        int leftChildHeight = calculateHeight(curr->left) + 1;
        int rightChildHeight = calculateHeight(curr->right) + 1;
        if(leftChildHeight >= rightChildHeight)
        {
            return leftChildHeight;
        }
        else
        {
            return rightChildHeight;
        }
    }
    return 0;
}

int main()
{
    struct Food *root = NULL;
    struct Food *newFood;

    root = insertFood(root, createFood("Sate Padang", 34000));
    root = insertFood(root, createFood("Sate Ayam", 28000));
    root = insertFood(root, createFood("Telur Bebek", 29000));
    root = insertFood(root, createFood("Ayam Goreng", 28000));
    root = insertFood(root, createFood("Bakso Sapi", 28000));
    
    printf("Pre Order\n");
    preOrder(root);
    printf("\n");

    //root = deleteFood(root, "Sate Padang");
    printf("In Order\n");
    inOrder(root);
    printf("\n");

    printf("Post Order\n");
    postOrder(root);
    printf("\n");


    printf("Search Food: ");
    struct Food *toSearch = searchFood(root, "Bakso Sapi");
    if(toSearch == NULL)
    {
        printf("Data Not Found!\n");
    }
    else
    {
        printf("%s - %d\n", toSearch->name, toSearch->price);
    }
    printf("\n");

    printf("Height: %d\n", calculateHeight(root));
    return 0;
}
