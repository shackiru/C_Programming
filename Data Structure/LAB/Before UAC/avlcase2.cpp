#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Game
{
    char title[100];
    char genre[100];
    int stock;

    int height;
    Game *left, *right;
};

Game *createGame(char * title, char * genre, int stock)
{
    Game * newNode = (Game *) malloc (sizeof(Game));
    strcpy(newNode->title, title);
    strcpy(newNode->genre, genre);
    newNode->stock = stock;

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
    return b;
}

int getHeight(Game * node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->height;
}


int calculate(Game * node)
{   
    if(node == NULL)
    {
        return 0;
    }
    return getMax(getHeight(node->left), getHeight(node->right)) + 1;

}


int getBalance(Game * node)
{
    if(node == NULL)
    {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

Game * leftRotate(Game * node)
{
    Game * newNode = node->right;
    node->right = newNode->left;
}

Game * rightRotate()
{

}

Game * insertGame(Game * node, Game * temp)
{
    if(node == NULL)
    {
        return temp;
    }
    else if(strcmp(temp->title, node->title) < 0)
    {
        node->left = insertGame(node->left, temp->left);
    }
    else if(strcmp(temp->title, node->title) > 0)
    {
        node->right = insertGame(node->right, temp->right);
    }

    node->height = calculate(node);

    return node;
}

int main()
{
    return 0;
}
