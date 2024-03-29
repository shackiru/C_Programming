#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVL -> self balancing BST

struct Food
{
    char name[100];
    int price;
    Food *leftChild, *rightChild;
    int height;
};

Food * createFood(const char *name, int price)
{
    Food *newFood = (Food*) malloc (sizeof(Food));
    strcpy(newFood->name, name);
    newFood->price = price;
    newFood->height = 1;
    newFood->leftChild = newFood->rightChild = NULL;

    return newFood;
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

//bandingin anak kiri dan kanan gedean mana
//ambil yang lebih besar
//ditambah 1
int getHeight(Food * node)
{
    if(node == NULL)
    {
        return 0;
    }
    int leftChildHeight = getHeight(node->leftChild);
    int rightChildHeight = getHeight(node->rightChild);

    return getMax(leftChildHeight, rightChildHeight) + 1;
}

int getBalance(Food * node)
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

Food * rightRotate(Food * node)
{
    Food * newParent = node->leftChild;
    node->leftChild = newParent->rightChild;

    newParent->rightChild = node;
    
    //update Height
    node->height = getHeight(node);
    newParent->height = getHeight(newParent);

    return newParent;
}   

Food * leftRotate(Food * node)
{
    Food * newParent = node->rightChild;
    node->rightChild = newParent->leftChild;

    newParent->leftChild = node;

    //update Height
    node->height = getHeight(node);
    newParent->height = getHeight(newParent);

    return newParent;
}

Food * insertFood(Food * root, const char *name, int price)
{
    //kalau rootnya tidak ada (root == NULL)
    if(root == NULL)
    {
        return createFood(name, price);
    }
    //kalau rootnya ada dan data yang ma dimasukkan lebih kecil
    else if(price < root->price)
    {
        root->leftChild = insertFood(root->leftChild, name, price);
    }
    //kalau rootnya ada dan data yang ma dimasukkan lebih besars
    else if(price > root->price)
    {
        root->rightChild = insertFood(root->rightChild, name, price);
    }

    //setiap ada data baru yang nambah, heightnya harus diupdate
    root->height = getHeight(root);

    //cek apakah perlu dirotate (balance factor tidak sesuai aturan)
    //balance < 01 atau balance > 1
    int balance = getBalance(root);

    //berat ke kiri (balance > 1)
    if(balance > 1)
    {
        // kalau price > root->price (bakal ditaro ke kanan)
        if(price > root->price)
        {
            //left rotate dulu
            root->leftChild = leftRotate(root->leftChild);

        }
        //kalau price < root->price
        // right rotate
        return rightRotate(root);
    }
    // berat ke kanan (balance < -1)
    else if(balance < -1)
    {
        if(price < root->price)
        {
            //right rotate dulu
            root->rightChild = rightRotate(root->rightChild);
        }
        //kalau price > root-price
        //left rotate
        return leftRotate(root);
    }

    return root;
}

Food * updateFood(Food * root, const char * newName, int price)
{
    if(root == NULL)
    {
        //datanya tidak ketemu
        printf("Data not found!\n");
        return root;
    }
    // kalau data yang dicari lebih kecil
    else if(price < root->price)
    {
        root->leftChild = updateFood(root->leftChild, newName, price);
    }
    //kalau data yang dicari lebih besar
    else if(price > root->price)
    {
        root->rightChild = updateFood(root->rightChild, newName, price);
    }
    //kalau data udah ketemu
    else
    {
        strcpy(root->name, newName);
        printf("Successfully updated!\n");
    }
    return root;
}

void inOrder(Food * node)
{
    if(node == NULL)
    {
        return;
    }
    inOrder(node->leftChild);
    printf("name: %s\t | \tprice: %d \t| height: %d \t| balance: %d \n", node->name, node->price, node->height, getBalance(node));
    inOrder(node->rightChild);

    return;
}

//preorder -> awal, postorder -> akhir, inorder -> tengah

int main()
{
    Food * root = insertFood(NULL, "hamburger", 20000);
    root = insertFood(root, "hot-dog", 15000);
    root = insertFood(root, "kebab", 12000);
    root = insertFood(root, "ubi ball", 10000);
    root = insertFood(root, "beng beng", 8000);

    inOrder(root);

    root = updateFood(root, "makanan", 20000);
    printf("\nAfter update: \n");
    inOrder(root);

    return 0;
}
