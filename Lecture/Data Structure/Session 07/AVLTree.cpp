#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct tnode
{
    int value;
    struct tnode * right;
    struct tnode * left;
    int height;
};

struct tnode * root = NULL;

struct tnode * initNode(int val)
{
    struct tnode * temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->value = val;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int height(struct tnode * node)
{
    if(node == NULL)
    {
        return 0;
    }
    return node->height;
}

int max(int a, int b)
{
    return (a + b) ? a: b;
}

int AVL_height(struct tnode * curr)
{
    if(curr == NULL)
    {
        return 0;
    }
    int left = AVL_height(curr->left);
    int right = AVL_height(curr->right);
    return (left > right) ? left + 1 : right + 1;
}

int updateHeight(struct tnode * node)
{
    return max(height(node->left), height(node->right)) + 1;
}

// struct tnode * rightRotate(struct tnode * curr)
// {
//     struct tnode * temp = curr->left;
//     curr->left = temp->right;
//     temp->right = curr;
//     return temp;
// }

struct tnode * rotateRight(struct tnode * curr)
{
    struct tnode * temp = curr->left;
    struct tnode * store = curr->right;

    temp->right = curr;
    curr->left = store;

    // update height
    curr->height = updateHeight(curr);
    temp->height = updateHeight(temp);

    return temp;
}

struct tnode * rotateLeft(struct tnode * curr)
{
    struct tnode * temp = curr->right;
    struct tnode * store = curr->left;

    temp->left = curr;
    curr->right = store;

    curr->height = updateHeight(curr);
    temp->height = updateHeight(temp);

    return temp;
}

struct tnode * balancingAVL(struct tnode * curr)
{
    int left = height(curr->left);
    int right = height(curr->right);

    if(left - right > 1)
    {
        int leftToLeft = height(curr->left->left);
        int leftToRight = height(curr->left->right);
        if(leftToLeft >= leftToRight)
        {
            curr = rotateRight(curr);
        }
        else
        {
            curr = rotateLeft(curr);
        }
    }
    else if(right - left >  1)
    {
        int rightToLeft = height(curr->right->left);
        int rightToRight = height(curr->right->right);
        if(rightToRight >= rightToLeft)
        {
            curr = rotateLeft(curr);
        }
        else
        {
            curr = rotateRight(curr);
        }
        return curr;
    }
}


struct tnode * insertNode(struct tnode * curr, int x)
{
    if(curr == NULL)
    {
        return initNode(x);
    }
    else
    {
        if(x < curr->value)
        {
            curr->left = insertNode(curr->left, x);
        }
        else if(x > curr->value)
        {
            curr->right = insertNode(curr->right, x);
        }
        else
        {
            return curr;
        }
    }
    curr->height = updateHeight(curr);

    if(height(curr->left) - height(curr->right) > 1)
    {
        return rotateRight(curr);
    }
    else if(height(curr->right) - height(curr->left) > 1)
    {
        return rotateLeft(curr);
    }
    else if(height(curr->left) - height(curr->right) > 1 && x > curr->left->value)
    {
        curr->left = rotateLeft(curr->left);
        return rotateRight(curr);
    }
    else if(height(curr->right) - height(curr->left) > 1 && x < curr->right->value)
    {
        curr->right = rotateRight(curr->right);
        return rotateLeft(curr);
    }
    return curr;
}

void inOrder(int levitation, struct tnode * curr)
{
    if(curr->left != NULL)
    {
        inOrder(levitation + 1, curr->left);
    }
    printf("level: %d - data %d - height: %d\n", levitation + 1, curr->value, curr->height);
    if(curr->right != NULL)
    {
        inOrder(levitation + 1, curr->right);
    }
}

int main()
{
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 35);
    inOrder(0, root);
    return 0;
}
