#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food
{
    int id;
    char name[105];
    int price;
    int height;
    Food *left, *right;
};

Food * createFood(int id, char * name, int price)
{
    Food *food = (Food*) malloc (sizeof(Food));
    food->id = id;
    strcpy(food->name, name);
    food->price = price;
    food->height = 1;
    food->left = food->right = NULL;

    return food;
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

int getHeight(Food * curr)
{
    if(curr == NULL)
    {
        return 0;
    }
    return curr->height;
}

int getBalanceFactor(Food * curr)
{
    if(curr == NULL)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

int calculateHeight(Food * curr)
{
    return getMax(getHeight(curr->left), getHeight(curr->right)) + 1;
}

Food * rightRotate(Food * curr)
{
    Food * cL = curr->left;
    Food * cLR = curr->right;

    cL->right = curr;
    curr->left = cLR;

    curr->height = calculateHeight(curr);
    cL->height = calculateHeight(cL);

    return cL;
}

Food * leftRotate(Food * curr)
{
    Food * cR = curr->right;
    Food * cRL = cR->left;
    
    cR->left = curr;
    curr->right = cRL;

    curr->height = calculateHeight(curr);
    cR->height = calculateHeight(cR);

    return cR;
}


Food * insertFood(Food * curr, int id, char * name, int price)
{
    if(curr == NULL)
    {
        return createFood(id, name, price);
    }
    else if(id < curr->id)
    {
        curr->left = insertFood(curr->left, id, name, price);
    }
    else if(id > curr->id)
    {
        curr->right = insertFood(curr->right, id, name, price);
    }
    curr->height = calculateHeight(curr);

    return curr;
}

Food *deleteFood(Food *curr, int id) 
{
    if(!curr) 
    {
        return NULL;
    }
    else if(id < curr->id) 
    {
        curr->left = deleteFood(curr->left, id);
    }
    else if(id > curr->id) 
    {
        curr->right = deleteFood(curr->right, id);
    }
    else 
    {
        if(!curr->left && !curr->right) 
        {
            free(curr);
            curr = NULL;
        }
        else if(!curr->left) 
        {
            Food *temp = curr->right;
            free(curr);
            curr = temp;
        }
        else if(!curr->right) 
        {
            Food *temp = curr->left;
            free(curr);
            curr = temp;
        }
        else 
        {
            Food *temp = curr->right;

            while(temp->left) 
            {
                temp = temp->left;
            }

            curr->id = temp->id;
            strcpy(curr->name, temp->name);
            curr->price = temp->price;
            curr->right = deleteFood(curr->right, temp->id);
        }
    }

    return curr;
}

void preOrder(Food * curr)
{
    if(curr == NULL)
    {
        return;
    }
    printf("%-3d, %-50s, %-6d, (%d)\n", curr->id, curr->name, curr->price, curr->height);
    preOrder(curr->left);
    preOrder(curr->right);
}

void inOrder(Food * curr)
{
    if(curr == NULL)
    {
        return;
    }
    inOrder(curr->left);
    printf("%-3d %-50s %-6d (%d)\n", curr->id, curr->name, curr->price, curr->height);
    inOrder(curr->right);
}

int main()
{
    Food * root = NULL;
    root = insertFood(root, 10, "Nasi Goreng", 15000);
    root = insertFood(root, 5, "Sate Padang", 25000);
    root = insertFood(root, 15, "Sate Taichan", 30000);
    root = insertFood(root, 20, "Rendang", 10000);
    root = insertFood(root, 3, "Nasi Uduk", 8000);

    inOrder(root);

    return 0;
}
