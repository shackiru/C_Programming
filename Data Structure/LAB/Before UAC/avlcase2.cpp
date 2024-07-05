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

int countID = 0;
int numOfGame = 0;

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
    Game * newChild = newNode->left;

    newNode->left = node;
    node->right = newChild;

    node->height = calculate(node);
    newNode->height = calculate(newNode);

    return newNode;
}

Game * rightRotate(Game * node)
{
    Game * newNode = node->left;
    Game * newChild = newNode->right;

    newNode->right = node;
    node->left = newChild;

    node->height = calculate(node);
    newNode->height = calculate(newNode);

    return newNode;
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
    int balance = getBalance(node);

    if(balance > 1)
    {
        // if(strcmp(temp->title, node->left->title) > 0)
        // {
        //     node->left = leftRotate(node->left);
        // }
        if(getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }
    else if(balance < -1)
    {
        // if(strcmp(temp->title, node->right->title) < 0)
        // {
        //     node->right = rightRotate(node->right);
        // }
        if(getBalance(node->right) > 0)
        {
             node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }

    return node;
}

Game * predecessor (Game * iter)
{
    Game * curr = iter->left;
    while(curr->right)
    {
        curr = iter->right;
    }
    return curr;
}

Game * deleteGame(Game * node, char * title)
{
    if(node == NULL)
    {
        return NULL;
    }
    else if(strcmp(title, node->title) < 0)
    {
        node->left = deleteGame(node->left, title);
    }
    else if(strcmp(title, node->title) > 0)
    {
        node->right = deleteGame(node->right, title);
    }
    else
    {
        Game * newNode = (node->left) ? node->left : node->right;
        if(newNode == NULL)
        {
            free(node);
            node = NULL;
        }
        else if(node->left || node->right)
        {
            free(node);
            *node = *newNode;
        }
        else
        {
            newNode = predecessor(node);
            strcpy(node->title, newNode->title);
            strcpy(node->genre, newNode->genre);
            node->stock = newNode->stock;

            node->left = deleteGame(node->left, newNode->title);
        }
    }
        node->height = calculate(node);
    int balance = getBalance(node);

    if(balance > 1)
    {
        // if(strcmp(temp->title, node->left->title) > 0)
        // {
        //     node->left = leftRotate(node->left);
        // }
        if(getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }
    else if(balance < -1)
    {
        // if(strcmp(temp->title, node->right->title) < 0)
        // {
        //     node->right = rightRotate(node->right);
        // }
        if(getBalance(node->right) > 0)
        {
             node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

void inOrder(Game * node)
{
    if(node == NULL)
    {
        return;
    }
    inOrder(node->left);
    printf("%s, %s, %d | height: %d, balance factor: %d\n", node->title, node->genre, node->stock, node->height, getBalance(node));
    inOrder(node->right);
}

Game * dummyData(Game * node)
{
    node = insertGame(node, createGame("Stardew Valley", "Farming", 9));
    node = insertGame(node, createGame("Genshin Impact", "Fantasy", 15));
    node = insertGame(node, createGame("Valorant", "FPS", 3));

    return node;
}

Game * searchGame(Game * node, char * title)
{   
    if(node == NULL)
    {
        return NULL;
    }
    else if(strcmp(title, node->title) < 0)
    {
        node->left = searchGame(node->left, title);
    }
    else if(strcmp(title, node->title) > 0)
    {
        node->right = searchGame(node->right, title);
    }
    return node;
}

Game * insertMenu(Game * node)
{
    char title[105];
    char genre[105];
    int stock;
    do
    {
        printf("Insert Title[5 - 25 chars | unique:]");
        scanf("%[^\n]", title); 
        getchar();
    } 
    while (strlen(title) < 5 || strlen(title) > 25 || searchGame(node, title) != NULL);

    do
    {
        printf("Insert Genre[Action || Adventure || RPG || Card Game]: ");
        scanf("%[^\n]", genre);
        getchar();
    } 
    while (
        strcmp(genre, "Action") &&
        strcmp(genre, "Adventure") &&
        strcmp(genre, "RPG") &&
        strcmp(genre, "Card Game")
    );

    do
    {
        printf("Insert Stock[>1]: ");
        scanf("%d", &stock);
        getchar();
    } 
    while (stock < 1);
    

    // kalau diminta id
    // int countID = 0;
    // char gameID[105];
    // countID = countID + 1;
    // sprintf(gameID, "GA%03d", countID);

    node = insertGame(node, createGame(title, genre, stock));
    printf("Successfully Insert");
    numOfGame++;
    getchar();
    
    return node;
}

Game * updateMenu(Game * node)
{
    char title[105];

        printf("Insert game to delete: ");
        scanf("%[^\n]", title);
        getchar();
    
    Game * toDelete = searchGame(node, title);
    if(toDelete == NULL)
    {
        printf("Not found\n");
        return node;   
    }

    char opt[100];
    do
    {
        printf("Add or Remove");
        scanf("%[^\n]", opt);
        getchar();
    } 
    while (strcmpi(opt, "add")&& strcmpi(opt, "remove"));

    int toRemove = 0;
    do
    {
        printf("Input Stock: ");
        scanf("%d", &toRemove);
        getchar();
    } 
    while ((strcmpi(opt, "remove") == 0 && (toRemove < 1 || toRemove > toDelete->stock)) || (strcmpi(opt, "add") == 0 && toRemove < 1));
    
    
}

void viewMenu(Game * node)
{
    if(numOfGame <= 0)
    {
        printf("No Game!\n");
    }
    else
    {
        inOrder(node);
    }
    printf("Press [ENTER] to continue...");
    getchar();
}

Game * mainMenu(Game * node)
{
    int sel = 0;
    do
    {
        scanf("%d", &sel); 
        getchar();
        switch (sel)
        {
            case 1:
            {
                insertMenu(node);
                break;
            }

            case 2:
            {
                viewMenu(node);
                break;
            }
            
            default:
            {
                printf("Please select the right selection!");
                break;
            }
        }
    } while (sel != 4);
    
}

int main()
{
    Game * node = NULL;
    node = dummyData(node);
    inOrder(node);

    // node = deleteGame(node, "Stardew Valley");
    // inOrder(node);

    return 0;
}
